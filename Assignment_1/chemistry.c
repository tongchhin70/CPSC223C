#include <stdio.h>
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
    
    //init vars
    float vol1;
    float vol2;
    float vol3;
    float totalVolume;
    float percentage1;
    float percentage2;
    float percentage3;
    float result;
    float percentageTotal;

    //users information
    char name[30];
    char title[30];

    // printf("\nWelcome to Modern Chemistry brought to by Chief Software Engineer Tong Chhin");
    // printf("\nThe time is now: %s\n", display_time);

    // printf("\nPlease Enter Your Name:");
    // fgets(name, 30, stdin);
    // name[strcspn(name, "\n")] = 0; //removes new line by fgets

    // printf("\nPlease enter your title: (Director, Sargent, Ms, Chief, Engineer, Fishmonger, etc):");
    // fgets(title, 30, stdin);
    // title[strcspn(title, "\n")] = 0; //removes new line by fgets

    // printf("Thank you %s %s", title, name);

    printf("\nPlease enter the volume (ml) of the liquid in beaker #1:");
    scanf("%f", &vol1);

    printf("\nPlease enter the percent of alcohol in beaker #1 as decimal fraction:");
    scanf("%f", &percentage1);

    printf("\nPlease enter the volume (ml) of the liquid in beaker #2:");
    scanf("%f", &vol2);

    printf("\nPlease enter the percent of alcohol in beaker #2 as decimal fraction:");
    scanf("%f", &percentage2);

    printf("\nPlease enter the volume (ml) of the liquid in beaker #3:");
    scanf("%f", &vol3);

    printf("\nPlease enter the percent of alcohol in beaker #3 as decimal fraction:");
    scanf("%f", &percentage3);

    printf("\nThank you for entering these data. The results are being computed.");

    //calculations
    totalVolume = vol1 + vol2 + vol3;
    result = (vol1*percentage1)+(vol2*percentage2)+(vol3*percentage3);
    percentageTotal = (result/totalVolume)*100;

    printf("\n################################################################################################################################");

    printf("\n\n\nThe final beaker contains %.3f ml of fluid of which %.3f ml is alcohol: %.3f%% mL\n\n", totalVolume, result, percentageTotal);

    printf("\n################################################################################################################################");


    printf("\n\nThe time is now: %s", display_time);
    printf("\nThe number of seconds since the Great Epoch is %lu\n\n\n", current_time);

    return 0;
}