/*
Implement operations of queue - clone
Tags:	Queue
Given a class Queue, Implement operations of queue.
struct qNode represents individual element in queue.
Define 5 functions of class “Queue”
    void enqueue(int x)
that accepts data to be inserted x. The function should enqueue the qNode with data as x into queue
    int dequeue()
that dequeue the qNode and return the data value of it. (If Queue is already empty then return -1)
    int size()
that return number of elements in the queue.
    int search(int item)
that accepts an integer as an item. A function searches the given item into a queue if the item found in a queue then return 1 else return 0.
    void display()
that display the queue elements in a row and a space after each element. (If Queue is already empty then display “Empty”)
Input
    7
    1 2 1 0 0 6 0
    1 1 3 0 4 1 2
    where,
First line represents a number of operations.
Second line represents a number of data values to be enqueued.
Third line represents a same number of operations to be performed on values. (0 for dequeue, 1 for enqueue, 2 for size, 3 for search and 4 for display)
Output
    1 is found
    2 
    Queue size is 2
The output displays the elements of the queue after operations.
Assume that,
The structure “struct qNode” is already defined.
The class “Queue” is already defined.
*/
#include<stdio.h> 
#include<stdlib.h>

struct qnode 
{
    int data;
    struct qnode* next;
};

struct qnode* front = NULL;
struct qnode* rear = NULL; 
void enqueue(int x)
{
    struct qnode* temp = (struct qnode*)malloc(sizeof(struct qnode*));
    temp -> data  = x; 
    temp -> next = NULL; 
    if(front == NULL && rear == NULL)         // If queue is empty then initialise front and rear as pointing to first node in linked list
    {
        front = temp;
        rear = temp;
        return;
    }
    rear -> next = temp;                   
    rear = temp;
}

int dequeue() 
{
    struct qnode* temp = front; 
    if(front == NULL)                       // If front is Null then queue is empty
        return -1;
    if(front == rear)                     // If front equal to rear then make both of them to null
    {
        front = NULL;
        rear = NULL; 
        return temp->data;
    }
    else                               // else delete elem by moving front to next node
    {
        front = front -> next; 
        return temp->data;
    }
}

int search(int item) 
{
    struct qnode* temp = front;
    while(temp!=NULL)                   //Traverse the linked list as queue              
    {
        if(temp->data == item)          // If found desired element then return 1 
            return 1;
        temp = temp -> next;           // Incrementing the pointer to move to next node in linked list
    }
    return 0;
}

void display()
{
    if(front == NULL)                     
    {
        printf("Queue is empty\n");
        return;
    }
    else 
    {
        struct qnode* temp = front; 
        while(temp!=NULL)                            // Untill temp reaches end of queue implemented as linked list print all the element stored in queue
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int size()
{
    struct qnode* temp = front; 
    int count = 0;
    while(temp!=NULL)                  // Traversing and calcuating the size of queue implemented as linked list
    {
        count = count + 1; 
        temp = temp -> next; 
    }
    return count; 
}

int main()
{
    struct qNode* head;
    head = NULL;
    int N;
    scanf("%d",&N);
    int A[N];
    int B[N];
    for(int i = 0; i<N; i++)
    {
        scanf("%d",&A[i]);
    }
    for(int i = 0; i<N; i++)
    {
        scanf("%d", &B[i]);
    }
    for(int i = 0; i<N; i++)
    {
        if(B[i] == 0)
        {
            dequeue();
        }
        else if(B[i] == 1) 
        {
            int x = A[i];
            enqueue(x);
        }
        else if(B[i] == 2) 
        {
            int y = size();
            printf("Queue size is %d\n",y);
        }
        else if(B[i] == 3) 
        {
            int output = search(A[i]);
            if(output == 1) 
            {
                printf("%d is found\n",A[i]);
            }
            else 
            {
                printf("%d is not found\n",A[i]);
            }
        }
        else if(B[i] == 4)  
            display();
    }
    return 0;
}