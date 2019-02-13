#include <stdio.h>

#define CHAR_SIZE 26

typedef struct Trie
{
    int leaf;
    struct Trie* character[CHAR_SIZE];
}
Trie;

int main(void)
{
    printf("Hello\n");
    return 0;
}