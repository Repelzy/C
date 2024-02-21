#include <stdio.h>

int b[10000];
int n;

void print()
{
    int i;
    for (i=1; i<=n; i++)
    {
        printf("%d", b[i]);
    }
    printf("\n");
}

int main()
{
    int i;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        b[i]=0;
    }
    
    while(1)
    {
        print();
        int i=n;
        while(i>=1 && b[i]==1)
        {
            i--;        
        } 
        if (i<1) break;
        b[i]=1;
        int j;
        for (j=i+1; j<=n; j++)
        {
            b[j]=0;
        }
    }
    return 0;
}   

