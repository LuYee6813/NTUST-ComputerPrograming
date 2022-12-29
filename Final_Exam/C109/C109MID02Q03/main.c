#include <stdio.h>
int main()
{
	int direction = 0;
	int walkWays[4][2] = {
		{0, 1},  // RIGHT
		{1, 0},  // DOWN
		{0, -1}, // LEFT
		{-1, 0}, // TOP
	};
	char maze[12][12];
	int i = 0, j = 0;
	int start[2] = { 0, 0 };
	int realStart = 0;
	for (i = 0; i < 12; i++)
		for (j = 0; j < 12; j++) {
			char temp;
			scanf_s("%c", &temp, 1);
			if (temp == '\n')
				scanf_s("%c", &temp, 1);
			if (temp == 'X' && j == 0)
			{
				start[0] = i;
				realStart = i;
			}
			maze[i][j] = temp;
		}
	maze[start[0]][start[1]] = 'R';
	int correct = 1;
	while (1) {
		while (maze[start[0] + walkWays[direction][0]][start[1] + walkWays[direction][1]] == '#')
			if (start[0] + walkWays[direction][0] >= 0 && start[0] + walkWays[direction][0] < 12 && start[1] + walkWays[direction][1] >= 0 && start[1] + walkWays[direction][1] < 12)
				direction = direction + 1 > 3 ? 0 : direction + 1;
		start[0] += walkWays[direction][0];
		start[1] += walkWays[direction][1];
		maze[start[0]][start[1]] = 'R';
		if (start[0] == realStart && start[1] == 0)
		{
			correct = 0;
			break;
		}
		if (start[1] == 11)
			break;
		direction = direction - 1 < 0 ? 3 : direction - 1;
	}
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 12; j++)
			printf("%c", maze[i][j]);
		if (i != 11)
			printf("\n");
	}
	if (correct == 0)
		printf("\nThis maze has no solution");
}
/*
############
##XXXXX#XXX#
##X###X###X#
##X#XXXXXXX#
##X#######X#
#XX#X####XX#
XX##XXXXXX##
####X##X##X#
#X#X#XXX##X#
#X#X##X#XXX#
#XXX##XXX#XX
############
*/