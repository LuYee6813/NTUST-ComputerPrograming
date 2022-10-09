// n*n矩陣乘法 3個二維陣列方法
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int n1[9][9] = {0};
    // {
    //     1,3,5,7,
    //     9,11,13,15,
    //     17,19,21,23,
    //     25,27,29,31
    // };
    int n2[9][9] = {0};
    // {
    //     0,2,4,6,
    //     8,10,12,14,
    //     16,18,20,22,
    //     24,26,28,30
    // };
    int res[9][9] = {0};
    // 讀取值存進n*n的n1陣列
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &n1[i][j]);
        }
    }
    // 讀取值存進n*n的n2陣列
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &n2[i][j]);
        }
    }

    // 計算矩陣相乘並存進res(n*n)陣列

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k =0; k<n;k++){
                res[i][j] += n1[i][k] * n2[k][j];
            }
            //     i  j        i  k     k  j
            // res[0][0] += n1[0][0]*n2[0][0]
            // res[0][0] += n1[0][1]*n2[1][0]
            // res[0][0] += n1[0][2]*n2[2][0]
            // res[0][0] += n1[0][3]*n2[3][0]

            // res[1][0] += n1[1][0]*n2[0][1]
            // res[1][0] += n1[1][1]*n2[1][1]
            // res[1][0] += n1[1][2]*n2[2][1]
            // res[1][0] += n1[1][3]*n2[3][1]
        }
    }

    // 印出n1(n*n)陣列
    printf("\nn1[%d]*[%d]:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", n1[i][j]);
        }
        printf("\n");
    }

    // 印出n2(n*n)陣列
    printf("\nn2[%d]*[%d]:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", n2[i][j]);
        }
        printf("\n");
    }

    // 印出res(n*n)陣列
    printf("\nres[%d]*[%d]:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}