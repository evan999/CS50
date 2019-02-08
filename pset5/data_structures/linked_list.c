#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct Node
{
    int data;
    struct Node *next;
}
Node;

void push(int, struct Node*);

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

    head->data = 5;
    head->next = second;
    head->next->data= 7;

    // second->data = 27;
    // second->next = third;
    head->next->next = third;
    head->next->next->data = 9;
    //third->data = 13;
    //third->next = NULL;
    head->next->next->next = NULL;
    push(6, head);
    // printf("%i\n", pop(head));
    printf("%i\n", peek(head));

    return 0;
}

void push(int data, struct Node* head) // add node to linked list
{
    struct Node* trav = head;

    while (trav->next != NULL)
    {
        trav = trav->next;
    }



    // trav->next = (struct Node*)malloc(sizeof(struct Node));
    // trav->next->data = data;
    // trav->next->next= NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    trav->next = newNode;
}

// Pop the second to last item of the linked list (last is NULL)
int pop(struct Node* head)
{
    struct Node* trav = head;
    int counter = 0;

    // Find second to last node
    while (trav->next->next != NULL)
    {
        printf("%i\n", counter++);
        trav = trav->next;
    }

    int data = trav->next->data; // Hey next, what's your data?
    free(trav->next); // Hey next, you're free!
    trav->next = NULL;
    return data; // return number
}

// Look at the last item
int peek(struct Node* head)
{
    struct Node* trav = head;

    while(trav->next->next != NULL)
    {
        trav = trav->next;
    }

    int data = trav->next->data;
    return data;
}




