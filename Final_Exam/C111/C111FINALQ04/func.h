#pragma once
#include <stdio.h>

// Implement the following functions.

void parse(char cases[], double* a, double* b, double* c, 
    double* d, double* e, double* f, double* g, double* h)
{
    sscanf(cases, "(%lf,%lf,%lf,%lf),(%lf,%lf,%lf,%lf)", a, b, c, d, e, f, g, h);
}

void calc_print(int i, double a, double b, double c,
    double d, double e, double f, double g, double h)
{
    printf("Case %d:\n", i + 1);
    printf("  Addition: (%.2lf,%.2lf,%.2lf,%.2lf)\n", a + e, b + f , c + g, d + h);
    printf("  Subtraction: (%.2lf,%.2lf,%.2lf,%.2lf)\n", a - e, b - f, c - g, d - h);
    printf("  Dot: %.2lf\n", (a * e) + (b * f) + (c * g) + (d * h));
}