#include <stdio.h>


int main()
{
	int count = 0;
	scanf_s("%d", &count);
	if (count < 2 || count > 20)
	{
		printf("Invalid input");
		return;
	}
	int i = 0, j = 0, z = 0;
	int start = 1;
	for (i = 0; i < count + (count - 1); i++) {
		for (j = 0; j < (count - 1 - (start / 2)); j++)
			printf(" ");
		for (j = 0; j < start; j++)
			printf("*");
		start += (i >= count - 1 ? -2 : 2);
		if(i != count + (count - 2))
			printf("\n");
	}
	return 0;
}