// n*n矩陣加法 三維陣列方法
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
    int res[9][9][9];
    scanf("%d", &matrices_count);
    scanf("%d", &n);
    for (int i = 0; i < matrices_count; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                scanf("%d", &res[i][j][k]);
            }
        }
    }

    for (int i = 0; i < matrices_count; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                res[2][j][k] = res[0][j][k] + res[1][j][k];
            }
        }
    }
    
    for (int i = 0; i <= matrices_count; i++)
    {
        printf("第%d個陣列:\n", i);
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                printf("%d ", res[i][j][k]);
            }
            printf("\n");
        }
    }

    return 0;
}