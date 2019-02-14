#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool load(const char *dictionary);

int main(void)
{
    printf("Hello\n");
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize trie
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        return false;
    }
    root->is_word = false;
    for (int i = 0; i < N; i++)
    {
        root->children[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        // unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)
    {
        //TODO
        for(int j = 0; j < N; j++)
        {
            if(root)
            {
                root->children[j];
            }
            else
            {
                children[j]->children[j+1];
            }

            if (children[j] == NULL)
            {
                is_word = false;
                break;
            }

        }

    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}