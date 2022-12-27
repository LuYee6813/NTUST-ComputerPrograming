#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
    int arr[10];
    int output[10] = {0,0,0,0,0,0,0,0,0,0};
    int i=0, j=0;

    for (i = 0; i < 10; i++) scanf_s("%d", &arr[i]);

    //泡沫排序
    for (i = 0; i < 9; i++) 
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    //找重複的值
    for (i = 0; i < 9; i++)
    {
        if (arr[i + 1] == arr[i]) output[i] = arr[i];
    }

    // 雙指標去除重複數字
    int slow = 0, fast = 0;
    while (fast < 10)
    {
        if (output[fast] != output[slow]) 
        {
            slow++;                     
            output[slow] = output[fast];
        }
        fast++;
    }
    for (i = 0; i < 10; i++) printf("%d ",output[i]);
    int sum = 0;
    for (i = 0; i <= slow; i++) sum += output[i];
    printf("%d", sum);
    return 0;
}
//10 15 23 15 55 75 55 15 55 1112