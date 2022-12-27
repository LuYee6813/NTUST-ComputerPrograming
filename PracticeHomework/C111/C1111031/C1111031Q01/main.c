#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	//input
	//5
	//22 37 19 11 38

	//output
	//11 19 22 37 38


	int n,i,j;
	int arr[1001];
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
		
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			// 大到小
			//if (arr[j] < arr[j+1])
			//{
			//	int temp = 0;
			//	temp = arr[j];
			//	arr[j] = arr[j + 1];
			//	arr[j+1] = temp;
			//}

			//小到大
			if (arr[j] > arr[j+1])
			{
				int temp = 0;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (j = 0; j < n; j++)
	{
		printf("%d", arr[j]);
		if (j != n - 1) printf(" ");
	}

	return 0;
}