#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    int cents;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    int change;
    int coins;

    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    change = round(dollars * 100);

    printf("Change: %i\n", change);


    while (change >= 25)
    {
        quarters = quarters + 1;
        change = change - 25;
    }
    while (change >= 10 && change < 25)
    {
        dimes = dimes + 1;
        change = change - 10;
    }
    while (change >= 5 && change < 10)
    {
        nickels = nickels + 1;
        change = change - 5;
    }
    while (change >= 1 && change < 5)
    {
        pennies = pennies + 1;
        change = change - 1;
    }

    coins = quarters + dimes + nickels + pennies;

    printf("Quarters used: %i\n", quarters);
    printf("Dimes used: %i\n", dimes);
    printf("Nickels used: %i\n", nickels);
    printf("Pennies used: %i\n", pennies);
    printf("%i\n", coins);
}




