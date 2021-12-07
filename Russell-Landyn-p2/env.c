#include <stdlib.h>
#include <stdio.h>

/**
 * Main function which performs a basic version
 * of the 'env' function.
 * {@param argc} int argument counter
 * {@param argv} char** argument location mapper
 * {@param envp} char** environment
 */
int main (int argc, char* argv[], char* envp[]) {

    setbuf(stdout, NULL);

    char* env = getenv("MY_ENV_VAR");

    for (int i = 0; envp[i] != NULL; i++) {
        printf("\n%s", envp[i]);
    } // for
    printf("\n");

    free(env);

    return EXIT_SUCCESS;
} // main
