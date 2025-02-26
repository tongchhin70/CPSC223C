//============= Begin source code ===============
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_CHAR_SIZE 256
#define MAX_CHAR_LINE 64
#define MAX_SEARCH_RESULTS 100

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
    char filename[30];//create file name 
    char *string;
    long fsize;
    char c;

    printf("\n*NOTE: CASE SENSITIVE AND ADD .txt AT THE END!*");
    printf("\nEnter the name of the text file: ");
    fgets(filename, 30, stdin);
    filename[strcspn(filename, "\n")] = 0; //removes new line by fgets


    fptr = fopen(filename, "r");

    if (fptr == NULL){
        printf("The file does not exist. The program will now exit.");
        return 1;
    }else {
        printf("The file %s has loaded successfully!", filename);
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
        if (c != '\n'){
            string[i] = c;
        }
        else{
            string[i] = ' ';
        }
        i++;
    }

    string[i] = '\0';

    fclose(fptr); // Close the file

    printf("\nFile has copied to a one-dimensional array.\n"); // Finished copying the contents

    // Print 256 characters
    printf("\nFile Contents to max of 256 char and 64 char per line:\n"); 
    for (i = 0; i < MAX_CHAR_SIZE; i++) {
        putchar(string[i]);
        if ((i + 1) % MAX_CHAR_LINE == 0) { // Print 40 characters per row
            printf("\n");
        }
    }

    char search[12];

    while (1) {

        int *arraysearch = malloc(sizeof(int)*MAX_SEARCH_RESULTS);
        if (arraysearch == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("\n\nEnter a String to Search (Enter quit to close out the program): ");
        fgets(search, 12, stdin);
        if (search == NULL) {
            printf("User Input Error, Goodbye!\n");
            free(arraysearch);
            break;
        }

        search[strcspn(search, "\n")] = '\0';  // Remove newline character

        if (strlen(search) == 0) {
            printf("Invalid search string. Please enter a valid search term.\n");
            free(arraysearch);
            continue;
        }   

        if (strcmp(search, "quit") == 0){
            free(arraysearch);
            break;  
        }

        i = 0;
        char *stringcopy = string;
        while ((stringcopy = strstr(stringcopy, search)) != NULL) {
            arraysearch[i] = stringcopy - string;
            i++;
            stringcopy += strlen(search); //Moves the pointer past the word
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

    printf("\n\nThe time is now: %s", display_time);
    printf("\nThe number of seconds since the Great Epoch is %lu", current_time);
    printf("\nThanks for using this Program. Comeback Next Time! Goodbye!\n\n\n");

    free(string);

    return 0;
}