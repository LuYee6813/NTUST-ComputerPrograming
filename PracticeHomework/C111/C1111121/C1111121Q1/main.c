#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
void path(int YPathEnter, int XPathEnter, int(*reMazeMap)[16], int Array, int FinalXnumber);
int main()
{
    char MazeMap[15][16] = { 0 }, input;
    int Ynumber = 0, Xnumber = 0, YEnter, XEnter = 1, Path = 0, reMazeMap[15][16] = { 0 };
    while (1) {
        input = getchar();
        if (input != '\n') {
            MazeMap[Ynumber][Xnumber] = input;
            Xnumber = Xnumber + 1;
        }
        if (input == '\n') {
            Ynumber = Ynumber + 1;
            Xnumber = 0;
        }
        if (Ynumber == 15) {
            Ynumber = 0;
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
            Ynumber = i - 1;
            break;
        }
        if (MazeMap[i - 1][14] == '#') {
            Path = Path + 1;
        }
    }

    if (Path == 15) {
        printf("This maze has no solution");
    }
    if (Path != 15) {
        path(YEnter, 0, reMazeMap, 15, Ynumber);
    }
    return 0;
}
void path(int YPathEnter, int XPathEnter, int(*reMazeMap)[16], int Array, int FinalXnumber) {
    int count = 0;
    if (YPathEnter == FinalXnumber && XPathEnter == 14) {
        printf("This maze has a solution");
    }
    reMazeMap[YPathEnter][XPathEnter] = 2;
    if (reMazeMap[YPathEnter - 1][XPathEnter] == 0 && (YPathEnter - 1 >= 0)) {
        path(YPathEnter - 1, XPathEnter, reMazeMap, 15, FinalXnumber);
    }
    else {
        count = count + 1;
    }
    if (reMazeMap[YPathEnter][XPathEnter + 1] == 0 && (XPathEnter + 1 < 15)) {
        path(YPathEnter, XPathEnter + 1, reMazeMap, 15, FinalXnumber);
    }
    else {
        count = count + 1;
    }
    if (reMazeMap[YPathEnter + 1][XPathEnter] == 0 && (YPathEnter + 1 < 15)) {
        path(YPathEnter + 1, XPathEnter, reMazeMap, 15, FinalXnumber);
    }
    else {
        count = count + 1;
    }
    if (reMazeMap[YPathEnter][XPathEnter - 1] == 0 && (XPathEnter - 1 >= 0)) {
        path(YPathEnter, XPathEnter - 1, reMazeMap, 15, FinalXnumber);
    }
    else {
        count = count + 1;
    }
    if (count == 4) {
        if (reMazeMap[YPathEnter - 1][XPathEnter] == 2) {
            reMazeMap[YPathEnter][XPathEnter] = -1;
            path(YPathEnter - 1, XPathEnter, reMazeMap, 15, FinalXnumber);
        }
        if (reMazeMap[YPathEnter][XPathEnter + 1] == 2) {
            reMazeMap[YPathEnter][XPathEnter] = -1;
            path(YPathEnter, XPathEnter + 1, reMazeMap, 15, FinalXnumber);
        }
        if (reMazeMap[YPathEnter + 1][XPathEnter] == 2) {
            reMazeMap[YPathEnter][XPathEnter] = -1;
            path(YPathEnter + 1, XPathEnter, reMazeMap, 15, FinalXnumber);
        }
        if (reMazeMap[YPathEnter][XPathEnter - 1] == 2) {
            reMazeMap[YPathEnter][XPathEnter] = -1;
            path(YPathEnter, XPathEnter - 1, reMazeMap, 15, FinalXnumber);
        }
    }
}

