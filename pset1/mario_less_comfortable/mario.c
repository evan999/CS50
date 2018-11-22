#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    int spaces;
    int hashes;
    // Validation - verify that the user entered an integer
    // Otherwise, prompt the user to retry
    do
    {
        height = get_int("Enter the height: ");
    }
    while (height < 0 || height > 23);


    // Draw the half pyramid
    for(int i = 1; i <= height; i++)
    {
        // Print spaces
        spaces = height - i;

        for(int s = 1; s <= spaces; s++)
        {
            printf(" ");
        }

        // Print hashes
        hashes = i + 1;

        for(int h = 1; h <= hashes; h++)
        {
            printf("#");
        }

        // Print new line
        printf("\n");
    }
}