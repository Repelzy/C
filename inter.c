#include <stdio.h>

void main()
{
    int n;
    int i=0;
    int b=1;
    do { 
        printf("Nhap 1 so nguyen lon hon 0: ");
        scanf("%d", &n);        
    } while (n<=0);
    
    while(i<=n)
    {
    		printf("%d!=%d\n",i,b);
    		i++;
    		b *= i;
        
    }
}


