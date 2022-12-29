#pragma once
#include <stdio.h>
#include <stdlib.h>

// Implement the following functions.

void parse(char* cases, float* a, float* b, float* c, float* d, float* e, float* f)
{
    char Record[6][10] = { 0 };
    int Yarray = 0, Xarray = 0;
    for (int i = 0; i <= 100; i = i + 1) {
        if (cases[i] != '(' && cases[i] != ')' && cases[i] != ',') {
            Record[Yarray][Xarray] = cases[i];
            Xarray = Xarray + 1;
        }
        if (cases[i] == ',') {
            Yarray = Yarray + 1;
            Xarray = 0;
        }
        if (cases[i] == '\0') {
            break;
        }
    }
    int k = 0;
    switch (k) {
    case 0:
        *a = atof(Record[k]);
        k = k + 1;
    case 1:
        *b = atof(Record[k]);
        k = k + 1;
    case 2:
        *c = atof(Record[k]);
        k = k + 1;
    case 3:
        *d = atof(Record[k]);
        k = k + 1;
    case 4:
        *e = atof(Record[k]);
        k = k + 1;
    case 5:
        *f = atof(Record[k]);
        break;
    }
}

void calc_print(int i, float a, float b, float c, float d, float e, float f)
{
    printf("Case %d:\n", i + 1);
    printf("  Addition: (%.2f,%.2f,%.2f)\n", a + d, b + e, c + f);
    printf("  Subtraction: (%.2f,%.2f,%.2f)\n", a - d, b - e, c - f);
    printf("  Dot: %.2f\n", a * d + b * e + c * f);
}