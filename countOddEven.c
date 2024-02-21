#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    int odd = 0; int even = 0;
    for(int i = 0; i < n ; i++){
        scanf("%d", &a[i]);
        if(a[i] % 2){
            odd++;
        }
        else{
            even++;
        }
    }
    printf("%d %d", odd, even);
}