#include <stdio.h>

int x[1000];
int m[1000];
int n;

void print() {
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void Try(int k) {
    for (int v = 1; v <= n; v++) {
        if (m[v] == 0) {
            x[k] = v;
            m[v] = 1;
            if (k == n)
                print();
            else
                Try(k + 1);
            m[v] = 0;  
        }
    }
}

int main() {
    scanf("%d", &n);
    Try(1);
    return 0;
}