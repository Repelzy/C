#include <stdio.h>

int main()
{
    int n, i, fib1 = 1, fib2 = 2, nextFib;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (i = 1; i <= n; i++)
    {
        printf("%d, ", fib1);
        nextFib = fib1 + fib2;
        fib1 = fib2;
        fib2 = nextFib;
    }

    return 0;
}
