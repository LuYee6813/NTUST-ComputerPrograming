// n*n矩陣乘法(三維陣列方法)
// 測資：
// 4
// 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31
// 0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int res[9][9][9] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &res[0][i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &res[1][i][j]);
        }
    }

    // 計算矩陣相乘並存進res(n*n)陣列

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k =0; k<n;k++){
                res[2][i][j] += res[0][i][k] * res[1][k][j];
            }
        }
    }

    // 印出n1(n*n)陣列
    printf("\nn1[%d]*[%d]:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", res[0][i][j]);
        }
        printf("\n");
    }

    // 印出n2(n*n)陣列
    printf("\nn2[%d]*[%d]:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", res[1][i][j]);
        }
        printf("\n");
    }

    // 印出res(n*n)陣列
    printf("\nres[%d]*[%d]:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", res[2][i][j]);
        }
        printf("\n");
    }

    return 0;
}