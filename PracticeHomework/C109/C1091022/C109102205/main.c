#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* input, * output;
    int total, val1, val2;
    char str[100], result[100];
    fopen_s(&input, "input.txt", "r");
    fgets(str, 100, input);
    sscanf_s(str, "%d", &val1);
    fgets(str, 100, input);
    sscanf_s(str, "%d", &val2);
    total = val1 + val2;
    sprintf(result, "%d", total);
    fopen_s(&output, "output.txt", "w+");
    fputs(result, output);
    return 0;
}