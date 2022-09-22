#include <stdio.h>

int main()
{
	int input = 9;
	
	int i = 0, j = 0, k = 0;
	int matrix1[3][3];
	int matrix2[3][3];
	int ans[3][3];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			scanf("%d", &matrix1[i][j]);
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			scanf("%d", &matrix2[i][j]);
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			ans[i][j] = 0;
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				ans[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d", ans[i][j]);
			if (!(j == 3 - 1))
				printf(" ");
		}
		if (!(i == 3 - 1))
			printf("\n");
	}
	return 0;
}