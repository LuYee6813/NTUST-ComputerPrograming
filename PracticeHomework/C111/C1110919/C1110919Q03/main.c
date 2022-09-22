#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{	
	int a, c;
	char b[10];
	scanf("%d",&a);
	scanf("%s", b);
	scanf("%d", &c);
	printf("%d %s %d", a, b, c);
	return 0;
}