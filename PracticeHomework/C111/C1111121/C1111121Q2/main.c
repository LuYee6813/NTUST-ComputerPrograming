#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include<stdio.h>
int main() {
    int n, m;
    int count = 1;
    char tmp;
    while (scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0) break;
        else if (count > 1) printf("\n");
        int map[102][102] = { 0 };
        int danZone[102][102] = { 0 };
        for (int i = 1; i <= n; i++) {
            getchar();
            for (int j = 1; j <= m; j++) {

                scanf("%c", &tmp);
                if (tmp == '*') {
                    map[i][j] = 1;
                }
                else
                    map[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (map[i][j] == 1) {
                    for (int a = -1; a <= 1; a++)
                        for (int b = -1; b <= 1; b++) {
                            if (map[i + a][j + b] != 1)
                                danZone[i + a][j + b]++;
                        }
                }
            }
        }
        printf("Field #%d:\n", count);
        count++;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (map[i][j] == 1) printf("*");
                else printf("%d", danZone[i][j]);
            }
            printf("\n");
        }


    }
    return 0;
}