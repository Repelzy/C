#include<stdio.h>
#include<string.h>
 
int main()
{
    char str[100];
    int cnt=0;
    int c;
    while((c=getchar())!=EOF)
    {
        scanf("%s", str);
        cnt++;
    }
    printf("%d", cnt-1);
    return 0;
}