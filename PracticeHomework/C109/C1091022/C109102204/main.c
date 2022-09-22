#include <stdio.h>


int main()
{
    int ans = 0;
    char buffer;
    do {
        scanf("%c", &buffer);
        if (buffer == '\n')
            break;
        if (buffer == '1') ans = ans * 2 + 1;
        else if (buffer == '0') ans *= 2;
    } while (buffer != '\n');
    printf("%d", ans);
    return 0;
}