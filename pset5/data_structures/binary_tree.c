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

BinaryNode* root = NULL;

void add(int item);
int seek(int query); // true 1 or false 0 if item exists in tree
void free_tree(BinaryNode* nav);

void test_tree()
{
    add(5);
    assert(seek(5) == 1 && "tree contains the number 5"); // modify the true to use seek
    add(3);
    add(4);
    assert(seek(9) == 0 && "tree does not contain 9");
    // assert(true); // modify the true to use seek
}

void bruteForceTree()
{
    root = malloc(sizeof(BinaryNode));
    root->data= 5;

    BinaryNode* leftNode = malloc(sizeof(BinaryNode));
    leftNode->data = 2;
    leftNode->small = NULL;
    leftNode->large = NULL;

    BinaryNode* rightNode = malloc(sizeof(BinaryNode));
    rightNode->data = 8;
    rightNode->small = NULL;
    rightNode->large = NULL;

    root->small = leftNode;
    root->large = rightNode;


}

void testSeek()
{

    bruteForceTree();
    assert(seek(5) && "found 5"); // If nothing prints, function call works!
    assert(seek(2) && "found 2");
    assert(!seek(1) && "confirm 1 does not exit");
    assert(seek(8) && "found 8 right found");
    assert(!seek(9) && "confirm 9 does not exist right right");
    assert(!seek(3) && "confirm 3 does not exist left right");
    assert(!seek(7) && "confirm 7 does not exist right left");
}

// Test our Add function by using assert on seek.
void testAdd()
{
    add(5);
    assert(seek(5) && "found the added 5");
    add(2);
    assert(seek(2) && "found the new number 2");
    assert(seek(5) && "5 still exits");
    add(1);
    assert(seek(1) && "1 was added successfully");
    assert(seek(2) && "2 still exists");
    add(3);
    assert(seek(3) && "3 was found");
    add(8);
    assert(seek(8) ** "8 was found");
    add(9);
    add(3);
    assert(seek(9) && seek(3) && "9 and 3 were both found");
    assert(seek(8) && "8 still exists");
}

void testFree()
{
    add(5);
    assert(seek(5) && "5 was added to the tree");
    add(2);
    add(1);
    add(8);
    add(3);
    add(9);
    free_tree(root);
    assert(!seek(5) && "5 was cleared from the tree");
    assert(!seek(2) && "2 was cleared from the tree");
    assert(!seek(8) && "8 was cleared from the tree");
    assert(!seek(1) && "1 was cleared");
}

// Initialize root node to NULL
//BinaryNode* root = NULL;

int main(void)
{
    printf("Hello\n");
    // add(5);
    // add(5);
    // printf("%i\n", add(5));

//    printf("Add element: %i\n", add(5));

    int data[] = {5, 8, 2, 9, 4, 1, 3};
    testFree();
    // bruteForceTree();
    // testSeek();
    // testAdd();
    // struct BinaryNode *root = add(5);
    // test_tree();




    // Initialize left and right child nodes to NULL
    // BinaryNode->left = NULL;
    // BinaryNode->right = NULL;


}

void add(int item)
{
    // Add the item to the end of a branch based on following rules:
    // if item is larger, then current node move to right (large) route
    // if item is smaller, then current node move to left (small) route
    // check for end of the branch

    BinaryNode* newNode = malloc(sizeof(BinaryNode));
    newNode->data = item;
    newNode->small = NULL;
    newNode->large = NULL;

    // If empty tree
    if (root == NULL)
    {
        root = newNode;
        return;
    }

    BinaryNode* nav = root;

    while("end of branch not found")
    {
        // if item is smaller, go left
        // Look before you leap!
        if (item < nav->data)
        {
            if (nav->small != NULL)
            {
                nav = nav->small;
                continue;
            }

            nav->small = newNode;
            return;
        }

        if (item > nav->data)
        {
            if (nav->large != NULL)
            {
                nav = nav->large;
                continue;
            }

            nav->large = newNode;
            return;
        }

        return;
    }
}

// Find element in the tree
int seek(int query)
{
    // seek scans the tree for the number sent.
    // It will return 0 if the number is not found in the tree.
    // It will return 1 if the number is found in the tree.

    BinaryNode* nav = root;
    while (true && "Not at the end of a branch or haven't found the query yet")
    {
        // how to find
        // check current node's data
        // if found, 1
        if (nav->data == query)
        {
            // found the data we were looking for
            return 1;
        }

        // else
        // is current node larger or smaller then query
        if (query < nav->data)
        {
            // go smaller route
            // check for a node
            if (nav->small == NULL)
            {
                // done with search
                // number not found
                return 0;
            }

            nav = nav->small;
            continue;
        }
        // the query is greater than current node
        if(nav->large == NULL)
        {
            // done with search
            // number not found
            return 0;
        }

        // go to node
        nav = nav->large;
        continue;
    }

    return 0;
}

void free_tree(BinaryNode* nav)
{
    // Free all heap nodes from the tree

    // Base cases
    // Empty tree
    if (nav == NULL)
    {
        return;
    }

    // nav has no children
    if (nav->small == NULL && nav->large == NULL)
    {
        free(nav);
        return;
    }


    // Recursive cases
    if (nav->small != NULL)
    {
        free_tree(nav->small);
    }

    if (nav->large != NULL)
    {
        free_tree(nav->large);
    }
    free(nav);

    return;
}









