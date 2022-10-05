#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0) {
        printf("It is an ugly number.");
    }
    else {
        printf("It is not an ugly number.");
    }
}