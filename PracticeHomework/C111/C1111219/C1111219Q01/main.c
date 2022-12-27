#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

#define LEN_NAME 50

struct student
{
    // Student name
    char name[LEN_NAME];

    // English score
    int english;

    // Math score
    int math;
};

int main()
{
    int n = 0;
    int english=0, math = 0;
    char name[LEN_NAME];
    struct student x;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("\n%49[^,],%d,%d", &name, &english, &math);
        strcpy(x.name, name);
        x.english = english;
        x.math = math;
        printf("%s: %d, %d\n",x.name,x.english,x.math);
    }

    return 0;
}