#include <stdio.h>
#include <limits.h>

#define N 100

int c[N][N];
int n;
int x[N];
int f;
int best_f;
int visited[N];
int xMin[N];

void solution()
{
    if (f + c[x[n]][x[1]] < best_f) {
        best_f = f + c[x[n]][x[1]];
        printf("Update best: %d\n", best_f);
    }

    int i;
    for (i = 1; i <= n; i++) {
        xMin[i] = x[i];
    }
}
	

void Try(int k)
{
    int v;
    for (v = 1; v <= n; v++) {
        if (visited[v] == 0) {
            x[k] = v;
            f = f + c[x[k - 1]][x[k]];
            visited[v] = 1;

            if (f + c[x[k - 1]][x[k]] + c[x[k]][x[1]] * (n - k + 1) < best_f) {
                Try(k + 1);
            }

            visited[v] = 0;
            f = f - c[x[k - 1]][x[k]];
        }
    }
}


void input()
{
    scanf("%d", &n);
    int i;
    int j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }
}

int main()
{
    freopen("tsp.txt", "r", stdin);
    input();
    int v;
    for (v = 1; v <= n; v++) {
        visited[v] = 0;
    }

    best_f = INT_MAX;
    f = 0;

    x[1] = 1;
    visited[x[1]] = 1;

    Try(2);

    printf("Best solution: ");
    int i;
    for (i = 1; i <= n; i++) {
        printf("%d ", xMin[i]);
    }
    printf("\n");

    return 0;
}

