#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ways[8][2] = {
		{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0},
		{-1, 1},
		{1, -1},
		{-1, -1},
		{1, 1},
	};
	char ans[20][100][100];
	int colAndrow[20][2];
	int count = 0;
	int i = 0, j = 0, z = 0;
	while (1 == 1) {
		int col = 0;
		int row = 0;
		scanf("%d %d", &col, &row);
		colAndrow[count][0] = col;
		colAndrow[count][1] = row;
		if (col == 0 && row == 0)
		{
			break;
		}
		for (i = 0; i < col; i++)
		{
			for (j = 0; j < row; j++) {
				char temp;
				scanf("%c", &temp);
				if(temp == '\n')
					scanf("%c", &temp);
				ans[count][i][j] = temp;
			}
		}
		for (i = 0; i < col; i++)
		{
			for (j = 0; j < row; j++)
			{
				if (ans[count][i][j] == '.') {
					int mine = 0;
					for (z = 0; z < 8; z++) {
						if (i + ways[z][0] >= 0 && i + ways[z][0] <= col && j + ways[z][1] >= 0 && j + ways[z][1] <= row)
						{
							int new_i = i + ways[z][0];
							int new_j = j + ways[z][1];
							if (ans[count][new_i][new_j] == '*')
							{
								mine += 1;
							}
						}
					}
					ans[count][i][j] = '0' + mine;
				}
			}
		}
		count++;
	}
	for (z = 0; z < count; z++) {
		printf("Field #%d:\n", (z + 1));
		for (i = 0; i < colAndrow[z][0]; i++)
		{
			for (j = 0; j < colAndrow[z][1]; j++)
			{
				if (ans[z][i][j] == -1)
				{
					printf("*");
				}
				else
					printf("%c", ans[z][i][j]);
			}
			if (!(z == count - 1 && i == colAndrow[z][0]))
			{
				printf("\n");
			}
		}
		
	}
	return 0;
}