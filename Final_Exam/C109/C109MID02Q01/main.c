#include <stdio.h>


int main()
{
	float a;
	float b;
	scanf_s("%f %f", &a, &b);
	printf("%.2f\n", a + b);
	printf("%.2f\n", a - b);
	printf("%.2f\n", a * b);
	printf("%.2f", a / b);
	return 0;
}