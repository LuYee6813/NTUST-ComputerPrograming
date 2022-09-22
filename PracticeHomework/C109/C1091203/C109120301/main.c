#include <stdio.h>


int main()
{
	int num = 0;
	scanf_s("%d", &num);
	if (isPrime(num) == 0)
	{
		printf("%d is not prime.", num);
	}
	else {
		int reverseNum = 0;
		int tempNum = num;
		while (tempNum != 0) {
			reverseNum = reverseNum * 10 + (tempNum % 10);
			tempNum = tempNum / 10;
		}
		if (isPrime(reverseNum) == 1) {
			printf("%d is emirp.", num);
		}
		else {
			printf("%d is prime.", num);
		}
	}
	return 0;
}
int isPrime(int num) {
	if (num < 2)
	{
		return 0;
	}
	int i = 0;
	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return 0;
		}
	}
	return 1;
}