#include <stdio.h>


int main()
{
	float a = 0, b = 0;
	scanf("%f%f", &a, &b);
	float c = a * b;
	printf("%.2f * %.2f = %.2f", a, b, c);
	return 0;
}