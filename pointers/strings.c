//#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Initializing a string - WITHOUT cs50.h!!!
    char* name= "Evan\0"; // \0 ends the string
    printf("%s\n", name);
    for (int i = strlen(name) - 1; i >= 0; i--)
    {
        printf("%c", name[i]);
    }
    printf("\n");
}