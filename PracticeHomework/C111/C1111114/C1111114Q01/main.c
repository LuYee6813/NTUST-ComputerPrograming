// Do not modify this file, everything will be replaced during the judge process.
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

// The function implementations are in this header.
#include "func.h"

int main()
{
    // You may modify these variables for testing.
    float x = 6;
    float y = 9;
    char op = '+';

    float result;

    switch (op)
    {
    case '+':
        add(x, y, &result);
        break;
    case '-':
        subtract(x, y, &result);
        break;
    case '*':
        multiply(x, y, &result);
        break;
    case '/':
        divide(x, y, &result);
        break;
    default:
        break;
    }

    // Show the result
    print_result(x, y, op, result);

    return 0;
}