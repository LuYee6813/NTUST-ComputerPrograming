// n*n矩陣加法
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int n=2, size, temp;
	scanf("%d", &size);
	int arr[81] = { 0 };
	while (n--) {
		for (int i = 0; i < size * size; i++)
		{
			scanf("%d", &temp);
			arr[i] += temp;
		}
	}

	
	for (int i = 0; i < size * size; i++)
	{
		if ((i + 1) % size == 0)
			printf("%d\n", arr[i]);
		else
			printf("%d ", arr[i]);
	}

	return 0;
}