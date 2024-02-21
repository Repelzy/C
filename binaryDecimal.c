#include <stdio.h>

void binaryConvert(long long n){
    if(n == 0 || n == 1){
        printf("%d", n);
    }
    else{
        binaryConvert(n/2);
        printf("%d", n%2);
    }
}

int main(){
    long long n; scanf("%lld", &n);
    binaryConvert(n);
}