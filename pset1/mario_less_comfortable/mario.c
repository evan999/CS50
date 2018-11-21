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

    // For each row
    for(int i = 1; i <= height; i++)
    {
        int h;
        hashes = i + 1;
        // Print spaces
        //printf(" ");
        // Print hashes
        while(h < hashes)
        {
            printf("#");
            h = h + 1;
        }

        // Print new line
        printf("\n");
    }


}