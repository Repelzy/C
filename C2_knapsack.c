#include <stdio.h>
int s[1000];
int v[1000];
int N, M, maxI= 0;

void Try(int k, int P, int Q)
{
    if (k == N-1)
    {
        if (s[k] <= M - Q)
        {
            if (maxI < P + v[k])
            {
                maxI = P + v[k];
            }
        }
        else
        {
            if (maxI < P)
            {
                maxI = P;
            }
        }
    }
    else
    {
        if (s[k] <= M - Q)
        {
            Try(k + 1, P + v[k], Q + s[k]);
        }
        
        Try(k + 1, P, Q);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &s[i], &v[i]);
    }
    Try(0, 0, 0);
    printf("%d", maxI);
    return 0;
}