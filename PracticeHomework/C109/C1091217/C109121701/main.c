#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
int cmp2(const void* a, const void* b)
{
    float c = *(float*)a - *(float*)b;
    if (c > 0) return 1;
    if (c < 0) return -1;
    return 0;
}
int main()
{
    char input[100], * token, * temp;
    int s1[2001], s2[2001], s3[2001], s4[2001];
    float s5[2001];
    float avg1 = 0, avg2 = 0, avg3 = 0, avg4 = 0, avgb1 = 0, avgb2 = 0, avgb3 = 0, avgb4 = 0;
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    int n = 0;
    float ratio1 = 0, ratio2 = 0, ratio3 = 0, ratio4 = 0;
    float allScore = 0;

    scanf("%d,%f,%f,%f,%f", &n, &ratio1, &ratio2, &ratio3, &ratio4);
    getchar();
    int i = 0;
    for (i = 0; i < n; i++)
    {
        gets(input);
        token = strtok(input, ",");

        token = strtok(NULL, ",");
        s1[i] = atoi(token);
        token = strtok(NULL, ",");
        s2[i] = atoi(token);
        token = strtok(NULL, ",");
        s3[i] = atoi(token);
        token = strtok(NULL, ",");
        s4[i] = atoi(token);

        avg1 += s1[i];
        avg2 += s2[i];
        avg3 += s3[i];
        avg4 += s4[i];

        if (s1[i] != 0) count1++, avgb1 += s1[i];
        if (s2[i] != 0) count2++, avgb2 += s2[i];
        if (s3[i] != 0) count3++, avgb3 += s3[i];
        if (s4[i] != 0) count4++, avgb4 += s4[i];
        s5[i] = s1[i] * ratio1 + s2[i] * ratio2 + s3[i] * ratio3 + s4[i] * ratio4;
        allScore += s5[i];
    }

    qsort(s1, n, sizeof(int), cmp);
    qsort(s2, n, sizeof(int), cmp);
    qsort(s3, n, sizeof(int), cmp);
    qsort(s4, n, sizeof(int), cmp);
    qsort(s5, n, sizeof(float), cmp2);
    int median = n / 2;
    printf("%.2f %.2f %.2f %.2f\n", avg1 / (n * 1.0), avg2 / (n * 1.0), avg3 / (n * 1.0), avg4 / (n * 1.0));
    printf("%.2f %.2f %.2f %.2f\n", avgb1 / (count1 * 1.0), avgb2 / (count2 * 1.0), avgb3 / (count3 * 1.0), avgb4 / (count4 * 1.0));
    printf("%d.00 %d.00 %d.00 %d.00\n", 
        n % 2 == 1 ? s1[median + 1] : (s1[median] + s1[median - 1]) / 2,
        n % 2 == 1 ? s2[median + 1] : (s2[median] + s2[median - 1]) / 2,
        n % 2 == 1 ? s3[median + 1] : (s3[median] + s3[median - 1]) / 2,
        n % 2 == 1 ? s4[median + 1] : (s4[median] + s4[median - 1]) / 2
        );
    printf("%.2f %.2f", 
        (allScore + 0.005) / (n * 1.0), 
        n % 2 == 1 ? s5[median + 1] : (s5[median] + s5[median - 1]) / 2);

    return 0;
}