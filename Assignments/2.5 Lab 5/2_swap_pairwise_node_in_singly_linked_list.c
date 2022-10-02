/*
Swap pairwise nodes in Linked List
Tags:
Data StructuresLinked list
Given a Singly Linked List, pairwise swap the nodes of a given linked list. 
Since swap happens for nodes, a next pointer of the nodes will also get updated.
For linked list of odd number of nodes 1->2->3->4->5, the function should change it to 2->1->4->3->5. 
For linked list of even number of nodes 1->2->3->4->5->6, the function should change it to 2->1->4->3->6->5. 
Write a function: 
        struct node* solution(struct node *H) 
that accept a pointer to the first node in linked list H of type “struct node”. The function should swap the nodes pairwise and return a pointer to the HEAD in linked list. 
Input
    6 
    1 2 3 4 5 6 
where, 
First line represents a number of elements in the linked list. 
Second line represents elements in the linked list. 
Output 
    2 1 4 3 6 5 
Assume that, 
Structure “struct node” is already defined. 
The linked list is already created based on input provided.
Size of the linked list is an integer within the range [0 to 100000].
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* next;
};

void rearrage(struct node* list)        // Helps to swap pairwise nodes
{
    struct node *p, *q;
    int temp;
    if(!list || !list->next)
        return; 
    p = list;
    q = list->next; 
    while(q) 
    {
        temp = p->value; 
        p->value = q->value; 
        q->value = temp; 
        p = q->next; 
        q = p?p->next:0;
    }
    struct node* head;
    head = list;
    while(head!=NULL)
    {
        printf("%d ",head->value);
        head = head->next;
    }
}

//Your program will be evaluated by this main method and several test cases.
int main()
{
    struct node* head = NULL;
    int n;
    scanf("%d",&n);
    struct node* temp, *new_node;
    new_node = malloc(sizeof(struct node));
    scanf("%d",&new_node->value);
    head = new_node;
    temp = head;
    for(int i = 0; i<n-1; i++)                   // Taking linked list
    {
        new_node = malloc(sizeof(struct node));
        scanf("%d",&new_node->value);
        temp->next = new_node;
        temp = temp->next;
    }
    if(n==1)                                   // Checking if only one element is present
    {
        printf("%d",head->value); 
    }
    else if(n==0)                             // Checking if no element present
    {
        printf("no element present");
    }
    else{                                    // Swaping pairwise nodes
        rearrage(head);
    }
}