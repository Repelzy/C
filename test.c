#include <stdio.h>
#include <limits.h>

#define N 100

int c[N][N];
int n;
int x[N];
int f;
int fmin;
int visited[N];
int xMin[N];

void solution()
{
	if (f + c[x[n]][x[1]] < fmin) {
		fmin = f + c[x[n]][x[1]];
		printf("Update best: %d\n", fmin);
	}

	int i;
	for (i = 1; i <= n; i++) {
		xMin[i] = x[i];
	}
}

void Try(int k) {
	int v;
	for (v = 1; v <= n; v++) {
		if (visited[v] == 0) {
			x[k] = v;
			f = f + c[x[k - 1]][x[k]];
			visited[v] = 1;

			if (f + c[x[k]][x[1]] * (n - k + 1) < fmin) {
				Try(k + 1);
			}

			visited[v] = 0;
			f = f - c[x[k - 1]][x[k]];
		}
	}
}

void input(){
    scanf("%d", &n);
    for (int i =1; i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d", &c[i][j]);
}

int main()
{
	// Assuming you have initialized the 'c' matrix and other variables
    freopen("tsp.txt", "r", stdin);
    input();
	// Initialize visited array
	for (int v = 1; v <= n; v++) {
		visited[v] = 0;
	}

	// Set initial values for fmin and f
	fmin = INT_MAX;
	f = 0;

    x[1]=1;visited[x[1]]=1;
	// Call the recursive Try function starting with k = 2
	Try(2);

	printf("Best solution: ");
	for (int i = 1; i <= n; i++) {
		printf("%d ", xMin[i]);
	}
	printf("\n");

	return 0;
}
