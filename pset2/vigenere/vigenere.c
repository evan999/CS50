#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    string key = argv[1];
    for (int k = 0; k < strlen(key); k++)
    {
        if (argc != 2 || !isalpha(key[k]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char letter = plaintext[i];

        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                for(int j = 0; j < strlen(key); j++)
                {
                    int key_num = (int) key[i];
                    int number = (int) letter;
                    printf("%i\n", key_num);
                    //printf("%i\n", number);
                    int cipher = (number + key_num % 26) - 65;
                    while (cipher > 25)
                    {
                        cipher = cipher - 26;
                    }
                    //printf("%i\n", cipher);
                    int ascii_cipher = cipher + 65;
                    char ascii_char = (char) ascii_cipher;
                    // printf("%c", ascii_char);
                }

            }
            else if (islower(plaintext[i]))
            {
                for(int j = 0; j < strlen(key); j++)
                {
                    int key_num = (int) key[i];
                    int number = (int) letter;
                    //printf("%i\n", key_num);
                    //printf("%i\n", number);
                    int cipher = (number + key_num % 26) - 65;
                    while (cipher > 25)
                    {
                        cipher = cipher - 26;
                    }
                    //printf("%i\n", cipher);
                    int ascii_cipher = cipher + 65;
                    char ascii_char = (char) ascii_cipher;
                    printf("%c", ascii_char);
                }
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
    //return 0;
}