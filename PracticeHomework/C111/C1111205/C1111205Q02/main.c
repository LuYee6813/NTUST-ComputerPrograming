#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
int printSeries(int n)
{
	if (n == 0 || n == 1 || n == 2)
		return 0;
	else if (n == 3)
		return 1;
	else
		return printSeries(n - 1) + printSeries(n - 2) + printSeries(n - 3);
}

void tribonacci(int n)
{
	printf("%d", printSeries(n));
}

int main()
{
	int n;
	scanf("%d", &n);
	tribonacci(n+1);
	return 0;
}