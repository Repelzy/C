#include <stdio.h>

int x[1000];
int n;

void print(){
    for(int i = 1; i <= n; i++){
        printf("%d", x[i]);
    }
    printf("\n");
}

void Try(int k){
    for(int v = 0; v <= 1; v++){
        if(x[k-1] + v < 2 ){
            x[k] = v;
            if(k == n) print();
             else{
                Try(k+1);
            }
        } 
           
    }
}

int main(){
    scanf("%d", &n);
    x[0] = 0;
    Try(1);
    return 0;
}