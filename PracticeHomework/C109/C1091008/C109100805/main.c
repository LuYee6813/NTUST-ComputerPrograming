#include <stdio.h>


int main()
{
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	int c = a % b;
	printf("%d mod %d = %d", a, b, c);
	return 0;
}