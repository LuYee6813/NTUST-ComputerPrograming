// 判斷字串連續累加,不連續累加值歸零
// OOXXOXXOOO
// 1+2+0+0+1+0+0+1+2+3
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>
int main()
{
	char s[101];
	int t = 0;
	scanf("%d\n", &t);
	while (t--)
	{
		int score = 0; 
		int c = 0;
		scanf("%s", &s);
		int length = strlen(s);
		for (int i = 0; i < length; i++) {
			if (s[i] == 'O') {
				c++;
			}
			else {
				c = 0;
			}
			score = score + c;
		}
		printf("%d\n", score);
	}

	return 0;
}