// 輸入式加減乘除
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	float n1, n2;
	char op;
	float ans;

	scanf("%f%c%f", &n1, &op, &n2);

	if (op == '+') {
		ans = n1 + n2;
		printf("%.2f+%.2f=%.2f", n1, n2, ans);
	}
	else if (op == '-') {
		ans = n1 - n2;
		printf("%.2f-%.2f=%.2f", n1, n2, ans);
	}
	else if (op == '*') {
		ans = n1 * n2;
		printf("%.2f*%.2f=%.2f", n1, n2, ans);
	}
	else if (op == '/') {
		ans = n1 / n2;
		printf("%.2f/%.2f=%.2f", n1, n2, ans);
	}


	
	return 0;
}