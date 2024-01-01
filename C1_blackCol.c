#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int matrix[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int blackColumns = 0;
    for (int j = 0; j < m; j++) {
        int isBlackColumn = 1;
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] == 0) {
                isBlackColumn = 0;
                break;
            }
        }
        if (isBlackColumn) {
            blackColumns++;
        }
    }

    printf("%d\n", blackColumns);

    return 0;
}
