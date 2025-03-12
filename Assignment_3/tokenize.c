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
#define MAX_CHAR_SIZE 1024
#define MAX_STRING_LINE 100

void print_array(char *arr[], int n);

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

    FILE* file ; //init file
    char filename[30];//create file name 
    char *string;
    char buffer[MAX_CHAR_SIZE];
    char *stringArray[MAX_STRING_LINE];
    char c;

    printf("\n*NOTE: CASE SENSITIVE AND ADD .txt AT THE END!*");
    printf("\nEnter the name of the text file: ");
    fgets(filename, 30, stdin);
    filename[strcspn(filename, "\n")] = 0; //removes new line by fgets


    file  = fopen(filename, "r");

    if (file  == NULL){
        printf("The file does not exist. The program will now exit.");
        return 1;
    }else {
        printf("The file %s has loaded successfully!", filename);
    }

    int count = 0;
    while (fgets(buffer, MAX_CHAR_SIZE, file) && count < MAX_STRING_LINE) {
        size_t length = strlen(buffer);
        stringArray[count] = malloc(length + 1);

        strcpy(stringArray[count], buffer); // Copy buffer to allocated memory
        count++;
    }

    fclose(file); // Close the file

    printf("\nFile has copied to a one-dimensional array.\n"); // Finished copying the contents
    print_array(stringArray, count);
    
}
    