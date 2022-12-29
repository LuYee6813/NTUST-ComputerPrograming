#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = n; i > 0; i--)
	{
		for (int j = n - i; j > 0; j--)
			putchar(' ');
		for (int j = i * 2 - 1; j > 0; j--)
			putchar('*');
		putchar('\n');
	}

	
	return 0;
}