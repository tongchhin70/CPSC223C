#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#define MAXLINE_SIZE 128
#define MAX_STUDENTS 100

void StandingToString(enum class_standing standing) {
    switch (standing) {
        case Freshman:
            printf("Freshman\n");
            break;
        case Sophomore:
            printf("Sophomore\n");
            break;
        case Junior:
            printf("Junior\n");
            break;
        case Senior:
            printf("Senior\n");
            break;
        default:
            printf("Unknown standing\n");
    }
}

int main(){
    char inputTextFile[256];
    char outputBinFile[256];
    FILE *fin  = NULL;  // input file pointer
    FILE *fout = NULL;  // output file pointer
    
    while (1) {
        printf("Enter filename: ");
        // If user presses Ctrl+D or we can't read, exit the program
        if (!fgets(inputTextFile, sizeof(inputTextFile), stdin)) {
            printf("\nExiting Program, Thank you and Goodbye!\n");
            return 0;
        }
        // Remove trailing newline from user input
        inputTextFile[strcspn(inputTextFile, "\n")] = '\0';

        // Try opening the input file in read mode
        fin = fopen(inputTextFile, "r");
        if (!fin) {
            printf("Invalid file name '%s'. Please try again.\n", inputTextFile);
            continue;  // Go back and prompt again
        }

        // Build the output filename by replacing extension with .bin
        // 1) Copy the input filename into outputBinFile
        strcpy(outputBinFile, inputTextFile);

        // 2) Find the last '.' in outputBinFile (if any) and truncate
        char *dot = strrchr(outputBinFile, '.');
        if (dot) {
            *dot = '\0';  // remove extension
        }
        // 3) Append ".bin"
        strcat(outputBinFile, ".bin");

        // Try opening the output file in write-binary mode
        fout = fopen(outputBinFile, "wb");
        if (!fout) {
            // If we fail to open output, close the input file
            fclose(fin);
            fin = NULL;
            printf("Could not open output file '%s'. Please try again.\n", outputBinFile);
            continue;
        }

        // If we reach here, both files are open successfully
        printf("Opened '%s' in READ MODE.\n", inputTextFile);
        printf("The output file name is '%s'.\n", outputBinFile);
        printf("Opened '%s' in WRITE BINARY MODE.\n", outputBinFile);
        break; // Exit the while loop, proceed with reading/writing
    }

    Student s;
    char buffer[MAXLINE_SIZE];
    while(fgets(buffer, MAXLINE_SIZE, fin)){


        buffer[strcspn(buffer, "\n")] = 0;
        strncpy(s.name, buffer, MAX_NAME_LEN - 1);
        s.name[MAX_NAME_LEN - 1] = '\0';


        fgets(buffer, MAXLINE_SIZE, fin);
        s.cwid = atoi(buffer);

        fgets(buffer, MAXLINE_SIZE, fin);
        buffer[strcspn(buffer, "\n")] = 0;
        strncpy(s.major, buffer, MAX_MAJOR_LEN - 1);
        s.major[MAX_MAJOR_LEN - 1] = '\0';

        fgets(buffer, sizeof(buffer), fin);
        buffer[strcspn(buffer, "\n")] = 0;

        if (strcmp(buffer, "Freshman") == 0)
            s.standing = Freshman;
        else if (strcmp(buffer, "Sophomore") == 0)
            s.standing = Sophomore;
        else if (strcmp(buffer, "Junior") == 0)
            s.standing = Junior;
        else if (strcmp(buffer, "Senior") == 0)
            s.standing = Senior;
        else
            printf("Unknown standing: %s\n", buffer);
        
        fgets(buffer, MAXLINE_SIZE, fin);
        buffer[strcspn(buffer, "\n")] = 0; 
        s.number_classes_enrolled = atoi(buffer);

        for (unsigned int i = 0; i < s.number_classes_enrolled; i++) {
            fgets(buffer, MAX_COURSE_LEN, fin);
            buffer[strcspn(buffer, "\n")] = 0;
            strncpy(s.class_schedule[i], buffer, MAX_COURSE_LEN - 1);
            s.class_schedule[i][MAX_COURSE_LEN - 1] = '\0';
        }

        fgets(buffer, MAXLINE_SIZE, fin);
        buffer[strcspn(buffer, "\n")] = 0; 
        s.phone = atoll(buffer);

        fgets(buffer, MAXLINE_SIZE, fin);
        buffer[strcspn(buffer, "\n")] = 0;  
        s.parking_fee = atof(buffer); // Convert string to float



        printf("Name: %s\n", s.name);
        printf("CWID: %u \n", s.cwid);
        printf("Major: %s\n", s.major);
        printf("Class Standing: ");
        StandingToString(s.standing); // Return the print of Class Standing
        printf("Class Enrolled: %u\n", s.number_classes_enrolled);
        for (unsigned int i = 0; i < s.number_classes_enrolled; i++) {
            printf("  Class %d: %s\n", i + 1, s.class_schedule[i]);
        }
        printf("Phone Number: %lu\n", s.phone);
        printf("Parking Fee: %.2f\n", s.parking_fee);

        fwrite(&s, sizeof(Student), 1, fout); // Write to the Binary file
    }

    fclose(fin);
    fclose(fout);

    printf("\nFinished writing students to binary file: %s\n", outputBinFile);
    return 0;
}
