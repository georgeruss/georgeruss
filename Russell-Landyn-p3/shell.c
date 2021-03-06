#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <wait.h>

#define MAX 1024
#define delim " \t\r\n\a"

int shell_cd(char **args); // cd function
int shell_exit(char **args); // exit function

int arg_counter = 1;

/**
 * This function reads in input.
 * {@return char*}
 */
char* shell_readline(void) {
    setbuf(stdout, NULL);
    int buffersize = MAX;
    char* buffer = malloc(sizeof(char) * buffersize);
    int position = 0;
    char ch;

    if (!buffer) {
        perror("Allocation error");
        exit(-1);
    }

    while (read(STDIN_FILENO, &ch, 1) > 0) {
        if (ch == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = ch;
        }

        position++;

        if (position >= buffersize) {
            buffersize += MAX;
            free(buffer);
            buffer = realloc(buffer, sizeof(char) * buffersize);
            if (!buffer) {
                perror("Allocation error");
                exit(EXIT_FAILURE);
            } // if
        } // if
    } // while
    free(buffer);
    return buffer;
} // shell_readline

/**
 * This function splits the input.
 * {@param args} char** provides access to user arguments
 * {@return char**}
 */
char** shell_splitline(char* line) {
    setbuf(stdout, NULL);
    int buffersize = MAX;
    int position = 0;
    char** tokens = (char**)malloc(buffersize * sizeof(char*));
    char* token;

    if (!tokens) {
        perror("Allocation error");
        exit(-1);
    } // if

    token = strtok(line, delim);
    while (token != NULL) {

        tokens[position] = token;
        position++;

        if (position >= buffersize) {
            buffersize += MAX;
            tokens = realloc(tokens, buffersize * sizeof(char*));
            if (!tokens) {
                perror("Allocation error");
                exit(0);
            } // if
        } // if
        token = strtok(NULL, delim);
    } // while

    tokens[position] = NULL;
    return tokens;
} // shell_splitline

/**
 * This function launches the shell.
 * {@param args} char** provides access to user arguments
 * {@return int}
 */
int shell_launch(char** args) {
    setbuf(stdout, NULL);
    pid_t pid;

    int in, out;

    for (int i = 0; i < MAX; i++) {
        if (args[i] != NULL) {
            arg_counter++;
            continue;
        } else {

        }
    } // for

    arg_counter++;

    pid = fork();

    if (arg_counter > 1) {
        if (pid == 0) {
            if (!strcmp("pwd", args[0])){
                char buf[MAX];
                printf("%s\n", getcwd(buf, MAX));
                return 1;
            }

            if (!strcmp("EOT", args[0])){
                exit(1);
            }
            for (int i = 1; args[i] != NULL; i++) {
                if (!strcmp("<", args[i])) {        // input character
                    args[i] = NULL;
                    ++i;
                    in = open(args[i], O_RDONLY, 0);
                    dup2(in, STDIN_FILENO);
                    close(in);
                    in = 0;
                    continue;
                } // if
                if (!strcmp(">", args[i])) {
                    args[i] = NULL;
                    ++i;
                    in = creat(args[i], 0644);
                    dup2(out, STDOUT_FILENO);
                    close(out);
                    out = 0;
                    continue;
                } // if
                if (!strcmp(">>", args[i])) { // append
                    args[i] = NULL;
                    ++i;
                    int append = open(args[i], O_CREAT | O_RDWR | O_APPEND, 0644);
                    dup2(append, STDOUT_FILENO);
                    close(append);
                    continue;
                } // if
            } // for
            if (execvp(args[0], args) < 0) {
                perror("Could not execute command.\n");
            } // if
        } else if (pid < 0) {
            perror("shell error");
            return 1;
        } else {
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
            } // if
        }
    } else {
        if (pid == 0) {
            if (execvp(args[0], args) < 0) {
                perror("Could not execute command.\n");
            }
        } else if (pid < 0) {
            perror("shell error");
        } else {
            int status;
            waitpid(pid, &status, 0);
            printf("\b ");
        } // if
    }
    return 1;
} // shell_launch


/**
 * Provides a list of builtin commandss.
 * {@return char}
 */
char *builtin_str[] = {
    "cd",
    "exit"
};

/**
 * Provides access to functions.
 */
int (*builtin_func[]) (char**) = {
    &shell_cd,
    &shell_exit
};

/**
 * This function retunes the amount of buil-in commands.
 * {@return int}
 */
int shell_amount_builtins() {
    return sizeof(builtin_str) / sizeof(char* );
} // shell_amount_builtins

/**
 * This function implements the 'cd' function.
 * {@param args} char** provides access to user arguments
 * {@return int}
 */
int shell_cd(char** args) {
    setbuf(stdout, NULL);
    if (args[1] == NULL) {
        chdir(getenv("HOME"));
    } else {
        if (chdir(args[1]) != 0) {
            perror(args[0]);
        } else {
            chdir(getenv(args[1]));
        }
    }
    return 1;
} // shell_cd

/**
 * This function implements the 'exit' function.
 * {@param args} char** provides access to user arguments
 * {@return int}
 */
int shell_exit(char** args) {
    exit(0);
} // shell_exit

/**
 * This function executes commands.
 * {@param args} char** provides access to user arguments
 * {@return int}
 */
int shell_execute(char** args) {
    if (args[0] == NULL) {
        return 1;
    }
    for (int i = 0; i < shell_amount_builtins(); i++) {
        if (strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        } // if
    } // for
    return shell_launch(args);
} // shell_execute

/**
 * This function loops the shell.
 */
void shell_loop(void) {
    setbuf(stdout, NULL);
    char* line;
    char** args;
    int help;
    chdir(getenv("HOME"));
    do {
        char buf[MAX];
        printf("1730sh:~");
        printf("%s", getcwd(buf, MAX));
        printf("$ ");
        line = shell_readline();
        args = shell_splitline(line);
        help = shell_execute(args);
        free(args);
    } while (help);
} // shell_loop

/**
 * Main Function.
 * {@param int argc} argument counter.
 * {@param char** argv} argument mapper.
 */
int main(int argc, char* argv[]) {
    setbuf(stdout, NULL);
    shell_loop();
    return EXIT_SUCCESS;
} // main
