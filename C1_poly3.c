#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

float a,b,c;

double display(float x){
    return x*x*x+a*x*x+b*x+c;
}

int min(int a, int b){
    if(a > b) return b;
    else return a;
}

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

bool check(int i, int j, int k){
    if(i+j+k==-a && i*j+i*k+j*k==b && i*j*k==-c) return true;
    else return false;
}

int main(){
    scanf("%f %f %f", &a, &b, &c);
    int x1, x2, x3, tmp;
    bool flag = false;
    for(int i = -100; i <= 100; i++){
        if (display(i) == 0) tmp = i;
    }
    for(int j = -1000; j <= 1000; j++){
        for(int k = -1000; k <= 1000; k++){
            if(check(tmp, j, k)==true){
                x1 = min(min(tmp, j), k);
                x3 = max(max(tmp, j), k);
                x2 = -a-x1-x3;
                flag = true; 
                break;
            }
        }
    }
    if(flag==false) {
        printf("NO SOLUTION\n");
    } else {
        if(x1==x2 && x1==x3) {
            printf("%d %d\n", x1, 3);
        } else if(x1==x2) {
            printf("%d %d\n%d %d\n", x1, 2, x3, 1);
        } else if(x2==x3) {
            printf("%d %d\n%d %d\n", x1, 1, x3, 2);
        } else {
            printf("%d %d\n%d %d\n%d %d\n", x1, 1, x2, 1, x3, 1);
        }
    }
    return 0;
}
