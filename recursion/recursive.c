#include <cs50.h>
#include <stdio.h>

long long fact(int num); // could also be written int fact(int);

long long fib(int num);

int main(void)
{
    //5!
    long long result = fact(20);
    //printf("20! = %lld\n", result);
    long long result2 = fib(40);
    printf("40th position of fibonnacci is: %lld\n", result2);
}

long long fib(int num)
{
    // Base case: if 1 or 0 return 1 or 0
    if (num <= 1)
    {
        return num;
    }
    return fib(num - 1) + fib(num - 2);
}

long long fact(int num)
{
    // Base case
    if(num <= 1)
    {
        return num;
    }
    // Recursive case
    return num * fact(num - 1);

}

// Note: Recursion calls use more memory as it takes a lot of memory to make a function call.
// They are able to save state, however.