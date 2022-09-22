#include <stdio.h>


int main()
{
	int input;
	scanf("%d", &input);
	printf("%d layer pyramid:\n", input);
	int i, j;
	for (i = 1; i <= input; i++)
	{
		for (j = 1; j <= input - i; j++)
			printf(" ");
		for (j = 1; j <= i; j++)
		{
			printf("*");
			if (j != i)
				printf(" ");
		}
		if (i != input)
			printf("\n");
	}
	return 0;
}