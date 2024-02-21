#include <stdio.h>

void dectohex(long long n)
{
    if (n < 16)
    {
        if (n < 10)
        {
            printf("%d", n);
        }
        else
        {
            printf("%c", (55 + n));
        }
    }
    else
    {
        dectohex(n/16);
        int r = n % 16;
        if (r < 10)
        {
            printf("%d", r);
        }
        else
        {
            printf("%c", (55 + r));
        }
    }
}

int main()
{
    long long n; scanf("%lld", &n);
    dectohex(n);
}