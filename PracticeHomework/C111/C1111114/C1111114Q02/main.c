#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>  
#include <stdlib.h>  
int cmp(const void* a, const void* b)
{
    return ((float*)a)[0] - ((float*)b)[0];
}
int main()
{
    int t = 0;
    int i = 0;
    int c = 0;
    float num[10][2];
    scanf("%d", &t);
    int n = t;
    while (t--) {
        scanf("%f %f", &num[c][0], &num[c][1]);
        c++;
    }
    qsort(num, n, sizeof(float) * 2, cmp);
    for (i = 0; i < n; i++)
    {
        printf("%.2f %.2f\n", num[i][0], num[i][1]);
    }

    return 0;
}

//#pragma warning(disable : 4996)
//#pragma warning(disable : 6031)
//#include <stdio.h>
//
//int main()
//{
//    float number, First[10] = { 0 }, Second[10] = { 0 };
//    scanf("%f", &number);
//    for (int i = 1; i <= number; i = i + 1) {
//        scanf("%f", &First[i - 1]);
//        scanf("%f", &Second[i - 1]);
//    }
//    for (int i = 1; i <= number; i = i + 1) {
//        for (int j = 0; j < number - 1; j = j + 1) {
//            if (First[j] > First[j + 1]) {
//                float t = First[j];
//                First[j] = First[j + 1];
//                First[j + 1] = t;
//                float k = Second[j];
//                Second[j] = Second[j + 1];
//                Second[j + 1] = k;
//            }
//            if (First[j] == First[j + 1]) {
//                if (Second[j] > Second[j + 1]) {
//                    float k = Second[j];
//                    Second[j] = Second[j + 1];
//                    Second[j + 1] = k;
//                }
//            }
//        }
//    }
//    for (int i = 1; i <= number; i = i + 1) {
//        printf("%.2f %.2f\n", First[i - 1], Second[i - 1]);
//    }
//    return 0;
//}