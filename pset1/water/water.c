#include <stdio.h>
#include <cs50.h>

// Prompt and validate user input
// Calculate equivalent bottles
// Print Equivalent bottles

// get_int

// 2. Calculate equivalent bottles

// Prompt user with exact string:
// Minutes: 10
// Bottles: 120

// 1 min = 12 bottles of water
// 2 min = 24 bottles of water
// 3 min = 36 bottles of water
// 4 min = 48 bottles of water
// 5 min = 60 bottles of water

// n min = n * 12 bottles of water

// 3. Print Equivalent bottles

// printf("I have %i pets\n", n);

//printf("Minutes: %i\n Bottles: %i", minutes, bottles);

int main(void)
{
    int bottles;
    int minutes = get_int("Minutes: ");
    bottles = minutes * 12;
    printf("Bottles: %i\n", bottles);
}
