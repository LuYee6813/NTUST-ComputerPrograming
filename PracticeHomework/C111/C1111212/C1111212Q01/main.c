// n*n�x�}���k
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int n;
	int arr1[9][9], arr2[9][9], res[9][9] = {0};
	scanf("%d", &n);

	//�s�Ĥ@��n*n�}�C
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}

	//�s�ĤG��n*n�}�C
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr2[i][j]);
		}
	}

	//�x�}���k�B��
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				res[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", res[i][j]);
			if (j != n - 1)
			{
				printf(" ");
			}
		}
		if (i != n - 1)
		{
			printf("\n");
		}	
	}
	return 0;
}