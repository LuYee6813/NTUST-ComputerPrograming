#include <stdio.h>


int main()
{
	int input = 0;
	scanf("%d", &input);
	if (input < 0)
	{
		printf("It is not an ugly number.");
		return 0;
	}
	while (input != 1)
	{
		if (input % 5 == 0)
		{
			input = input / 5;
			continue;
		}
		if (input % 3 == 0)
		{
			input = input / 3;
			continue;
		}
		if (input % 2 == 0)
		{
			input = input / 2;
			continue;
		}
		printf("It is not an ugly number.");
		return 0;
	}
	printf("It is an ugly number.");
	return 0;
}