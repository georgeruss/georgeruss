#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <getopt.h>
#include <string.h>

#define MAX 1024

int fd;
int n;
int counter;
int bytes       = 0;
int byte_total  = 0;
int linecount   = 0;
int line_total  = 0;
int wordcount   = 0;
int word_total  = 0;
FILE* fp        = NULL;
char buffer[MAX];
char* line      = NULL;
char* line2     = NULL;

/**
 * Main function which performs a basic version
 * of the 'wc' function.
 * {@param argc} int argument counter
 * {@param argv} char** argument mapper
 * {@return int}
 */
int main(int argc, char** argv) {

    setbuf(stdout, NULL); // buffer turned off

    if (argc == 1) {
        char ch;
        while (0 == 0) {
            while (read(STDIN_FILENO, &ch, 1) > 0) {
            } // while
        } // while
    } else if (argc >= 2) {
        int x = 1;
        char ch;
        int count_2 = 0;
        int open_args = 0;
        int counterxyz = 0;

        for (int i = 1; i < argc; i++) { // open-able arguments counter
            if (open(argv[i], O_RDONLY) > 0) {
                open_args++;
            } // if
        } // for

        for (int i = 1; i < argc; i++) { // find the postion of the first readable file
            counterxyz++;
            if (open(argv[i], O_RDONLY) > 0) {
                break;
            } // if
        } // for

        while (x < argc && count_2 != 1) {
            linecount = 0;
            wordcount = 0;
            bytes     = 0;

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

            if (argc >= 2) {

                if (line2 == line) {
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

                    while ((n = read(fd, buffer, MAX)) > 0) {  // linecounter
                        for (int i = 0; i < n; i++) {
                            if (buffer[i] == '\n') {
                                linecount++;
                            } // if
                            if (buffer[i] == ' ' || (buffer[i] != ' ' && buffer[i] == '\n')) {
                                wordcount++;
                            } // for
                        } // for
                        wordcount++;
                        bytes = n;
                    } // while

                    for (int i = 1; i < argc; i++) {
                                                          // c = bytes, w = words, l = linecount
                        if (strcmp(argv[i], "-c")  == 0) {
                            // bytes
                            printf(" %d", bytes);
                            printf(" %s\n", line);

                            byte_total += bytes;
                            if (counterxyz - 1 < argc && open_args > 1) {
                                printf(" %d", byte_total);
                                printf(" total\n");
                            } // if
                            x++;
                        } else if (strcmp(argv[i], "-w") == 0) {
                            // words
                            printf(" %d", wordcount);
                            printf(" %s\n", line);
                            word_total += wordcount;
                            if (counterxyz == argc && open_args > 1) {
                                printf(" %d", word_total);
                                printf(" total\n");
                            } // if
                            x++;
                        } else if (strcmp(argv[i], "-l") == 0) {
                            printf(" %d", linecount);
                            printf(" %s\n", line);
                            line_total += linecount;
                            if (counterxyz == argc && open_args > 1) {
                                printf(" %d", line_total);
                                printf(" total\n");
                            } // if
                            x++;
                        } else if (strcmp(argv[i], "-lc") == 0 || strcmp(argv[i], "-cl") == 0) {
                            // bytes and linecount
                            printf(" %d", linecount);
                            printf(" %d", bytes);
                            printf(" %s\n", line);

                            line_total += linecount;
                            byte_total += bytes;

                            if (counterxyz == argc && open_args > 1) {
                                printf(" %d", line_total);
                                printf(" %d", byte_total);
                                printf(" total\n");
                            } // if
                            x++;
                        } else if (strcmp(argv[i], "-lw") == 0 || strcmp(argv[i], "-wl") == 0) {
                            // bytes and linecount
                            printf(" %d", linecount);
                            printf(" %d", wordcount);
                            printf(" %s\n", line);

                            line_total += linecount;
                            word_total += wordcount;

                            if (counterxyz == argc && open_args > 1) {
                                printf(" %d", line_total);
                                printf(" %d", word_total);
                                printf(" total\n");
                            } // if
                            x++;
                        } else if (strcmp(argv[i], "-wc") == 0 || strcmp(argv[i], "-cw") == 0) {
                            // bytes and wordcount
                            printf(" %d", wordcount);
                            printf(" %d", bytes);
                            printf(" %s\n", line);

                            word_total += wordcount;
                            byte_total += linecount;

                            if (counterxyz == argc && open_args > 1) {
                                printf(" %d", word_total);
                                printf(" %d", byte_total);
                                printf(" total\n");
                            } // if
                            x++;
                        } else if (strcmp(argv[i], "-clw") == 0 || strcmp(argv[i], "-lwc") == 0
                        || strcmp(argv[i], "-wlc") == 0 || strcmp(argv[i], "-cwl") == 0
                        || strcmp(argv[i], "-lcw") == 0 || strcmp(argv[i], "-wcl") == 0
                        || strcmp(argv[i], "-cwl") == 0) {

                            printf(" %d", linecount);
                            printf("  %d", wordcount);
                            printf(" %d", bytes);
                            printf(" %s\n", line);
                            line_total += linecount;
                            word_total += wordcount;
                            byte_total += bytes;

                            if (counterxyz == argc && open_args > 1) {
                                printf(" %d", line_total);
                                printf(" %d", word_total);
                                printf(" %d", byte_total);
                                printf(" total\n");
                            } // if
                            x++;
                        } else {
                            printf(" %d", linecount);
                            printf("  %d", wordcount);
                            printf(" %d", bytes);
                            printf(" %s\n", line);
                            line_total += linecount;
                            word_total += wordcount;
                            byte_total += bytes;

                            if (counterxyz == argc && open_args > 1) {
                                printf(" %d", line_total);
                                printf(" %d", word_total);
                                printf(" %d", byte_total);
                                printf(" total\n");
                            } // if
                        } // if
                        break;
                    } // for
                } else if (line2 != line) {
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

                    while ((n = read(fd, buffer, MAX)) > 0) {  // linecounter
                        for (int i = 0; i < n; i++) {
                            if (buffer[i] == '\n') {
                                linecount++;
                            } // if
                            if (buffer[i] == ' ' || (buffer[i] != ' ' && buffer[i] == '\n')) {
                                wordcount++;
                            } // for
                        } // for
                        wordcount++;
                        bytes = n;
                    } // while

                    for (int i = 1; i < argc; i++) {
                        // c = bytes, w = words, l = linecount
                        if (strcmp(argv[i], "-c")  == 0) {
                            // bytes
                            printf(" %d", bytes);
                            printf(" %s\n", line);
                        } else if (strcmp(argv[i], "-w") == 0) {
                            // words
                            printf(" %d", wordcount);
                            printf(" %s\n", line);
                            word_total += wordcount;

                            if (counterxyz == argc && open_args > 1) {
                                printf(" %d", word_total);
                                printf(" total\n");
                            } // if
                        } else if (strcmp(argv[i], "-l") == 0) {
                            printf(" %d", linecount);
                            printf(" %s\n", line);
                            line_total += linecount;

                            if (counterxyz == argc && open_args > 1) {
                                printf(" %d", line_total);
                                printf(" total\n");
                            } // if
                        } else if (strcmp(argv[i], "-lc") == 0 || strcmp(argv[i], "-cl") == 0) {
                            // bytes and linecount
                            printf(" %d", linecount);
                            printf(" %d", bytes);
                            printf(" %s\n", line);
                            line_total += linecount;
                            byte_total += bytes;

                            if (counterxyz == argc && open_args > 1) {
                                printf(" %d", line_total);
                                printf(" %d", byte_total);
                                printf(" total\n");
                            } // if
                        } else if (strcmp(argv[i], "-lw") == 0 || strcmp(argv[i], "-wl") == 0) {
                            // bytes and linecount
                            printf(" %d", linecount);
                            printf(" %d", wordcount);
                            printf(" %s\n", line);
                            line_total += linecount;
                            word_total += wordcount;

                            if (counterxyz == argc && open_args > 1) {
                                printf(" %d", line_total);
                                printf(" %d", word_total);
                                printf(" total\n");
                            } // if
                        } else if (strcmp(argv[i], "-wc") == 0 || strcmp(argv[i], "-cw") == 0) {
                            // bytes and wordcount
                            printf(" %d", wordcount);
                            printf(" %d", bytes);
                            printf(" %s\n", line);
                            word_total += wordcount;
                            byte_total += bytes;

                            if (counterxyz == argc && open_args > 1) {
                                printf(" %d", word_total);
                                printf(" %d", byte_total);
                                printf(" total\n");
                            } // if
                        } else if (strcmp(argv[i], "-clw") == 0 || strcmp(argv[i], "-lwc") == 0
                        || strcmp(argv[i], "-wlc") == 0 || strcmp(argv[i], "-cwl") == 0
                        || strcmp(argv[i], "-lcw") == 0 || strcmp(argv[i], "-wcl") == 0
                        || strcmp(argv[i], "-cwl") == 0) {
                            printf(" %d", linecount);
                            printf("  %d", wordcount);
                            printf(" %d", bytes);
                            printf(" %s\n", line);
                            line_total += linecount;
                            word_total += wordcount;
                            byte_total += bytes;

                            if (counterxyz == argc && open_args > 1) {
                                printf(" %d", line_total);
                                printf(" %d", word_total);
                                printf(" %d", byte_total);
                                printf(" total\n");
                            } // if
                        } else {

                            printf(" %d", linecount);
                            printf("  %d", wordcount);
                            printf(" %d", bytes);
                            printf(" %s\n", line);
                            line_total += linecount;
                            word_total += wordcount;
                            byte_total += bytes;

                            if (counterxyz == argc && open_args > 1) {
                                printf(" %d", line_total);
                                printf(" %d", word_total);
                                printf(" %d", byte_total);
                                printf(" total\n");
                            } // if
                        } // if
                        break;
                    } // if
                } // for

            } else {
                printf(" %d", linecount);
                printf("  %d", wordcount);
                printf(" %d", bytes);
                printf(" %s\n", line);
            } // if
            if (counterxyz == argc) counterxyz++;
            x++;
        } // while
    } // if
    close(fd);
    return EXIT_SUCCESS;
} // main
