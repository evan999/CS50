#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct Node
{
    int data;
    struct Node *next;
}
Node;

void push(int data, Node* head);

int pop(Node* head);

int peek(Node* head);

void free_list(Node* root);

int main(void)
{
    Node* head = NULL; // pointer to head node
    Node* second = NULL; // pointer to second node
    Node* third = NULL; // pointer to third node

    head = (struct Node*)malloc(sizeof(struct Node)); // dynamically allocate memory to head ptr
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 5;
    head->next = NULL;
    // head->next = second;
    // head->next->data= 7;

    // // second->data = 27;
    // // second->next = third;
    // head->next->next = third;
    // head->next->next->data = 9;
    // //third->data = 13;
    // //third->next = NULL;
    // head->next->next->next = NULL;
    push(3, head);
    printf("Pop: %i\n", pop(head));
    printf("Last element in list: %i\n", peek(head));

    return 0;
}

void push(int data, Node* head) // add node to linked list
{
    Node* trav = head;

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
// TODO: Modify pop to fix segmentation fault bug
// Return data, free the head
int pop(struct Node* head)
{
    Node* trav = head;

    // Find second to last node
    while (trav->next->next != NULL)
    {
        trav = trav->next;
    }

    // if (trav->next != NULL)
    // {
    //     free(trav);
    // }

    int data = trav->next->data; // Hey next, what's your data?
    free(trav->next); // Hey next, you're free!
    trav->next = NULL;
    free(trav);
    return data; // return number

}

// Look at the last item
int peek(struct Node* head)
{
    Node* trav = head;

    while(trav->next->next != NULL)
    {
        trav = trav->next;
    }

    // if (trav->next != NULL)
    // {
    //     data = trav->data;
    // }
    // else
    // {
    //     data = trav->next->data;
    // }

    int data = trav->next->data;
    return data;
}

void free_list(struct Node* root)
{
    Node* trav = root;

    if (trav->next == NULL)
    {
        free(trav);
        return;
    }

    // If on second to last item

    if (trav->next->next == NULL)
    {
        free(trav->next); // free item before NULL ptr
        free(trav); // free the current item
        // trav->next = NULL;


        // Function is done. Go back to start of function.
        return;
    }

    // Continue down the list
    // Call function, go to next item in list and go through function
    free_list(trav->next);
    free(root); // free current item (on last item)
    return;
}








