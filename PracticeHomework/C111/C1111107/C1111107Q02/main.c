#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>

int GCD(int a, int b)
{
	return b == 0 ? a : GCD(b, a % b);
}

int bin_to_dec(char *a, char *b) 
{
	int num1 = 0, num2 = 0;
	int i;
	for (i = 0; i < strlen(a); i++)
	{
		num1 = (num1 << 1) + (a[i] - '0');
	}
	for (i = 0; i < strlen(b); i++)
	{
		num2 = (num2 << 1) + (b[i] - '0');
	}
	return GCD(num1, num2);
}

int main()
{
	int N, Case = 1;
	scanf("%d", &N);
	while(N--)
	{
		char S1[31] = { 0 };
		char S2[31] = { 0 };
		scanf("%s%s", S1, S2);
		if (bin_to_dec(S1, S2) != 1) 
		{
			printf("Pair #%d: All you need is love!\n", Case++);
		}
		else 
		{
			printf("Pair #%d: Love is not all you need!\n", Case++);
		}
	}
	//printf("Hello world!");
	return 0;
}