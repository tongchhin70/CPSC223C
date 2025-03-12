//Author: Tong Chhin
//Author email: tongchhin@csu.fullerton.edu
//Program name: Chemistry Program
//Programming languages: One file in C language and two files in Bash.
//Date program began: 2025-Feb-16
//Date of last update: 2025-Feb-25
//Files in this program: datastring and r.sh.  
//Status: Ready to be submitted

//Purpose of this program:
// Purpose: This program reads a text file, stores its contents in memory, allows the user to search for a string,
// and displays the occurrences of that string within the file.

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

    fseek(fptr, 0, SEEK_END);
    fsize = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    
    string = malloc(sizeof(char) * (fsize + 1)); // Allocate memory for the entire file
    int i = 0;
    
    while ((c = fgetc(fptr)) != EOF) {
        if (c != '\n') {
            string[i] = c; // Store the character
        } else {
            string[i] = ' '; // Replace newline with space
        }
        i++;
    }
    string[i] = '\0'; // Null-terminate the string

    fclose(fptr); // Close the file

    printf("\nFile has copied to a one-dimensional array.\n"); // Finished copying the contents

    // Print 256 characters
    printf("\nFile Contents to max of 256 char and 64 char per line:\n"); 
    for (i = 0; i < MAX_CHAR_SIZE; i++) {
        putchar(string[i]);
        if ((i + 1) % MAX_CHAR_LINE == 0) { // Print 64 characters per row
            printf("\n"); //Once the number hits 64, it will print a newline
        }
    }

    char search[12]; //Init search string to 12 chars

    while (1) { // Creates a while to loop until a condition is met

        int *arraysearch = malloc(sizeof(int)*MAX_SEARCH_RESULTS); //Initizalizing the array to be dynamic
        if (arraysearch == NULL) { //checks if memory is full
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("\n\nEnter a String to Search (Enter 'quit' to close out the program): ");
        fgets(search, 12, stdin);

        if (search[0] == '\0') { 
            printf("User Input Error, Goodbye!\n");
            free(arraysearch);
            break;
        }

        search[strcspn(search, "\n")] = '\0';  // Remove newline character

        if (strlen(search) == 0) { // If user enters nothing, it will ask for them to re-enter seaerch
            printf("Invalid search string. Please enter a valid search term.\n");
            free(arraysearch);
            continue;
        }   

        if (strcmp(search, "quit") == 0){ // Exit Program Condition
            free(arraysearch);
            break;  
        }

        i = 0;
        char *stringptr = string; // Assigns pointer to the string
        while ((stringptr = strstr(stringptr, search)) != NULL) { // Checks if pointer with strstr is not Null
            arraysearch[i] = stringptr - string; //Gets the position
            i++; // Increment
            stringptr += strlen(search); //Moves the pointer past the found string
        }
    
        if (i > 0){ // Checks the index if any position is found
            printf("Substring found at positions: ");
            for (int j = 0; j < i; j++) { //Uses j to increment and print out the indexing of array
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
    printf("\nThanks for using this Program. Comeback Next Time! Goodbye!\n\n\n"); // Displaying a goodbye message

    free(string);

    return 0;
}