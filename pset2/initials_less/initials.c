#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string();

    for (int i = 0; i < strlen(name); i++)
    {

        if (i == 0)
        {
            printf("%c", toupper(name[i]));
        }
        else if ((int) name[i - 1] == 32)
        {
            printf("%c", toupper(name[i]));
        }
        else
        {
            continue;
        }
    }
    printf("\n");
}