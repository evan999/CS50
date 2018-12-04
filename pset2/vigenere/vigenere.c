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
        }
    }

    string plaintext = get_string("plaintext: ");
    int key_len = strlen(key);
    // plaintext = p

    printf("ciphertext: ");
    //int CASE;
    for (int plaintext_index = 0, key_index = 0, n = strlen(plaintext); plaintext_index < n; plaintext_index++, key_index++)
    {
        int letterKey = tolower(key[key_index % key_len]) - 'a';
        if (key_index >= key_len)
        {
            key_index = 0;
        }
        if (isupper(plaintext[plaintext_index]))
        {
            //printf("%c", 'A' + (p[i] - 'A' + letterKey) % 26);
            printf("%c", 'A' + (plaintext[plaintext_index] - 'A' + letterKey) % 26);
            key_index++;
           // CASE = 'a';
        }
        else if (islower(plaintext[plaintext_index]))
        {
           printf("%c", 'a' + (plaintext[plaintext_index] - 'a' + letterKey) % 26);
           key_index++;
            // CASE = 'A';
        }

        else
        {
            printf("%c", plaintext[plaintext_index]);
        }

    }
        // else
        // {
        //     printf("%c", p[i]);
        // }

    printf("\n");
    //return 0;
}


            // if (isupper(plaintext[plaintext_index]))
            // {
            //     int key_num = (int) key[key_index];
            //     // printf(" Key num: %i\n", key_num);
            //     int pnum = (int) plaintext[plaintext_index];
            //     // printf("Letter: %i\n", pt_num);
            //     //printf("%i\n", number);

            //     int cipher = ((pnum - 'A') + (key_num - 'A')) % 26;

            //      // c[i] = (p[i] + k[j]) % 26
            //     if(key_index == strlen(key))
            //     {
            //       key_index = 0;
            //     }

            //     printf("%i", cipher);
            //     int ascii_cipher = cipher + 65;
            //     char ascii_char = (char) ascii_cipher;
            //     //printf("%c", ascii_char);
            // }


            // int key_num = (int) ;
            // int pnum = (int) ;
            //printf("key: %i\n", key_num);
            //printf("p: %i\n", pnum);
            // int cipher = ;
            // if(key_index >= strlen(key))
            // {
            //   key_index = 0;
            // }

            // int ascii_cipher = cipher + 97;
            // char ascii_char = (char) ascii_cipher;
            //printf("%c", ascii_char);

