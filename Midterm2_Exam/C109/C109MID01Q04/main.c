#include <stdio.h>


int main()
{
	int ans[64] = { 0 };
	int count = 0;
	int n = 0;
	scanf_s("%d", &count);
	scanf_s("%d", &n);
	int i = 0;
	int j = 0;
	for (i = 0; i < count; i++) {
		for (j = 0; j < n * n; j++) {
			int temp = 0;
			scanf_s("%d", &temp);
			ans[j] += temp;
		}
	}
	for (j = 0; j < n * n; j++) {
		printf("%d", ans[j]);
		if (j % n != n - 1)
			printf(" ");
		if (j % n == n - 1 && j != n * n - 1)
			printf("\n");
	}
	return 0;
}