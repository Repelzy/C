#include <stdio.h>

#define MAX_SIZE 100

int a[MAX_SIZE];

void solve(int n, int m, int sum, int c) {
    if (c == n) {
        if (sum == m) {
            for (int j = 0; j < n; j++) {
                printf("%d ", a[j]);
            }
            printf("\n");
        }
        return;
    }

    for (int i = 1; i <= m - sum; i++) {
        a[c] = i;
        solve(n, m, sum + i, c + 1);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    solve(n, m, 0, 0);

    return 0;
}
