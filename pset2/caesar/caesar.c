#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    int key = atoi(argv[1]);
    // printf("%i\n", key);

    string plaintext = get_string();
    // printf("%s\n", plaintext);

    // int ciphertext[strlen(plaintext)];


    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char letter = plaintext[i];

        if(isalpha(plaintext[i]))
        {
            if(isupper(plaintext[i]))
            {
                int number = (int) letter;
                int cipher = number + key % 26;
                printf("%i\n", cipher);
            }
            else if(islower(plaintext[i]))
            {
                int number = (int) letter;
                printf("%i\n",  cipher);
            }
            // printf("%c", plaintext[i]);
        }

    }
}