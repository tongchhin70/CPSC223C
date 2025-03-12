#include <stdio.h>
#include <string.h>

void print_array(char *arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Token [%d]: %s\n", i, arr[i]);
    }
}