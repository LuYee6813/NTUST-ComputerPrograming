#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include "func.h"

int main()
{
    // Input cases
    int T = 2;
    
    // Test cases
    char* cases[] = {
        "(1.00,1.00,1.00),(1.50,1.50,1.50)", // (a,b,c),(d,e,f)
        "(2.20,2.20,2.20),(2.30,2.30,2.30)"
    };

    // Vector values
    float a, b, c;
    float d, e, f;

    // Loop through each case
    for (int i = 0; i < T; ++i)
    {
        // Parse vectors from string
        // cases[i] - one line of the input string
        // a - x value of the first vector
        // b - y value of the first vector
        // c - z value of the first vector
        // d - x value of the second vector
        // e - y value of the second vector
        // f - z value of the second vector
        parse(cases[i], &a, &b, &c, &d, &e, &f);

        // Calculate the vector properties and show the result
        // i - case number
        // a - x value of the first vector
        // b - y value of the first vector
        // c - z value of the first vector
        // d - x value of the second vector
        // e - y value of the second vector
        // f - z value of the second vector
        calc_print(i, a, b, c, d, e, f);
    }

    return 0;
}
