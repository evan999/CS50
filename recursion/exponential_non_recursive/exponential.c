#include <cs50.h>
#include <stdio.h>

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
    int result = 1;
    for (int i = 0; i < exponent; i++)
    {

        if (base == 0)
        {
            return 0;
        }
        if (exponent == 0)
        {
            return 1;
        }
        else if (exponent == 1)
        {
            return base;
        }
        else
        {
            result *= base;
        }
    }

    return result;
}