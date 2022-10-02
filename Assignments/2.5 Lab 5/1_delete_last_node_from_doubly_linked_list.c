/*
Delete last node of doubly linked list - clone
Tags:
Linked listDoubly Linked ListData Structures
Given a Doubly Linked List, delete the last node.
Write a function:
        struct node * solution(struct node * H)
that accept a pointer to the first node in linked list H of type “struct node”. The function should delete the last node of linked list and return a pointer to the HEAD node. If a list is empty return NULL pointer.
Input
    7
    2 6 4 7 8 2 9
    where, 
The first line represents a number of elements in the linked list.
The second line represents elements in the linked list.
Output
    2 6 4 7 8 2 
    2 8 7 4 6 2
The output displays all the elements in forward and reverse order both.
Assume that,
Structure “struct node” is already defined. 
The linked list is already created based on input provided.
Number of elements in the linked list is within the range [ 0 to 1000 ].
*/
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *addToEmpty(struct Node *head, int data)
{
    if (head != NULL)
    {
        return head;
    }
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    temp -> prev = NULL;
    return temp;
}

void traverse(struct Node *head)
{
    struct Node *p;
    if (head == NULL)
    {
        printf("No element present");
        return;
    }
    p = head;
    while(p->next!=NULL)                      // Traversing untill last element in the linked list
    {
        p = p->next;
    }
    (p->prev)->next = NULL;                  // Deleting the last node in the linked list
    free(p);
    p = head;
    while(p -> next != NULL)                // Printing the modified linked list
    {
        printf("%d ",p -> data);
        p = p -> next;
    }
    printf("%d \n",p->data);

    while(p != NULL)                       // Printing the linked list in reverse order.
    {
        printf("%d ",p -> data);
        p = p -> prev;
    }
}

struct Node *addEnd(struct Node *head, int data)
{
    if (head == NULL)
    {
        return addToEmpty(head, data);
    }
    struct Node *trav = head;
    while(trav -> next != NULL)
    {
        trav = trav -> next;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    trav -> next = temp;
    temp -> prev = trav;
    return head;
}

struct Node *solution(struct Node *head, int data)
{
    if(head == NULL)
    {
        return NULL;
    }
    struct Node* temp1;
    struct Node* temp2;
    temp1 = head;
    while(temp1!= NULL)
    {
        temp1 = temp2;
        temp1 = temp1 ->next;
    }
    temp2->next = NULL;
    free(temp1);
    temp1 = head;
    while(temp1->next != NULL)
    {
        printf("%d ",temp1->data);
        temp1 = temp1->next;
    }
    while(temp1->next != NULL)
    { 
        temp1 = temp1->next;
        
    }
    return head;
}

int main()
{
    int n,x;
    scanf("%d",&n);
    struct Node *head = NULL;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&x);
        head = addEnd(head,x);
    }
    scanf("%d",&x);
    if(n==1)                                   // Checking if only one element is present in the linked list
    {
        printf("No element present");
    }
    else{
        traverse(head);
    }
    return 0;
}