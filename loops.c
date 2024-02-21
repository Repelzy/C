#include <stdio.h>

int main()
{ 
 /*   int i,j=1;
    while (i<=10, j<=10){
        printf("%d\n", i+j);
        i++;
        j++;
    } */

    int i,j;
    for(i=10, j=1; i>=0; i--, j=i+1){
        printf("i=%d j=%d\n", i, j);
    }


return 0;


}