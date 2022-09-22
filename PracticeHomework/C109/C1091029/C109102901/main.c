#include <stdio.h>


int main()
{
	int str[10];
	scanf("%d %d %d %d %d %d %d %d %d %d", &str[0], &str[1], &str[2], &str[3], &str[4], &str[5], &str[6], &str[7], &str[8], &str[9]);
	int check[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, j, ans = 0;
	for(i = 0; i < 10; i ++)
		for (j = i + 1; j < 10; j++)
		{
			if (str[i] == str[j])
			{
				if (check[i] == 0)
				{
					check[i] = 1;
					ans += str[i];
				}
				check[j] = 1;
			}
		}
	printf("%d", ans);
	return 0;
}