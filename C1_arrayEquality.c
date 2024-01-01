#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        int a[n];
        int b[m];

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        int check = 1; 

        if (n != m) {
            check = 0; 
        } else {
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    check = 0; 
                    break;
                }
            }
        }

        if (check) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

    return 0;
}
