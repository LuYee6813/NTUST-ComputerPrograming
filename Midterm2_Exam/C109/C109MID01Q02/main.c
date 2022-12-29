#include <stdio.h>


int main()
{
	int f[100] = {0, 1};
	int count = 0;
	scanf_s("%d", &count);
	if (count <= 0)
	{
		printf("Invalid input");
		return;
	}
	int i = 2;
	for (i = 2; i < count + 1; i++)
		f[i] = f[i - 1] + f[i - 2];
	if (count == 1)
	{
		printf("1st Fibonacci number is:%d", f[count]);
	} else if (count == 2)
	{
		printf("2nd Fibonacci number is:%d", f[count]);
	} else if (count == 3)
	{
		printf("3rd Fibonacci number is:%d", f[count]);
	} else 
	{
		printf("%dth Fibonacci number is:%d", count, f[count]);
	}
	return 0;
}