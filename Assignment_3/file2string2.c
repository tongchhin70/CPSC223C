#include <stdio.h>
#include <stdlib.h>
#include "file2string2.h"

char *file2string(const char *filename) {
    FILE *file = fopen(filename, "r"); // open file
    if (!file) { // Checks if file not open
        return NULL; // Return Null
    }

    fseek(file, 0, SEEK_END); 
    long filesize = ftell(file);
    rewind(file);

    char *content = (char *)malloc(filesize + 1);
    if (!content) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    int c;
    long i = 0;
    while ((c = fgetc(file)) != EOF) { // Loop to scan each character
        content[i++] = (char)c;
    }

    content[i] = '\n'; // Adds EOF
    fclose(file);

    return content;
}