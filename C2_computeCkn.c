#include <stdio.h>

#define MOD 1000000007
#define MXN 1000

int n, k;
int a[MXN][MXN];

void dp() {
    a[1][0] = 1;
    a[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                a[i][j] = 1;
            else {
                a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % MOD;
            }
        }
    }
}

int main() {
    scanf("%d %d", &k, &n);
    dp();
    printf("%d\n", a[n][k]);
    return 0;
}
