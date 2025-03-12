//TOng Chhin
//tongchhin@csu.fullerton.edu
//This course: “CPSC 223C”
//This product:  “Midterm test”
//Today’s date:  “March 11, 2025”


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_SENTENCES 100  
#define MAX_LENGTH 1024  

void bubble(char *arr[], int n) {
    char *temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j][0] > arr[j + 1][0]) { 
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print_array(char *arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("[%d]: %s\n", i, arr[i]);
    }
}

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

    printf("\nWelcome to Line Sort brought to by Chief Software Engineer Tong Chhin");
    printf("\nThe time is now: %s\n", display_time);

    FILE* fptr; //init file
    char filename[30];//create file name 
    char buffer[MAX_LENGTH]; 
    char *arrayString[MAX_SENTENCES];
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

    int i = 0;
    
    while ((c = fgetc(fptr)) != EOF && i < MAX_LENGTH - 1) {
        if (c == '\r') {
            continue;
        }
        buffer[i] = c;
        i++;
    }
    buffer[i] = '\0';

    fclose(fptr);


    int count = 0;
    char *token = strtok(buffer, ".");

    while (token != NULL && count < MAX_SENTENCES){
        arrayString[count] = malloc(strlen(token) + 2);
        if (arrayString[count] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        strcpy(arrayString[count], token);
        strcat(arrayString[count], ".");  
        count++;

        token = strtok(NULL, ".");
    }

    printf("\nThe file data were copied to an array of char of size %d rows.\n", count-1);
    print_array(arrayString, count);
    printf("\n\nSorted Array:\n");
    bubble(arrayString, count);
    print_array(arrayString, count);

    return 0;
}