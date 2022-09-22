#include <stdio.h>


int main()
{
	int str[6];
	scanf("%d %d %d %d %d %d", &str[0], &str[1], &str[2], &str[3], &str[4], &str[5]);
	int i, j, temp;
	for (i = 0; i < 6; i++)
		for (j = i + 1; j < 6; j++)
		{
			if (str[i] > str[j])
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	for (i = 0; i < 6; i++)
	{
		printf("%d", str[i]);
		if (i != 5)
			printf(" ");
	}
	return 0;
}