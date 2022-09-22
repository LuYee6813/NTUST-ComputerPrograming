#include <stdio.h>
#include <stdlib.h>

int main()
{
	char data[100];
	int changes = 0;
	gets(data);
	scanf_s("%d", &changes);
	int i = 0;
	for (i = 0; i < strlen(data); i++)
	{
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			data[i] = 'a' + (((data[i] - 'a') + changes) % 26);
		}
		else if(data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = 'A' + (((data[i] - 'A') + changes) % 26);
		}
	}
	printf("%s", data);
	return 0;
}