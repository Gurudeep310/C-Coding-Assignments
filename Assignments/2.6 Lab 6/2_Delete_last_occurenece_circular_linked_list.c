/*
Delete last occurrence of node in circular linked list - clone
Tags:	Circular linked listData Structures
Given a Circular Linked List, find and delete the last occurrence of provided value in a list.
Write a function:        
        struct node * solution(struct node *H, int E) 
that accept a pointer to the first node in linked list H of type “struct node” and the value of a node to be deleted E of type integer. The function should find and delete the last occurrence E in linked list and return HEAD pointer. If the list is null return NULL pointer.
Input
    7
    2 6 4 7 8 2 9
    2
    where, 
The first line represents a number of elements in the linked list.
The second line represents elements in the linked list.
The third line represents value to be searched and deleted.
Output
    2 6 4 7 8 9
Assume that,
Structure “struct node” is already defined. 
The linked list is already created based on input provided.
Number of elements in the list is within the range [0 to 1000]
*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;
struct Node *addToEmpty(struct Node *last, int data)
{
    if (last != NULL)
    {
        return last;
    }
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
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
  
struct Node *solution(struct Node *last, int n)
{
     int count= 0;
     node* new=(node*)malloc(sizeof(node));
    new = last;
    if(last->data == n)
    {
        count+=1;
    }   
    last = last->next;
    while(last->next!=new->next)
    {
        if(last->data == n)
        {
            count = count + 1;
        }
        last = last->next;
    }
    last = new;
     if(n==0||n==1)
     {
        printf("no element present");
        return 0;
     }
    else
    {
        int pos=count;
        int count1 = 0;
        node* temp1 = (node*)malloc(sizeof(node));
        node* prev = (node*)malloc(sizeof(node));
        node* last_element = malloc(sizeof(node));
        prev = last;
        temp1 = last;
        last_element = last->next;
        last = last->next;
        if(temp1->data==n)
        {
            while(last->next->next!=temp1->next)
            {
            last = last->next;
            }
            last->next = last_element;
            last = temp1;
            return last;
        }
        while(last->next!=temp1->next)
        {
            if(last->data == n)
            {
                count1++;
            }
            if(count1==pos)
            {
                prev->next=last->next;
                break;
            }
            prev = prev->next;
            last = last->next;
        }
        last = temp1;
        return last;
     }
}
//Your program will be evaluated by this main method and several test cases.
int main()
{
    int n,x;
    scanf("%d",&n);
    struct Node *last = NULL;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&x);
        last = addEnd(last,x);
    }
    scanf("%d",&x);
    if( n==0)
    {
        printf("no element present");
        return 0;
    }
    last = solution(last,x);
    traverse(last);
    return 0;
}