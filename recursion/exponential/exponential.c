#include <cs50.h>
#include <stdio.h>

// Exponential Math
// A recursive function that
// takes two inputs, a base and an exponent,
// and applies the equation y^x = y * y^x-1
// to calculate the result.

int exponentiate(int, int);

int main(void)
{
    int base = get_int("Base: ");
    int exponent = get_int("Exponent: ");
    int result = exponentiate(base, exponent);
    printf("%i\n", result);
}

int exponentiate(int base, int exponent)
{
    if (base == 0)
    {
        return 0;
    }
    else if (exponent == 0)
    {
        return 1;
    }
    else if (exponent == 1)
    {
        return base;
    }
    else
    {
        return base*exponentiate(base, exponent - 1);
    }
}

