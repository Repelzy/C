#include <stdio.h>


int x[10];
int dem = 0;
int n =4;

void ghinhan(){
    int i; 
    printf("c%d:", ++dem);
    for(int i = 1; i <= n; i++){
        printf("%d", x[i]);
        if(i<n) printf(",");
    }
    printf(";");
}


int abs(int a){
    if(a<0){
      return -a; 
    }
    return a;
}

int check(int ucv, int k){
    int j; 
    for(int j = 1; j < k; j++){
        if(x[j] == ucv){
            return 0;
        }
        if(abs(j-k) == abs(ucv-x[j])) return 0;
    }
    return 1;
}

void Try(int k){
    int i; 
    for(i = n; i >= 1; i--){
        if(check(i,k) == 1){
            x[k] = i;
            if(k==n)ghinhan();
            else{
                Try(k+1);
            }
        }
    }
}


int main(){
    Try(1);
}