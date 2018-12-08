#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    string key = argv[1];
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    for (int k = 0; k < strlen(key); k++)
    {
        if (!isalpha(key[k]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: ");
    int key_len = strlen(key);
    // plaintext = p

    printf("ciphertext: ");
    //int CASE;
    for (int plaintext_index = 0, key_index = 0, n = strlen(plaintext); plaintext_index < n; plaintext_index++)
    {
        int letterKey = tolower(key[key_index % key_len]) - 'a';

        if (isupper(plaintext[plaintext_index]))
        {
            
            printf("%c", 'A' + (plaintext[plaintext_index] - 'A' + letterKey) % 26);
            key_index++;

        }
        else if (islower(plaintext[plaintext_index]))
        {
            printf("%c", 'a' + (plaintext[plaintext_index] - 'a' + letterKey) % 26);
            key_index++;
        }
        else
        {
            printf("%c", plaintext[plaintext_index]);
        }

    }
    printf("\n");
    return 0;
}


