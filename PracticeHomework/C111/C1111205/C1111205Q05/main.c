#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#define _HAS_PATH 0
#define _WALL 1
#define _WALKED_PATH 2
#define _IS_WALL -1
#define _TEST_STRING "This Is Test String"
int turn(int dir, char way);
int move(int dir);
int isWall(int p, int  YPathEnter, int XPathEnter, int(*reMazeMap)[16], int Array);
int isExit(int Y, int X, int FinalY, int First);
void path(int YPathEnter, int XPathEnter, int(*reMazeMap)[16], int Array, int FinalX, char(*MazeMap)[16], int AArray);

int main()
{
    char MazeMap[15][16] = { 0 }, input;
    int Y = 0, X = 0, YEnter, XEnter = 1, Path = 0, reMazeMap[15][16] = { 0 };
    while (1) {
        input = getchar();
        // \n >> CRLS .   _CRLS '\n'
        if (input != '\n') {
            MazeMap[Y][X] = input;
            X = X + 1;
        }
        if (input == '\n') {
            Y = Y + 1;
            X = 0;
        }
        if (Y == 15) {
            Y = 0;
            break;
        }
    }

    for (int i = 1; i <= 15; i = i + 1) {
        if (MazeMap[i - 1][0] == 'X') {
            YEnter = i - 1;
            break;
        }
    }

    for (int i = 1; i <= 15; i = i + 1) {
        for (int j = 1; j <= 15; j = j + 1) {
            if (MazeMap[i - 1][j - 1] == '#') {
                reMazeMap[i - 1][j - 1] = -1;
            }
            if (MazeMap[i - 1][j - 1] == 'X') {
                reMazeMap[i - 1][j - 1] = 0;
            }
        }
    }

    for (int i = 1; i <= 15; i = i + 1) {
        if (MazeMap[i - 1][14] == 'X') {
            Y = i - 1;
            break;
        }
        if (MazeMap[i - 1][14] == '#') {
            Path = Path + 1;
        }
    }

    path(YEnter, 0, reMazeMap, 15, Y, MazeMap, 16);
    return 0;
}
int turn(int dir, char way) {
    switch (way) {
    case 'R':
        dir = dir + 1;
        break;
    case 'L':
        dir = dir - 1;
        break;
    }
    if (dir > 4) {
        dir = 1;
    }
    if (dir < 1) {
        dir = 4;
    }
    return dir;
}
int move(int dir) {
    int p = 1;
    switch (dir) {
    case 1:
        p = 1;
        break;
    case 2:
        p = 2;
        break;
    case 3:
        p = 3;
        break;
    case 4:
        p = 4;
        break;
    }
    return  p;
}
int isWall(int p, int  YPathEnter, int XPathEnter, int(*reMazeMap)[16], int Array) {
    switch (p) {
    case 1:
        XPathEnter = XPathEnter + 1;
        break;
    case 2:
        YPathEnter = YPathEnter + 1;
        break;
    case 3:
        XPathEnter = XPathEnter - 1;
        break;
    case 4:
        YPathEnter = YPathEnter - 1;
        break;
    }
    if (reMazeMap[YPathEnter][XPathEnter] == _IS_WALL) {//-1
        return _WALL;//1
    }
    if (reMazeMap[YPathEnter][XPathEnter] == 2) {//-2
        return _WALKED_PATH;//2
    }
    else {
        return _HAS_PATH;//0
    }
}
int isExit(int Y, int X, int FinalY, int First) {
    if (Y == FinalY && X == 14) {
        return 1;
    }
    if (Y == First && X == 0) {
        return 2;
    }
    else {
        return 0;
    }
}
void path(int YPathEnter, int XPathEnter, int(*reMazeMap)[16], int Array, int FinalX, char(*MazeMap)[16], int AArray) {
    //char way;
    int dir = 1;
    int p;
    int a = YPathEnter;
    reMazeMap[YPathEnter][XPathEnter] = 2;
    MazeMap[YPathEnter][XPathEnter] = 'R';
    XPathEnter = XPathEnter + 1;
    reMazeMap[YPathEnter][XPathEnter] = 2;
    while (isExit(YPathEnter, XPathEnter, FinalX, a) == 0) {
        if (isWall(move(turn(dir, 'R')), YPathEnter, XPathEnter, reMazeMap, Array) == _HAS_PATH) {
            dir = turn(dir, 'R');
            continue;
        }
        if (isWall(dir, YPathEnter, XPathEnter, reMazeMap, Array) == 0) {
            p = move(dir);
            reMazeMap[YPathEnter][XPathEnter] = 2;
            MazeMap[YPathEnter][XPathEnter] = 'R';
            switch (p) {
            case 1:
                XPathEnter = XPathEnter + 1;
                break;
            case 2:
                YPathEnter = YPathEnter + 1;
                break;
            case 3:
                XPathEnter = XPathEnter - 1;
                break;
            case 4:
                YPathEnter = YPathEnter - 1;
                break;
            }
            continue;
        }
        if (isWall(dir, YPathEnter, XPathEnter, reMazeMap, Array) == 2) {
            p = move(dir);
            reMazeMap[YPathEnter][XPathEnter] = -1;
            MazeMap[YPathEnter][XPathEnter] = 'R';
            switch (p) {
            case 1:
                XPathEnter = XPathEnter + 1;
                break;
            case 2:
                YPathEnter = YPathEnter + 1;
                break;
            case 3:
                XPathEnter = XPathEnter - 1;
                break;
            case 4:
                YPathEnter = YPathEnter - 1;
                break;
            }
            continue;
        }
        else {
            dir = turn(dir, 'L');
            continue;
        }
    }
    if (isExit(YPathEnter, XPathEnter, FinalX, a) == 1) {
        MazeMap[FinalX][14] = 'R';
        for (int i = 1; i <= 15; i = i + 1) {
            printf("%s\n", MazeMap[i - 1]);
        }
        printf("This maze has a solution");
    }
    if (isExit(YPathEnter, XPathEnter, FinalX, a) == 2) {
        for (int i = 1; i <= 15; i = i + 1) {
            printf("%s\n", MazeMap[i - 1]);
        }
        printf("This maze has no solution");
    }
}