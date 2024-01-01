#include <stdio.h>

int main() {
    int n, k, k1, m;
    scanf("%d %d", &n, &k);

    int A[n][k];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    scanf("%d %d", &k1, &m);

    int B[k][m];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    int C[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = 0;
            for (int x = 0; x < k; x++) {
                C[i][j] += A[i][x] * B[x][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
