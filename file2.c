#include <stdio.h>
#define K2M 0.621

int main()
{
    float km;
    printf("Enter the number: ");
    scanf("%f", &km);
    float convert = K2M * km;
    printf("The conversion is: %.2f\n", convert);
    return 0;
}