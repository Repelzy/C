#include <stdio.h>

int main(){
    int i,n,j,count=0; 
    char s[100];
    
    scanf("%d%s", &n, s);
    for (i=0;i<n-1; i++){
        if (s[i]==s[i+1]){
            count++;
        }
        for(j=i+1;j<n;j++){
            s[j-1]=s[j];
        }
            n--;
    if (i>0){
        i = i-1;
    }
    else{
        i=-1;
    }

    }
    printf("%d\n", count);
    return 0;
}