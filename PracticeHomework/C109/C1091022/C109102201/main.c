#include <stdio.h>


int main()
{
	int input;
	scanf("%d", &input);
	int i, ans = 0;
	for (i = 1; i <= input; i++)
		ans += i;
	printf("The Sum of Natural Number upto %d terms : %d", input, ans);
	return 0;
}