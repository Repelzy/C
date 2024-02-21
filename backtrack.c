#include <stdio.h>

#define N 100
int x[N];
int n;

int check(int v, int k)
{
	int i;
	for (i = 1; i <= k - 1; i++)
		if (x[i] == v)
			return 0;
	return 1;
}

void solution()
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%d ", x[i]);
	printf("\n");
}

void Try(int k)
{
	int v;
	for (v = 1; v <= n; v++)
	{
		if (check(v, k))
		{
			x[k] = v;
			if (k == n)
			{
				solution();
			}																																																																																																																																																																																																																																																																																																																																																																																				
			else
			{
				Try(k + 1);
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	Try(1);
	return 0;
}

