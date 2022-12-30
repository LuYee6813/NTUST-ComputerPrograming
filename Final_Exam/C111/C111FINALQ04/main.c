#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include "func.h"

int main()
{
    // Input cases
    int T = 2;

    // Test cases
    char *cases[] = {
        "(0.28,2.8,-2,-5.8),(-10,-9.2,-4.97,-7.86)", // (a,b,c,d),(e,f,g,h)
        "(-2.37,6.1,-2,5),(0.9,4.9,-8.7,-9)",
    };

    // Vector values
    double a, b, c, d;
    double e, f, g, h;

    // Loop through each case
    for (int i = 0; i < T; ++i)
    {
        // Parse vectors from string
        // cases[i] - one line of the input string
        // a - x value of the first vector
        // b - y value of the first vector
        // c - z value of the first vector
        // d - w value of the first vector
        // e - x value of the second vector
        // f - y value of the second vector
        // g - z value of the second vector
        // h - w value of the second vector
        parse(cases[i], &a, &b, &c, &d, &e, &f, &g, &h);

        // Calculate the vector properties and show the result
        // i - case number
        // a - x value of the first vector
        // b - y value of the first vector
        // c - z value of the first vector
        // d - w value of the first vector
        // e - x value of the second vector
        // f - y value of the second vector
        // g - z value of the second vector
        // h - w value of the second vector
        calc_print(i, a, b, c, d, e, f, g, h);
    }

    return 0;
}
