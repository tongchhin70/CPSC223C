

//============= Begin source code ===============
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_CHAR_SIZE 256
#define MAX_CHAR_LINE 64

int main(){

    //Gets Current Time
    time_t current_time;
    current_time = time(NULL);
    struct tm *local_time;
    //converts current to local

    time(&current_time);
    local_time = localtime(&current_time);
    // Format the date and time
    char display_time[100];
    strftime(display_time, sizeof(display_time), "%Y %B %d @ %I:%M%p", local_time);

    printf("\nWelcome to Data String brought to by Chief Software Engineer Tong Chhin");
    printf("\nThe time is now: %s\n", display_time);

    FILE* fptr; //init file
    char *filename;//create file name 
    char *string;
    long fsize;
    char c;

    //INTRO
    // printf("\n*NOTE: CASE SENSITIVE AND ADD .txt AT THE END!*");
    // printf("\nEnter the name of the text file: ");
    // fgets(filename, 30, stdin);
    // filename[strcspn(filename, "\n")] = 0; //removes new line by fgets


    // fptr = fopen(filename, "r");

    // if (fptr == NULL){
    //     printf("The file does not exist. The program will now exit.");
    //     exit(0);
    // }else {
    //     printf("The file has loaded successfully!");
    // }

    //TESTCASE
    fptr = fopen("text.txt", "r");
    if (fptr == NULL){
        printf("The file does not exist. The program will now exit.");
        exit(0);
    }else {
        printf("The file has loaded successfully!");
    }


    // Moving pointer to end
    fseek(fptr, 0, SEEK_END);
    // Records the size 
    fsize = ftell(fptr);
    // Moving it back to the start
    fseek(fptr, 0, SEEK_SET); 

    // Printing position of pointer
    printf("\n\nThe file size has %ld chars\n", fsize);

    string = malloc(sizeof(char)*(fsize+1)); // Using Malloc to allocate memory, + 1 to make room for NULL
    int i = 0; // Init an Index

    while ((c = fgetc(fptr)) != EOF) {
        string[i] = c; // Adds a char to into string array
        i++; // Moves the index to the next char
    }

    string[i] = '\0'; // Add NULL to the end of the string array
    fclose(fptr); // Close the file

    free(fptr); // Free up memory

    printf("\nFile has copied to a one-dimensional array.\n"); // Finished copying the contents

    // printf("\nFile Contents:\n\n%s\n", string);

    // Print 256 characters
    printf("\nFile Contents to max of 256 characters:\n");
    i = 0; // Index starting at 0

    while (i != MAX_CHAR_SIZE ){ // Adds a while loop to restrict char to loop 256 times
        if (i % 64 != 0){ // Condition with modulo to add a new line for every 64 char
            printf("%c", string[i]);
            i++; // Increment 
        } else {
            printf("\n"); // New line added
            printf("%c", string[i]);
            i++; // Increment 
        }
    }


    char *search = malloc(sizeof(char)* 12);
    char *result;
    char *stringcopy = string;

    if (search == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    while (1) {

        i = 0;
        int *arraysearch = malloc(sizeof(int)*10);
        char *result;
        char *stringcopy = string;

        printf("\n\nEnter a String to Search (Enter quit to close out the program): ");
        fgets(search, 12, stdin);
        search[strcspn(search, "\n")] = '\0';  // Remove newline character

        if (strcmp(search, "quit") == 0){
            printf("Goodbye!\n");
            break;  // Exit the loop
        }

        while ((result = strstr(stringcopy, search)) != NULL){
            stringcopy = result + strlen(search);
            arraysearch[i] = result - string;
            i++;
        }
    
        if (strstr(string, search) != NULL){
            printf("Substring found at positions: ");
            for (int j = 0; j < i; j++) {
                printf("%d ", arraysearch[j]);
            }
            printf("\n");
        } else {
            printf("Position Not Found!");
    
        }

        //free up memory
        free(arraysearch);
    }

    free(search);

    // printf("Substring found at positions: ");
    // for (int j = 0; j < i; j++) {
    //     printf("%d ", arraysearch[j]);
    // }
    // printf("\n");



    return 0;
}