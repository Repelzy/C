#include <stdio.h>

int a[10000];
int n,m;
void printSolution()
{
	int i;
	for (i=1;i<=m;i++)
	{
		printf("%d ", a[i]);
	
	}
		printf("\n");
}

void generateFirstSolution(){
	int i;
	for (i=1;i<=m;i++) a[i]=i;
}

int main(){
	scanf("%d %d", &m,&n);
	generateFirstSolution();
	while(1){
		printSolution();
		int i=m;
		while (i>=1 && a[i]==n-m+1) i=i-1;
		if (i<1) break;
		a[i] = a[i] + 1;
		int j;
		for (j=i+1;j<=m;j++) a[j]=a[j-1] +1;
	}
	return 0;
}
