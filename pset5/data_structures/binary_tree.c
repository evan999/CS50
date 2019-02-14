#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <assert.h>

typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;

typedef struct BinaryNode
{
    int data;
    struct BinaryNode *small;
    struct BinaryNode *large;
} BinaryNode;

void add(int data);
int seek(int data); // true 1 or false 0 if item exists in tree

// void test_tree()
// {
//     add(5);
//     assert(seek(5) == 1 && "tree contains the number 5"); // modify the true to use seek

//     add(3);
//     add(4);
//     assert(seek(9) == 0 && "tree does not contain 9");
//     // assert(true); // modify the true to use seek
// }

// Initialize root node to NULL
//BinaryNode* root = NULL;

int main(void)
{
    printf("Hello\n");
    // add(5);
    // add(5);
    printf("%i\n", add(5));

//    printf("Add element: %i\n", add(5));

    // int data[] = {5, 8, 2, 9, 4, 1, 3};
    // struct BinaryNode *root = add(5);
    // test_tree();




    // Initialize left and right child nodes to NULL
    // BinaryNode->left = NULL;
    // BinaryNode->right = NULL;


}

void add(int data)
{
    // BinaryNode* root = malloc(sizeof(BinaryNode));
    struct BinaryNode* root = NULL;
    root = malloc(sizeof(BinaryNode));

    BinaryNode* newNode = malloc(sizeof(BinaryNode));
    newNode->data = data;
    newNode->small = NULL;
    newNode->large = NULL;

    // If empty tree
    if (root == NULL)
    {
        root = newNode;
        return;
    }

    while (newNode->small == NULL && newNode->large == NULL)
    {
        if (data < root->data && newNode->small != NULL)
        {
            newNode->small->data = data;
            return;
        }
        else if (data > root->data && newNode->large != NULL)
        {
            newNode->large->data = data;
            return;
        }
        else
        {
            continue;
        }
    }

    return;
}

// Find element in the tree
int seek(int data)
{
    return 0;
}










