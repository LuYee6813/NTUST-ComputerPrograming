#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	
	int count = 0;
	scanf_s("%d\n", &count);
	int i = 0;
	int ansFirst[100][30];
	int ansSecond[100][30];
	int ansMaxFirstLen[100];
	int ansMaxSecondLen[100];
	int willSmaller[100] = { 0 };
	for (i = 0; i < count; i++)
	{
		char temp;
		int readToWho = 0;
		int readToDigits = 0;
		int symbol = -1;
		int tempInt[30];
		memset(tempInt, 0, sizeof(tempInt));
		int First[2][30];
		memset(First[0], 0, sizeof(First[0]));
		memset(First[1], 0, sizeof(First[1]));
		int Second[2][30];
		memset(Second[0], 0, sizeof(Second[0]));
		memset(Second[1], 0, sizeof(Second[1]));
		int FirstLen[2] = { 0, 0 };
		int SecondLen[2] = { 0, 0 };
		do
		{
			scanf_s("%c", &temp, 1);
			if (temp == '+' || temp == '-')
			{
				int j = 0;
				if (readToDigits == 0) {
					for (j = FirstLen[readToWho] - 1; j >= 0; j--)
					{
						First[readToWho][29 - (FirstLen[readToWho] - 1 - j)] = tempInt[j];
					}
				}
				else {
					for (j = SecondLen[readToWho] - 1; j >= 0; j--)
					{
						Second[readToWho][29 - (SecondLen[readToWho] - 1 - j)] = tempInt[SecondLen[readToWho] - 1 - j];
					}
				}
				memset(tempInt, 0, sizeof(tempInt));
				symbol = temp == '+' ? 1 : 0;
				readToDigits = 0;
				readToWho = 1;
				continue;
			}
			else if (temp == '.')
			{
				int j = 0;
				if (readToDigits == 0) {
					for (j = FirstLen[readToWho] - 1; j >= 0; j--)
					{
						First[readToWho][29 - (FirstLen[readToWho] - 1 - j)] = tempInt[j];
					}
				}
				else {
					for (j = SecondLen[readToWho] - 1; j >= 0; j--)
					{
						Second[readToWho][29 - (SecondLen[readToWho] - 1 - j)] = tempInt[SecondLen[readToWho] - 1 - j];
					}
				}
				memset(tempInt, 0, sizeof(tempInt));
				readToDigits = 1;
				continue;
			}
			else if (temp == '\n')
			{
				int j = 0;
				if (readToDigits == 0) {
					for (j = FirstLen[readToWho] - 1; j >= 0; j--)
					{
						First[readToWho][29 - (FirstLen[readToWho] - 1 - j)] = tempInt[j];
					}
				}
				else {
					for (j = 0; j < SecondLen[readToWho]; j++)
					{
						Second[readToWho][29 - (SecondLen[readToWho] - 1 - j)] = tempInt[(SecondLen[readToWho] - 1 - j)];
					}
				}
				int maxFirstLen = FirstLen[0] > FirstLen[1] ? FirstLen[0] : FirstLen[1];
				int maxSecondLen = SecondLen[0] > SecondLen[1] ? SecondLen[0] : SecondLen[1];
				int borrow = 0;
				
				for (j = 29; j > 29 - maxSecondLen; j--) {
					Second[0][j] = Second[0][j] > 0 ? Second[0][j] : 0;
					Second[1][j] = Second[1][j] > 0 ? Second[1][j] : 0;
				}
				for (j = 29; j > 29 - maxFirstLen; j--) {
					First[0][j] = First[0][j] > 0 ? First[0][j] : 0;
					First[1][j] = First[1][j] > 0 ? First[1][j] : 0;
				}
				for (j = 0; j < 30; j++)
				{
					if (First[0][j] < First[1][j] && willSmaller[i] == 0)
						willSmaller[i] = 1;
					ansFirst[i][j] = 0;
					ansSecond[i][j] = 0;
				}
				
				for (j = 29 - maxSecondLen + 1; j < 30; j++)
				{
					ansSecond[i][j] = Second[0][j] + (symbol == 1 ? Second[1][j] : -Second[1][j]) + (symbol == 1 ? borrow : -borrow);
					borrow = 0;
					if (symbol == 1 && ansSecond[i][j] > 9)
					{
						ansSecond[i][j] -= 10; borrow = 1;
					}
					else if (symbol == 0 && ansSecond[i][j] < 0)
					{
						if (j == 29 && maxFirstLen == 1 && First[0][29] == 0)
						{
							ansSecond[i][j] += 10;
							First[0][0] *= -1;
							willSmaller[i] = 1;
							continue;
						}
						ansSecond[i][j] += 10; borrow = 1;
					}
				}
				for (j = 29; j > 29 - maxFirstLen; j--)
				{
					ansFirst[i][j] = First[0][j] + (symbol == 1 ? First[1][j] : -First[1][j]) + (symbol == 1 ? borrow : -borrow);
					borrow = 0;
					if (symbol == 1 && ansFirst[i][j] > 9)
					{
						ansFirst[i][j] -= 10; borrow = 1;
					}
					else if (symbol == 0 && ansFirst[i][j] < 0)
					{
						
						if (j == 29 - maxFirstLen + 1)
						{
							continue;
						}
						ansFirst[i][j] += 10; borrow = 1;
					}
				}
				if (borrow == 1)
				{
					ansFirst[i][29 - maxFirstLen] = (symbol == 1 ? borrow : -borrow);
					maxFirstLen += 1;
				}
				
				ansMaxFirstLen[i] = maxFirstLen;
				ansMaxSecondLen[i] = maxSecondLen;
				break;
			}
			else {
				if (readToDigits == 0)
				{
					tempInt[FirstLen[readToWho]++] = (int)(temp)-48;
				}
				else {
					tempInt[SecondLen[readToWho]++] = (int)(temp)-48;
				}
			}
		} while (1 == 1);
	}
	for (i = 0; i < count; i++)
	{
		int j = 0;
		int start = 0;
		printf("#%d:", i);
		for (j = 29 - ansMaxFirstLen[i] + 1; j < 30; j++)
			if (ansFirst[i][j] != 0 || j == 29)
			{
				start = j;
				break;
			}
		if (willSmaller[i] == 1)
			printf("-");
		for (j = start; j < 30; j++)
			printf("%d", ansFirst[i][j]);
		if (ansMaxSecondLen[i] != 0)
		{
			printf(".");
			for (j = 29 - ansMaxSecondLen[i] + 1; j < 30; j++)
				if (ansSecond[i][j] != 0)
				{
					start = j;
					break;
				}
			for (j = 29; j >= start; j--)
				printf("%d", ansSecond[i][j]);
		}
		if (i != count - 1)
		{
			printf("\n");
		}
	}
	return 0;
}