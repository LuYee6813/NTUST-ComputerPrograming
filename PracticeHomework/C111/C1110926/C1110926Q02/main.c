#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <math.h>

int main()
{
	float n1[2][2],addX,addY,subX,subY,result3;
	scanf("%f %f %f %f", &n1[0][0], &n1[0][1], &n1[1][0], &n1[1][1]);

	addX = n1[0][0] + n1[1][0];
	addY = n1[0][1] + n1[1][1];
	printf("%.2f %.2f\n", addX, addY);

	subX = n1[0][0] - n1[1][0];
	subY = n1[0][1] - n1[1][1];
	printf("%.2f %.2f\n", subX,subY);

	result3 = (n1[0][0] * n1[1][0]) + (n1[0][1] * n1[1][1]);
	printf("%.2f\n", result3);

	return 0;
}