/*
Find Nth node from end of singly linked list - clone
Tags:
Data StructuresLinked list
Given a Singly Linked List, find the Nth element from the end of the linked list. 
Write a function: 
        int solution(struct node * H, int N)
that accept a pointer to the first node of linked list H of type “struct node” and a search position N of type integer. The function should return the value of Nth node from the end of the linked list. If the Nth element is not present return -1. 
Input
    6 
    10 20 30 40 50 30
    4 
     where, 
  First line represents a number of elements in the linked list. 
  Second line represents elements in the linked list. 
  Third line represents the position of an element. 
Output
    30 
Assume that, 
Structure “struct node” is already defined. 
Size of the linked list will be between 0 and 32,767.
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int solution(struct node* head, int search)
{
    struct node* ptr;
    int flag=0;
    ptr = head;
    int count = 0;
    while(ptr!=NULL)            // Calculating the size of the linked list
    {
        ptr = ptr->next;
        count = count + 1;
    }
    if(count< search)         // Checking if asked element is greater than the size of the linked list
    {
        flag = -1;
        return flag;
    }
    ptr = head;
    if(count == search)      // Checking if only one element is present in the linked list.
    {
        printf("%d",ptr->data);
    }
    else{
        ptr = head;
        for(int i = 1; i<count-search+1; i++)     // Running through the elements in the linked list in reverse order.
        {
            ptr = ptr->next;
            if(i == count-search)                // Getting the required element from the linked list.
                printf("%d ",ptr->data);
        }
    }
    return flag;
}
//Your program will be evaluated by this main method and several test cases.
int main()
{
    struct node* head = NULL;
    struct node* new_node, *temp;
    int n;
    scanf("%d",&n);
    new_node = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&new_node->data);          // Scan first element to be entered in linked list
    head = new_node;                      
    temp = head;
    for(int i = 2; i<=n; i++)
    {
        new_node = (struct node*)malloc(sizeof(struct node));    // Scanning other elements to be in the linked list.
        scanf("%d",&new_node->data);
        temp->next = new_node;
        temp = temp->next;
    }
    int search; 
    scanf("%d",&search);                               // Scanning the element to be searched in the linked list. 
    int output = solution(head,search);
    if(output == -1)
    {
        printf("%d",output);
    }
    return 0;
}