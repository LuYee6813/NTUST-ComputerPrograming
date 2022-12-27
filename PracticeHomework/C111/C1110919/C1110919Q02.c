//印加減乘除算式跟答案
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{	
	float n1,n2,ans;
	scanf("%f",&n1);
	scanf("%f", &n2);

	ans = n1 + n2;
	printf("%.2f + %.2f = %.2f\n", n1 , n2,ans);
	ans = n1 - n2;
	printf("%.2f - %.2f = %.2f\n", n1 , n2,ans);
	ans = n1 * n2;
	printf("%.2f * %.2f = %.2f\n", n1 , n2,ans);
	ans = n1 / n2;
	printf("%.2f / %.2f = %.2f\n", n1 , n2,ans);
	return 0;
}