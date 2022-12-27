//單字計算
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	char s[100];
	int count = 0;
	while ((scanf("%s", &s)) != EOF)
	{
		printf("%s", s);
		count++;
		printf("\n");
	}
	printf("%d", count);
    
	return 0;
}