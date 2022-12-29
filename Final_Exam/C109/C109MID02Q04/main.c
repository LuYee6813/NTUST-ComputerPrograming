#include <stdio.h>


int main()
{
	float points[10][10];
	int n = 0;
	scanf_s("%d", &n);
	if (!(n >= 1 && n <= 10))
	{
		printf("invalid number of points");
	}
	else {
		int i = 0, j = 0, k = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < 2; j++)
				scanf_s("%f", &points[i][j]);
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (points[i][0] < points[j][0]) {
					float temp[] = { points[i][0], points[i][1] };
					points[i][0] = points[j][0];
					points[i][1] = points[j][1];
					points[j][0] = temp[0];
					points[j][1] = temp[1];
				}
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (points[i][0] == points[j][0] && points[i][1] < points[j][1]) {
					float temp[] = { points[i][0], points[i][1] };
					points[i][0] = points[j][0];
					points[i][1] = points[j][1];
					points[j][0] = temp[0];
					points[j][1] = temp[1];
				}
			}
		}
		printf("Sorted result:\n");
		for (i = 0; i < n; i++)
		{
			printf("%.2f %.2f", points[i][0], points[i][1]);
			if (i != n - 1)
				printf("\n");
		}
	}
	return 0;
}