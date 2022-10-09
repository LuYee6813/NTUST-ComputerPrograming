// 字串沙漏
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int n,c=0;
	scanf("%d", &n);

	for (int i = n; i > 0; i--)
	{
		for (int j = n - i; j > 0; j--)
			printf(" ");
		for (int j = i * 2 - 1; j > 0; j--)
			printf("%c",'A'+c);
		printf("\n");
		c++;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = n - i; j > 0; j--)
			printf(" ");
		for (int j = i * 2 - 1; j > 0; j--)
			printf("%c",'A'+c);
		printf("\n");
		c++;
	}
	
	return 0;
}