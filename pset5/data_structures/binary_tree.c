#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct Node
{
    int data;
    struct Node *next;
}
Node;

void push(int data, struct Node*);

int pop(struct Node*);

int peek(struct Node*);

int main(void)
{
    struct Node* head = NULL; // pointer to head node
    struct Node* second = NULL; // pointer to second node
    struct Node* third = NULL; // pointer to third node

    head = (struct Node*)malloc(sizeof(struct Node)); // dynamically allocate memory to head ptr
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));



    return 0;
}

void push(int data, struct Node* head) // add node to linked list
{

}

// Pop the second to last item of the linked list (last is NULL)
int pop(struct Node* head)
{
    return 0;
}

// Look at the last item
int peek(struct Node* head)
{
    return 0;
}










