#include <stdio.h>
#include <cs50.h>

// Collatz Conjecture

// Program that calculates how many steps it takes to get back to 1.

int collatz(int n);

int collatz(int n)
{
    if(n == 1)
    {
       return 0;
    }
    else if((n % 2) == 0)
    {
        return 1 + collatz(n/2);
    }
    else
    {
       return 1 + collatz(3*n + 1);
    }
}

int main(void)
{

}