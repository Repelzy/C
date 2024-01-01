#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int cnt = 0;
    int sum = 0;
    int l = 0;

    for (int r = 0; r < n; r++) {
        sum += a[r];

        if (r - l + 1 > k) {
            sum -= a[l];
            l++;
        }

        if (r - l + 1 == k && sum % 2 == 0)
            cnt++;
    }

    printf("%d\n", cnt);
    return 0;
}
