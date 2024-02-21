#include <stdio.h>
#define MAX 1000

int main() {
    int N, T, S, R;
    int i, t[MAX], s[MAX], r[MAX];
    int busy[MAX] = {0};
    int max_free = 0, slot = 0;

    scanf("%d %d %d %d", &N, &T, &S, &R);
    for(i = 1; i <= N; i++) {
        scanf("%d %d %d %d", &i, &t[i], &s[i], &r[i]);
        busy[s[i]]++;
    }

    for(i = 1; i <= S; i++) {
        if(T - busy[i] > max_free) {
            max_free = T - busy[i];
            slot = i;
        }
    }

    printf("%d %d\n", slot, max_free);

    return 0;
}
