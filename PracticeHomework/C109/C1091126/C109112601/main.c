#include <stdio.h>
#include <math.h>

int main()
{
	long int a, b;
	long int c[10000];
	char temp[30];
	int n = 0, i = 0;
	scanf_s("%d\n", &n);
	for (i = 0; i < n; i++) {
		gets(&temp);
		a = strtol(temp, NULL, 2);
		gets(&temp);
		b = strtol(temp, NULL, 2);
		c[i] = gcd(a, b);
	}
	for (i = 0; i < n; i++) {
		printf("Pair #%d: ", (i + 1));
		if (c[i] == 1)
			printf("Love is not all you need!");
		else
			printf("All you need is love!");
		if (i != n - 1)
			printf("\n");

	}
}
int gcd(int a, int b) {
	int c = 0;
	while (a && b) {
		if (!(a & 1) && !(b & 1)) {
			a >>= 1, b >>= 1, c++;
		}
		else if (!(a & 1)) a >>= 1;
		else if (!(b & 1)) b >>= 1;
		else if (a > b) a -= b;
		else b -= a;
	}

	return (a > b ? a : b) << c;
}