#include <stdio.h>

#define N 9

int isValidRow(int grid[N][N], int row)
{
    int digits[N + 1] = {0};
    for (int col = 0; col < N; col++)
    {
        digits[grid[row][col]]++;
        if (digits[grid[row][col]] > 1)
            return 0;
    }
    return 1;
}

int isValidCol(int grid[N][N], int col)
{
    int digits[N + 1] = {0};
    for (int row = 0; row < N; row++)
    {
        digits[grid[row][col]]++;
        if (digits[grid[row][col]] > 1)
            return 0;
    }
    return 1;
}

int isValidBox(int grid[N][N], int startRow, int startCol)
{
    int digits[N + 1] = {0};
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            int num = grid[row + startRow][col + startCol];
            digits[num]++;
            if (digits[num] > 1)
                return 0;
        }
    }
    return 1;
}

int isValid(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        if (!isValidRow(grid, i) || !isValidCol(grid, i))
            return 0;
    }
    for (int row = 0; row < N; row += 3)
    {
        for (int col = 0; col < N; col += 3)
        {
            if (!isValidBox(grid, row, col))
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int grid[N][N];
        for (int row = 0; row < N; row++)
            for (int col = 0; col < N; col++)
                scanf("%d", &grid[row][col]);
        printf("%d\n", isValid(grid));
    }
    return 0;
}
