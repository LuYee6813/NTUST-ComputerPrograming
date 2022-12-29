#include <stdio.h>

int main()
{
	int input = 0;
	scanf_s("%d", &input);
	int i = 0, j = 0, k = 0, count = 0;
	int matrix1[4][4];
	input -= 1;
	int ans[4][4];
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			scanf_s("%d", &matrix1[i][j]);
			ans[i][j] = matrix1[i][j];
		}
	}
	for (count = 0; count < input; count++) {
		int matrix2[4][4];
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
				scanf_s("%d", &matrix2[i][j]);
		}
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
				matrix1[i][j] = ans[i][j];
		}
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
				ans[i][j] = 0;
		}
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				for (k = 0; k < 4; k++)
				{
					ans[i][j] += matrix1[i][k] * matrix2[k][j];
				}
			}
		}
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d", ans[i][j]);
			if (!(j == 4 - 1))
				printf(" ");
		}
		if (!(i == 4 - 1))
			printf("\n");
	}
	return 0;
}