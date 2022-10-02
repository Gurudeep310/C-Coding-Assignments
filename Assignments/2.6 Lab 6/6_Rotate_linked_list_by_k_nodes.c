/*
Rotate a linked list by K nodes - clone
Tags:	Data StructuresLinked list
Given a Singly Linked List, rotate the linked list counter-clockwise by K nodes. 
Write a function:
        struct node* solution(struct node *H, int K)
that accept a pointer to the first node in linked list H of type “struct node” and offset K of type integer. The function should return the pointer to the head of rotated linked list.
Input
     5 
     1 2 3 4 5
     2
    where,
First line represents a number of elements in the linked list. 
Second line represents elements in the linked list. 
Third line represents offset K.
Output
    3 4 5 1 2
Assume that,
Structure “struct node” is already defined. 
The linked list is already created based on input provided.
Value of K is an integer will be in the range from 0 to 32,767.
Size of the linked list is an integer within the range [0 to 100000].
*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void solution(struct Node* head, int k, int n)
{
    struct Node* temp1;
    struct Node* temp2;
    temp1 = head;
    int count = 0;
    int arr[10000];
    for(int i = 0; i<k; i++)
    {
        temp2 = temp1;
        arr[i] = temp1->data;
        temp1 = temp1->next;
        count = count + 1;
    }
    head = temp1;
    temp2->next = NULL;
    while(temp1->next!=NULL)
    {
        temp1 = temp1->next;
    }
    struct Node* new_node;
    int j = 0;
    while(j<count) 
    {
        new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = arr[j];
        temp1->next = new_node;
        temp1 = temp1->next;
        j = j + 1;
    }
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}

//Your program will be evaluated by this main method and several test cases.
int main()
{
    struct Node* head = NULL;
    struct Node* temp, *new_node;
    int n;
    scanf("%d",&n);
    if(n==0)
    {
        printf("no element present");
        return 0;
    }
    new_node = (struct Node*)malloc(sizeof(struct Node));
    scanf("%d",&new_node->data);
    head = new_node;
    temp = head;
    for(int i = 2; i<=n; i++)
    {
        new_node = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&new_node->data);
        temp->next = new_node;
        temp = temp->next;
    }
    int k;
    scanf("%d",&k);
    if(n==k || k == 0)
    {
        while(head!=NULL)
        {
            printf("%d ",head->data);
            head = head->next;
        }
        return 0;
    }
    solution(head,k,n);
}