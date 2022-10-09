#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <math.h>

int main()
{
	float n1, n2;
	scanf("%f", &n1);
	scanf("%f", &n2);
	float length, unit1,unit2;
	length = sqrt(pow(n1,2) + pow(n2,2));
	printf("%.2f\n", length);
	unit1 = n1 / length;
	unit2 = n2 / length;
	printf("%.2f %.2f\n", unit1, unit2);
	return 0;
}