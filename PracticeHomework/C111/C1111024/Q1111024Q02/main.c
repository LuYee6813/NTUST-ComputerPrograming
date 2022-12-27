#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdbool.h>
int main()
{	
	char s[1001] = { 0 };
	gets(s);
	int key;
	int encode;
	int flag = false;
	scanf("%d", &key);
	key %= 26;
	for (int i = 0; s[i]; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z')
		{
			encode = s[i] + key;
			if (encode < 'A') 
			{
				encode += 26;
				printf("%c->%c\n", s[i], encode);
			}
			if (encode > 'Z')
			{
				encode -= 26;
				printf("%c->%c\n", s[i], encode);
			}
			if (encode < 'a')
			{
				encode += 26;
				printf("%c->%c\n", s[i], encode);
			}
			if (encode > 'z')
			{
				encode -= 26;
				printf("%c->%c\n", s[i], encode);
			}
			encode = 0;
		}
		else 
		{
			printf("%c", s[i]);
		}
	}
	return 0;
}