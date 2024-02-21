#include <stdio.h>
#define pay 15000

int payment(int hours);
int main()
{
    int hours;
    do
    {
        printf("Enter hours: ");
        scanf("%d", &hours);
    }  while(hours<10 || hours >65);
    printf("Wage = %d\n", payment(hours));
}


int payment(int hours)
{
    int wage;
    if(hours <=40 ){
        wage = hours * pay;
    }
    else{
        wage = 40 * pay + (hours-40) * pay * 3/2; 
    }
    return wage;
}