/*
Delete last node of circular linked list - clone
Tags:	Circular linked listData Structures
Given a Circular Linked List, delete the last node of the list.
Write a function:
        struct node * solution(struct node *H)
that accept a pointer to the first node in linked list H of type “struct node”. The function should delete the last node and returns a HEAD pointer. If a list is empty return NULL pointer.
Input
    7
    2 6 4 7 8 2 9
    where, 
The first line represents a number of elements in the linked list.
The second line represents elements in the linked list.
Output
    2 6 4 7 8 2
Assume that,
Structure “struct node” is already defined. 
The linked list is already created based on input provided.
Number of elements in the list are within the range 0  to 1000.
*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *addToEmpty(struct Node *last, int data)
{
    if (last != NULL)
    {
        return last;
    }
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    last = temp;
    last -> next = last;
    return last;
}

struct Node *addEnd(struct Node *last, int data)
{
    if (last == NULL)
    {
        return addToEmpty(last, data);
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;
    return last;
}

void traverse(struct Node *last)
{
    struct Node *p;
    if (last == NULL)
    {
        return;
    }
    p = last -> next;
    do
    {
        printf("%d ",p -> data);
        p = p -> next;
    }
    while(p != last->next);
}
  
struct Node *solution(struct Node *last) {
    struct Node* temp1;
    temp1 = last->next;      // Given address of the last node. So shifting it to head.
    struct Node* temp2;
    while(temp1->next!= last->next)
    {
       temp2 = temp1;
       temp1 = temp1->next;
    }
    temp2->next = last->next;    // Storing address of head in the last node.
    last =temp2;                 // Storing address of last node
    free(temp1);                 // Freeing last node.
    return last;
}

//Your program will be evaluated by this main method and several test cases.
int main()
{
    int n,x;
    scanf("%d",&n);
    if(n==0)
    {
        printf("no element present");
    }
    else{
        struct Node *last = NULL;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&x);
            last = addEnd(last,x);
        }
        scanf("%d",&x);
        last = solution(last);
        traverse(last);
    }
    return 0;
}