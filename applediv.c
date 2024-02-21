#include <stdio.h>
#include <stdlib.h>

int findMinDifference(int apples[], int n, int sumSet1, int sumSet2, int index) {
    if (index == n) {
        return abs(sumSet1 - sumSet2);
    }

    int opt1 = findMinDifference(apples, n, sumSet1 + apples[index], sumSet2, index + 1);
    int opt2 = findMinDifference(apples, n, sumSet1, sumSet2 + apples[index], index + 1);

    return (opt1 < opt2) ? opt1 : opt2;
}

int main() {
    int n;
    scanf("%d", &n);

    int apple[20];
    for (int i = 0; i < n; i++) {
        scanf("%d", &apple[i]);
    }

    int res = findMinDifference(apple, n, 0, 0, 0);
    printf("%d\n", res);

    return 0;
}
