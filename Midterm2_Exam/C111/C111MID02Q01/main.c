#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int a, i = 0, reB[100] = { 0 }, big;
	char c, b[100] = { 0 };
	while (1) {
		c = getchar();
		if (c != '\n') {
			b[i] = c;
			reB[i] = c - 'A';
			//printf("%d", reB[i]);
			i = i + 1;
		}
		if (c == '\n') {
			break;
		}
	}
	big = reB[0];
	for (int j = 1; j <= i; j = j + 1) {
		if (reB[j - 1] > big) {
			big = reB[j - 1];
		}
	}
	//printf("%d", big);
	for (int j = 1; j <= i; j = j + 1) {
		for (int k = 1; k <= big - reB[j - 1]; k = k + 1) {
			printf(" ");
		}
		for (int l = 1; l <= 2 * reB[j - 1] + 1; l = l + 1) {
			//printf("%d", l);
			printf("%c", b[j - 1]);
		}
		printf("\n");
	}
	return 0;
}