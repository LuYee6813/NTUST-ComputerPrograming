#include <stdio.h>


int main()
{
	int a, b, c, d;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);
	printf("%d", max(a, max(b, max(c, d))));
	return 0;
}

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}