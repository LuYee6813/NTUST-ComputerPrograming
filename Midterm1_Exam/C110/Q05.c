// n*n矩陣加法 兩二維陣列相加方法
// input:
// 2
// 4
// 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31
// 0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30
// output:
// 1 5 9 13
// 17 21 25 29
// 33 37 41 45
// 49 53 57 61
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
    int matrices_count, n;
    int A[9][9];
    int B[9][9];
    int res[9][9];
    scanf("%d", &matrices_count);
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = A[i][j] + B[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",res[i][j] );
        }
        printf("\n");
    }

    return 0;
}