#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int Pow(int a, int b)
{ 
	int c = 1;
	for (int i = 1; i <= b; i++)
	{
		c = c * a;
	}
	return c;
}



int main()
{
	int c = 1240;
	char A[7];
	int s = sizeof(A);
	int moneyinp = 0;
	int buy = 0;
	fgets(A, s, stdin);
    for (int i = 0; i < s; i++)
    {
    	if (isspace(A[i]))
    	{
    		for (int j = 0; j < i; j++)
    		{
    			int h = A[j] - 48;
    			int h1 = h * Pow(10, i - 1 - j); 
    			moneyinp = moneyinp + h1;
    		}
    		for (int k = i + 1; k < s - 1; k++)
    		{
                int l = A[k] - 48;
                int l1 = l * Pow(10, s - 2 - k);
                buy = buy + l1;  
    		}

    	}
    }
    int moneyout = c * buy;
	if (moneyinp >= moneyout)
	{
     printf("%d\n", moneyout);
	}
	else
	{
      printf("%d\n", 0);
	}
	return 0;
}
