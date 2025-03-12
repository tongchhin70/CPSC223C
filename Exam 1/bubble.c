#include <stdio.h>
#include <string.h>
#include "bubble.h"  

void bubble(char *arr[], int n) {
    char *temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j][0] > arr[j + 1][0]) {  // Compare first character
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the sorted array
void print_array(char *arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("[%d]: %s\n", i, arr[i]);
    }
}