#include <stdio.h>
#include <stdlib.h>

int main()
{
	int count = 0, i = 0, j = 0, z = 0, length = 0;
	int matrix[10000];
	int answer[100];
	scanf_s("%d", &count);
	for (i = 0; i < count; i++) {
		int n = 0;
		char temp[100];
		scanf_s("%s", &temp, 100);
		scanf_s("%s", &temp, 100);
		scanf_s("%d", &length);
		for (j = 0; j < length; j++)
			for (z = 0; z < length; z++)
				scanf_s("%d", &matrix[n++]);
		int notOk = 0;
		for (j = 0; j < n; j++)
			if (matrix[j] != matrix[n - 1 - j])
			{
				notOk = 1;
				break;
			}
		answer[i] = notOk;
	}
	for (i = 0; i < count; i++)
	{
		if (answer[i] == 1)
			printf("Test #%d: Non-symmetric.", (i + 1));
		else
			printf("Test #%d: Symmetric.", (i + 1));
		if (i != count - 1)
			printf("\n");
	}
	return 0;
}