#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

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

int main() {
    char binFile[256];
    FILE *fin;
    Student s;

    while (1) {
        printf("Enter filename: ");
        // If user presses Ctrl+D or we can't read, exit the program
        if (!fgets(binFile, sizeof(binFile), stdin)) {
            printf("\nExiting Program, Thank you and Goodbye!\n");
            return 0;
        }
        // Remove trailing newline from user input
        binFile[strcspn(binFile, "\n")] = '\0';

        // Try opening the input file in read mode
        fin = fopen(binFile, "rb");
        if (!fin) {
            printf("Invalid file name '%s'. Please try again.\n", binFile);
            continue;  // Go back and prompt again
        }

        // If we reach here the file opened successfully
        printf("Opened '%s' in READ BINARY MODE.\n", binFile);
        break; // Exit the while loop, proceed with reading/writing
    }

    int count = 0;
    while (fread(&s, sizeof(Student), 1, fin) == 1) {
        printf("----------------------------------\n");
        printf("Student #%d\n", ++count);
        printf("Name: %s\n", s.name);
        printf("CWID: %u\n", s.cwid);
        printf("Major: %s\n", s.major);
        printf("Class Standing: "); 
        StandingToString(s.standing);
        printf("Class Enrolled: %u\n", s.number_classes_enrolled);
        for (unsigned int i = 0; i < s.number_classes_enrolled; i++) {
            printf("  Class %d: %s\n", i + 1, s.class_schedule[i]);
        }
        printf("Phone Number: %lu\n", s.phone);
        printf("Parking Fee: $%.2f\n", s.parking_fee);
    }

}