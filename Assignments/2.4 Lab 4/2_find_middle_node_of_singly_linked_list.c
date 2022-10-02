/*
Find middle node of singly linked list - clone
Tags:
Data StructuresLinked list
Given a Singly Linked List, find the middle node. 
If there are an even number of nodes, then there will be two middle nodes and function should return second middle node.
Write function: 
        int solution(struct *H) 
that accept a pointer to the first node in sorted linked list H of type “struct node”. The function should return the middle node of a given linked list. If linked list has no element, returns -1. 
Input 
    6 
    10 20 30 40 50 40 
    where, 
First line represents a number of elements in the linked list. 
Second line represents elements in the linked list.
Output 
    40 
Assume that, 
Structure “struct node” is already defined. 
The linked list is already created based on input provided. 
The number of nodes within the range [0 to 100000].
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

int solution(struct node* start,int N)
{
    struct node* ptr;
    ptr = start;
    int flag = 0;
    if(ptr == NULL || N == 0)      // Checking is the the size of linked list is 0 or no.of elements in the list is 0
        flag = -1;
    else{
        if(N%2 == 0)              // Checking if the total number of elements in the list is even.
        {
            int k = N/2;
            int count = 0;
            while(ptr!=NULL)
            {
                if(count == k)
                {
                    printf("%d",ptr->data);     // Printing the second middle element
                    break;
                }
                count = count + 1;
                ptr = ptr->next;
            }
        }
        else{
            int k = (N+1)/2;                
            int count = 0;
            while(ptr!=NULL)
            {
                count = count + 1;
                if(count == k){
                    printf("%d",ptr->data);      // Printing the middle element.
                    break;
                }
                ptr = ptr->next; 
            }
        }
    }
    return flag;
}
//Your program will be evaluated by this main method and several test cases.
int main()
{
    int N;
    scanf("%d",&N);
    struct node *start, *new_node, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&new_node->data);         // Taking 1st element to linked list
    start = new_node;
    temp = start;
    for(int i=2; i<=N; i++)             // Taking other elements to the linked list.
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&new_node->data);
        temp->next = new_node;
        temp = temp->next;
    }
    int output = solution(start,N);
    if(output == -1)
        printf("%d",output);
    return 0;
}