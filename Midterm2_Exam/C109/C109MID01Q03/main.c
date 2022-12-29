#include <stdio.h>


int main()
{
	int ans[9] = {0,0,0,0,0,0,0,0,0};
	int count = 0;
	scanf_s("%d", &count);
	int i = 0;
	int j = 0;
	for (i = 0; i < count; i++) {
		for (j = 0; j < 9; j++) {
			int temp = 0;
			scanf_s("%d", &temp);
			ans[j] += temp;
		}
	}
	for (j = 0; j < 9; j++) {
		printf("%d", ans[j]);
		if (j % 3 != 2)
			printf(" ");
		if (j % 3 == 2 && j != 8)
			printf("\n");
	}
	return 0;
}