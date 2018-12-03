#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    int key = atoi(argv[1]);
    // printf("%i\n", key);

    string plaintext = get_string("plaintext: ");
    //printf("%s\n", plaintext);

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char letter = plaintext[i];

        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {

                int number = (int) letter;
                //printf("%i\n", number);
                int cipher = (number + key % 26) - 65;
                while (cipher > 25)
                {
                    cipher = cipher - 26;
                }
                //printf("%i\n", cipher);
                int ascii_cipher = cipher + 65;
                char ascii_char = (char) ascii_cipher;
                printf("%c", ascii_char);
            }
            else if (islower(plaintext[i]))
            {
                //printf("%c", plaintext[i]);
                int number = (int) letter;
                //printf("%i\n", number);
                int cipher = (number + key % 26) - 97;
                while (cipher > 25)
                {
                    cipher = cipher - 26;
                }
                //printf("%i\n", cipher);
                int ascii_cipher = cipher + 97;
                char ascii_char = (char) ascii_cipher;
                printf("%c", ascii_char);
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}