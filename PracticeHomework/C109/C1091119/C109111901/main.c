#include <stdio.h>
#define Max 12
char maze[Max][Max];
int flag = 0;
void DFS(int x, int y, int dir) {
	if (x == 11 && y == 10) {
		flag = 1;
		maze[y][x] = 'R';
	}
	if (flag == 1) return;
	int yMove[4] = { 0,-1,0,1 };//右 上 左 下
	int xMove[4] = { 1,0,-1,0 };
	// dir 1 上 3 下 2 左 0 右
	// 下 1,0 上 -1,0 左 0,-1 右 0,1
	//前有右轉 走前 左轉
	int xBuf, yBuf;
	int dir_buf = dir;
	dir = (dir + 3) % 4;
	xBuf = x + xMove[dir];
	yBuf = y + yMove[dir];
	//printf("%d %d", xBuf, yBuf);
	if (xBuf >= 0 && xBuf < Max && yBuf >= 0 && yBuf < Max) {
		if (maze[yBuf][xBuf] == 'X') {
			DFS(xBuf, yBuf, dir);
		}
	}
	dir = dir_buf;
	xBuf = x + xMove[dir];
	yBuf = y + yMove[dir];
	//printf("%d %d", xBuf, yBuf);
	if (xBuf >= 0 && xBuf < Max && yBuf >= 0 && yBuf < Max) {
		if (maze[yBuf][xBuf] == 'X') {
			DFS(xBuf, yBuf, dir);
		}
	}
	dir = dir_buf;
	dir = (dir + 1) % 4;
	xBuf = x + xMove[dir];
	yBuf = y + yMove[dir];
	//printf("%d %d", xBuf, yBuf);
	if (xBuf >= 0 && xBuf < Max && yBuf >= 0 && yBuf < Max) {
		if (maze[yBuf][xBuf] == 'X') {
			DFS(xBuf, yBuf, dir);
		}
	}
	maze[y][x] = 'R';
}
int main()
{
	char buf;
	for (int i = 0; i < Max; i++) {
		for (int j = 0; j < Max; j++) {
			scanf_s("%c", &maze[i][j], 1);
		}
		//if(i!=Max-1)
		scanf_s("%c", &buf, 1);
	}
	DFS(0, 6, 0);
	for (int i = 0; i < Max; i++) {
		for (int j = 0; j < Max; j++) {
			printf("%c", maze[i][j]);
		}
		if (i != Max - 1) printf("\n");
	}
	if (flag == 0) printf("\nThis maze has no solution");
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