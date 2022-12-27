#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#include <stdio.h>

char* temp;
char s[200];

int isEmpty(char* s) {
    if (s[0] == '\0') {
        return 1;
    }
    return 0;
}

int input(char s[]) {
    int ptr = 0;
    char c = getchar();
    while (c != '\n') {
        s[ptr] = c;
        ptr++;
        c = getchar();
    }
    s[ptr] = '\0';

    return ptr;
}

int lenth(char s[]) {
    int ptr = 0;
    while (s[ptr] != '\0') ptr++;
    return ptr;
}

void output(int n) {
    int len = lenth(s);
    int ptr = 0;

    for (int i = 0; i < len; i++) {
        if (i + ptr < len) {
            int bad = 0;
            for (int j = i; j <= i + ptr; j++) {
                if (s[j] == ' ') {
                    bad = 1;
                }
            }
            if (!bad) {
                printf("%c", s[i + ptr]);
                ptr++;
            }
        }
        while (s[i] != ' ') i++;
    }
    printf("\n");
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    getchar();

    for (int i = 0; i < T; i++) {
        int ptr = 0;
        printf("Case #%d:\n", i + 1);
        while (1) {
            input(s);
            if (isEmpty(s) == 1) break;
            output(i + 1);
        }
        printf("\n");
    }




    return 0;
}