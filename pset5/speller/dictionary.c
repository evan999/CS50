// Implements a dictionary's functionality

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
        unload();
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
        struct node* nav = root;
        // Check for word
        for (int letter = 0; letter < N; letter++)
        {
            if (children[letter]->data == NULL)
            {
                newNode = malloc(sizeof(node));
                children[letter]->newNode;
            }
            else
            {
                // Node already created. Place letter in this node and continue
                nav->newNode;
                continue;
            }

            if (root == NULL)
            {
                root->is_word = false;
                return;
            }

            if (nav->children[letter] == NULL)
            {
                node->is_word = false;
                return;
            }
        }

        newNode->is_word = true;
        // continue to next word in dictionary
        return;

    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
