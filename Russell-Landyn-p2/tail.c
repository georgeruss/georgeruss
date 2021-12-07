#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX 1024

int fd;
int fd2;
int n;
int n2;
int open_args  = 0;
int counter    = 0;
int linecount  = 0;
FILE* fp       = NULL;
char buffer[MAX];
char* line     = NULL;
char* line2    = NULL;

/**
 * Main function performs a basic verison of the
 * 'tail' function.
 * {@param argc} int argument count
 * {@param argv} char** argument mapping
 * {@returns int}
 */
int main(int argc,char **argv){
    setbuf(stdout, NULL); // buffer turned off

    if (argc == 1) {
        char ch;
        while (0 == 0) {
            while (read(STDIN_FILENO, &ch, 1) > 0) {
                printf("%c", ch);
            } // while
        } // while
    } else if (argc >= 2) {
        int x = 1;
        char ch;
        int count_2;
        int counterxyz = 0;

        for (int i = 1; i < argc; i++) { // open-able arguments counter
            if (open(argv[i], O_RDONLY) > 0) {
                open_args++;
            } // if
        } // for

        for (int i = 1; i < argc; i++) {
            counterxyz++;
            if (open(argv[i], O_RDONLY) > 0) {
                break;
            } // if
        } // for

        while (x < argc && count_2 != 1) { // argument checker
            if (count_2 != 1) {
                for (int i = 1; i < argc; i++) {
                    if (strcmp(argv[i], "-") == 0) {
                        while (read(STDIN_FILENO, &ch, 1) > 0) {
                            printf("%c", ch);
                        } // while
                        count_2++;
                    } // if
                    break;
                } // for
            } // if

            if (argc > 2) {
                if (linecount == 0) {
                    for (int i = 1; i < argc; i++) {
                        if (strcmp (argv[i], "-n") == 0) {
                            if (atoi(argv[i + 1]) > -1) {
                                linecount = (argc == 2) ? 10 : atoi(argv[i + 1]);
                                break;
                            } else {
                                perror("Invalid argument");
                                exit(-1);
                            } // if
                        } // if
                    } // for
                    for (int i = 1; i < argc; i++) {
                        if (strcmp(argv[i], "-c") == 0) {
                            if (atoi(argv[i + 1]) > -1) {
                                linecount = atoi(argv[i + 1]);
                                break;
                            } else {
                                perror("Invalid argument");
                                exit(-1);
                            }
                        } // if
                    } // for
                } // if

                if (linecount < 0) {
                    linecount = 0;
                } // if

                char temp[MAX];

                if (line2 == line && linecount > 0) { // "opened" argument checker
                    for (int i = 1; i < argc; i++) {
                        if (open(argv[i], O_RDONLY) > 0) {
                            line = argv[i];
                            fd = open(line, O_RDONLY);
                            counterxyz++;
                            break;
                        } // if
                    } // for

                    if (counterxyz - 1 < argc && open_args > 1) {
                        printf("==> ");
                        printf("%s", line);
                        printf(" <==\n");
                    } // if

                    while ((n = read(fd, buffer, MAX)) > 0) {
                        int xz = 0;
                        int c = 0;

                        for (int i = n; i > -1; i--) {
                            temp[c] = buffer[i];
                            if (temp[c] == '\n') {
                                xz++;
                                if (xz == linecount) break;
                            } // if
                            c++;
                        } // for

                        if (strcmp(argv[1], "-n") == 0 || strcmp(argv[3], "-n") == 0) {
                            for (int i = c - 1; i > 0; i--) {
                                printf("%c", temp[i]);
                                if (temp[i] == '\n') {
                                    xz--;
                                    if (counter == xz + 1) break;
                                } // if
                            } // for
                        } else if (strcmp(argv[1], "-c") == 0 && strcmp(argv[3], "-n") != 0) {
                            for (int i = linecount; i > 0; i--) {
                                printf("%c", temp[i]);
                            } // if
                        } // if
                    } // while
                    printf("\n");
                    x++;
                }
                if (line2 != line && linecount > 0) { // "opened" argument checker
                    for (int i = 1; i < argc; i++) {
                        if (i == counterxyz) {
                            if (open(argv[i], O_RDONLY) > 0) {
                                line = argv[i];
                                fd = open(line, O_RDONLY);
                                counterxyz++;
                                break;
                            } // if
                        } // if
                    } // for

                    if (open_args > 1 && counterxyz - 1 < argc) {
                        printf("\n==> ");
                        printf("%s", line);
                        printf(" <==\n");
                    } // if

                    while ((n = read(fd, buffer, MAX)) > 0) {
                        int xz = 0;
                        int c = 0;
                        for (int i = n; i > -1; i--) {
                            temp[c] = buffer[i];
                            if (temp[c] == '\n') {
                                xz++;
                                if (xz == linecount) break;
                            } // if
                            c++;
                        } // for

                         if (strcmp(argv[1], "-n") == 0 || strcmp(argv[3], "-n") == 0) {
                            for (int i = c - 1; i > 0; i--) {
                                printf("%c", temp[i]);
                                if (temp[i] == '\n') {
                                    xz--;
                                    if (counter == xz + 1) break;
                                } // if
                            } // for
                        } else if (strcmp(argv[1], "-c") == 0 && strcmp(argv[3], "-n") != 0) {
                            for (int i = linecount; i > 0; i--) {
                                printf("%c", temp[i]);
                            } // if
                         } // if
                         x++;
                    } // while
                    x++;
                } else {
                    for (int i = 1; i < argc; i++) {
                        if (open(argv[i], O_RDONLY) > 0) {
                            line = argv[i];
                            fd = open(line, O_RDONLY);
                            counterxyz++;
                            break;
                        } // if
                    } // for
                    if (open_args > 1 && counterxyz - 1 < argc) {
                        printf("==> ");
                        printf("%s", line);
                        printf(" <==\n");
                    } // if
                    while ((n = read(fd, buffer, MAX)) > 0) {
                        for (int i = 0; i < n; i++) {
                            printf("%c", buffer[i]);
                        } // for
                    } // while
                    printf("\n");
                } // if
            } else {
                if (open(argv[1], O_RDONLY) > 0) {
                    fd = open(argv[1], O_RDONLY);
                    while((n = read(fd, buffer, MAX)) > 0) {
                        for (int i = 0; i < n; i++) {
                            printf("%c", buffer[i]);
                        }
                    }
                } else {
                    perror("bad argument");
                } // if
            } // if
            if (counterxyz == argc) counterxyz++;
            counter = 0;
            x++;
        } // while
    } // if
    close(fd);
    return EXIT_SUCCESS;
} // main
