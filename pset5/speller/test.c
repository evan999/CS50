#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents number of children for each node in a trie
#define N 27

// Represents a node in a trie
typedef struct node
{
    bool is_word;
    struct node *children[N];
}
node;

// Represents a trie
// Root of a trie
node *root;
node *children[N];

int main(void)
{
    printf("Hello\n");
    load();
    return 0;
}


// Loads dictionary into memory, returning true if successful else false
void load(const char *dictionary)
{
    // Initialize trie
    root = malloc(sizeof(node));

    // If empty trie
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
        // TODO
        /*
        if node is NULL, set is_word to false
        break out of loop. We have reached the last letter and it is not a valid word.
        */
        // struct node* nav = root;
        // Check for word
        node* nav = root;

        // root->children[i] = newNode; // ???

        for (int i = 0; i < N; i++)
        {
            if (nav->children[i] == NULL)
            {
                // Create new node for character
                nav->children[i] = malloc(sizeof(node));
                // newNode = children[i]->newNode;
                nav = nav->children[i];
            }
            else
            {
                // Node already created. Move to node and continue down the word (array)
                nav = nav->children[i];
                continue;
            }
        }

        nav->is_word = true;
        // continue to next word in dictionary
        // return;
        return true;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}


// Loads dictionary into memory, returning true if successful else false
