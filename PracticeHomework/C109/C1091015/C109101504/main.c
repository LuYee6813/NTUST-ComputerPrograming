#include <stdio.h>


int main()
{
	char text[12][3] = { "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "E", "X" };
	int rule[] = { 90,85,80,77,73,70,67, 63,60,50,1,0 };
	int ans;
	scanf("%d", &ans);
	for (int i = 0; i < sizeof(rule); i++) {
		if (ans - rule[i] >= 0)
		{
			printf(text[i]);
			break;
		}
	}
	return 0;
}