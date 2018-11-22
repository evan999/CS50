TODO:

-Prompt user for an amount of change
-Always use the largest coin possible
-Keep track of coins used
    -How many coins returned to the user
    -Change remaining
-Print final number of coins

get_float

float n;

do
{
    n = get_float();
}
while (n is invalid);

Convert dollars to cents

-Input is a value in dollars
-convert: 1$ = 100 cents
-floating point imprecision
-round

Pseudocode:

get amount in dollars
while(quarters can be used)
    increase count
    decrease amount by a quarter
while(dimes can be used)
    increase count
    decrease amount by a dime
...
print number of coins used
