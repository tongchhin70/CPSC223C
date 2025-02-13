#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

    fsize = ftell(fptr);

    // SET POINTER BACK TO THE ORIGINAL POSITION!!!!
    fseek(fptr, 0, SEEK_SET); 

    // Printing position of pointer
    printf("\n\nThe file size is %ld bytes", fsize);

    string = malloc(sizeof(char)*(fsize+1));
    int i = 0;

    while ((c = fgetc(fptr)) != EOF) {
        string[i] = c;
        i++;
    }

    string[i] = '\0';
    fclose(fptr);

    printf("\nFile Contents:\n\n%s\n\n", string);

    
    return 0;
}