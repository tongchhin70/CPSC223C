// Author: Tong Chhin
// Author email: tongchhin@csu.fullerton.edu
// Program name: Tokenizer Program
// Programming languages: Three files in C language and one file in Bash.
// Date program began: 2025-Mar-2
// Date last updated: 2025-Mar-13
// Program purpose: This program reads text data from a file into a dynamically allocated array,
// prompts the user for separator characters, tokenizes the input text into substrings (tokens)
// based on those separators, and clearly displays each token along with the total token count.


//============= Begin source code ===============
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "file2string2.h"
#define MAX_CHAR_SIZE 256
#define MAX_TOKEN 100

char* whitespaceremover(char* str){
    while (isspace((unsigned char)*str)) {
        str++;  // Advance pointer until non-whitespace char
    }
    return str; // Return new position clearly
}

int tokenize(char *str, const char *separators, char Token_arr[MAX_TOKEN][MAX_CHAR_SIZE]) {
    int count = 0; // Init count

    printf("Confirmation: These are the separators =>%s\n", separators); // Outputs the seperator
    printf("Here is the complete list of tokens:\n");

    str = whitespaceremover(str); //Removes any whitespaces at the front the string

    char *token = strtok(str, separators); // Starts the first Token

    while (token!=NULL){

        token = whitespaceremover(token);// Token Does not have a trailing whitespace

        strncpy(Token_arr[count], token, MAX_TOKEN - 1); // COPY TOKEN INTO THE INDEX OF I
        Token_arr[count][MAX_TOKEN - 1] = '\0'; // ADDS NULL AFTER TOKEN

        token = strtok(NULL, separators); // Starts token process again
        count++;
    }

    return count;
}

void print_token(char Token_arr[MAX_TOKEN][MAX_CHAR_SIZE], int count){
    for (int i = 0; i < count; i++){
        printf("TOKEN %d: %s\n", i, Token_arr[i]);
    }

    printf("Total Token: %d", count);
}

void print_content(char arr[], int size){
    printf("%d characters were read from the file into an array of the program.\n", size);

    for(int i = 0; i < size; i++){
        printf("%c", arr[i]); //  print char per char
    }
    printf("\n");
}

int main() {
    char filename[MAX_CHAR_SIZE];
    char separators[MAX_CHAR_SIZE];
    char *fileContent = NULL;

    //2D Array
    char token[MAX_TOKEN][MAX_CHAR_SIZE];
    int count;

    while (1) {
        printf("Enter filename: ");
        if (fgets(filename, sizeof(filename), stdin) == NULL) {
            printf("\nExiting Program, Thank you and Goodbye!\n");
            exit(0);
        }
        filename[strcspn(filename, "\n")] = 0; //removes new line by fgets

        fileContent = file2string(filename);

        if (fileContent != NULL) {
            break; // successfully opened file
        } else {
            printf("Invalid file name, please try again.\n");
        }
    }

    int length = strlen(fileContent); // Gets the size
    print_content(fileContent, length); // Calls the print function

    printf("Enter the separator characters which may include white space and press enter: ");
    fgets(separators, sizeof(separators), stdin);
    separators[strcspn(separators, "\n")] = '\0'; // The trailing newline at the end of the input

    count = tokenize(fileContent, separators, token); // Calls the Tokenization Function, stores count

    print_token(token, count);



    free(fileContent);
    printf("\nHave a nice evening.\n\n");
    return 0;
}