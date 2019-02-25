// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents number of children for each node in a trie
#define N 27

// Maximum length of a word
// The longest word in the English language contains 45 letters.
#define MAX_LENGTH 45

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
// node *children[N];


int get_index(const char c);

void free_nodes(node* nav);

// Counter for number of valid words in dictionary stored in trie
unsigned int num_words = 0;

// Get the index of char in word
int get_index(const char c)
{
    // if (c == '\'')
    // {
    //     return 26;
    // }
    if (c >= 'a' && c <= 'z')
    {
        return c - 'a';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return c - 'A';
    }
    else
    {
        return 26;
    }
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize trie
    // root = malloc(sizeof(node));
    root = calloc(1, sizeof(node));
    // // If empty trie
    // if (root == NULL)
    // {
    //     return false;
    // }
    // root->is_word = false;
    // Initialize all nodes to NULL
    // memset(root, 0, sizeof(node));
    // for (int i = 0; i < N; i++)
    // {
    //     root->children[i] = NULL;
    // }
    num_words = 0;
    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open dictionary %s.\n", dictionary);
        unload();
        return false;
    }

    // Buffer for a word
    // char word[LENGTH + 1];

    // Insert words into trie

    node* nav = root;

    // char ch;

    // int index = 0;

    for (int c = fgetc(file); c != EOF; c = fgetc(file))
    {

        // While there are words in the dictionary
        //    for each word in dictionary, read each character
        //       If end of word (check for end of line or terminating character)
        //          set is_word to true
        //          break out of loop - we are done with this word
        //          go to next word in dict
        //       If no more words
        //          break out of loop - we are done with function
        //       While there are characters in word (no terminating cases met)
        //          If path not yet created (character not yet used at this index)
        //              Create a new node for character
        //          If path already exists (character at index already used)
        //              Move nav to the node. No need to create new node as node already created and filled
        //

        if (c == '\n')
        {
            nav->is_word = true;
            num_words++;
            nav = root; // reset nav ptr to root to go through trie again
           // continue;
        }
        else
        {
            int index = get_index(c);
            // Check if path exists for letter
            if (nav->children[index] == NULL)
            {
                // Create new node for character
                // printf("%i\n", index);
                // nav->children[index] = malloc(sizeof(node));
                nav->children[index] = calloc(1, sizeof(node));
            // newNode = children[i]->newNode;
            // nav = nav->children[index];
            // continue;
            }
            // Move to next node
            nav = nav->children[index];
        }
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (&load)
    {
        return num_words;
    }
    else
    {
        return 0;
    }
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // case-insensitive
    // Assumes strings with only alphabetical chars
    // and/or apostrophes

    // If word exists, word should be found in trie

    // Traverse the dictionary trie
    // For each letter in input word
    //      go to corresponding element in children

    node* nav = root;

    for(int i = 0; word[i] != '\0'; i++)
    {
        int index = get_index(word[i]);

        if(nav->children[index] == NULL)
        {
            return false;
        }

        nav = nav->children[index];
    }

    return nav->is_word;
    // return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    free_nodes(root);
    return true;
}

// Helper function to recursively free nodes from trie.
void free_nodes(node* nav)
{
    for (int i = 0; i < N; i++)
    {
        if (nav->children[i] != NULL)
        {
            free_nodes(nav->children[i]);
        }
    }

    free(nav);
}

