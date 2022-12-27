//字母正三角
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n - i - 2; j++) {
			printf(" ");
		}
		for (int k = 0; k <= i * 2 ; k++) {
			printf("%c", 'A' + i);
		}
		if (i != n - 1) {
			printf("\n");
		}
	}
	return 0;
}