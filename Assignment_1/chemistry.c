#include <stdio.h>
#include <stdlib.h>

int main(){
    float vol1;
    float vol2;
    float vol3;

    float totalVolume;

    float percentage1;
    float percentage2;
    float percentage3;

    float result;


    printf("\nEnter Volume 1: ");
    scanf("%f", &vol1);
    printf("\nEnter Percentage 1: ");
    scanf("%f", &percentage1);

    printf("\nEnter Volume 2: ");
    scanf("%f", &vol2);
    printf("\nEnter Percentage 2: ");
    scanf("%f", &percentage2);

    printf("\nEnter Volume 3: ");
    scanf("%f", &vol3);
    printf("\nEnter Percentage 3: ");
    scanf("%f", &percentage3);


    totalVolume = vol1 + vol2 + vol3;
    result = (vol1*percentage1)+(vol2*percentage2)+(vol3*percentage3);


    printf("\n Total Volume of BLANK: %2.fmL", totalVolume);
    printf("\n Volume of BLANK: %2.fmL", result);

    return 0;
}