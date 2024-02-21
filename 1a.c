#include <stdio.h>
#include <string.h>

typedef struct INPUT{
    int d;
    char name[10];
    int change;
}INPUT;

int main(){
    int n; scanf("%d", &n);
    INPUT x[n];
    for(int i = 0; i < n; i++){
        scanf("%d %s %d", &x[i].d, x[i].name, &x[i].change);
    }
    int sum1 = 0, sum2 = 0, sum3= 0;
    for(int i = 0; i < n; i++){
        if(strcmp(x[i].name, "Jersey") == 0){
            sum1 += x[i].change;
        }
        else if(strcmp(x[i].name, "Sind") == 0){
            sum2 += x[i].change;
        }
        else if(strcmp(x[i].name, "Vang") == 0){
            sum3 += x[i].change;
        }
    }   
    int maxS = sum1;
    if(sum2 > maxS){
        maxS = sum2;
    }
    else if(sum3 > maxS){
        maxS = sum3;
    }
    printf("%d\n", abs(maxS));
}