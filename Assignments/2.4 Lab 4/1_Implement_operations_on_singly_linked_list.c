/*
Implement operations of Singly Linked List
Linked list
Given classes class [info message="class Node<br>{<br>    public:<br>        int data;<br>        Node *next;<br>};"] Node [/info] and class [info message="class SinglyLinkedList{ <br>    private:<br>    Node *head; <br>    public:<br>    SinglyLinkedList(){ <br>        head = NULL; <br>    } <br>    int search(int N); <br>    void insert(int N, int OP); <br>    int remove(int N); <br>    int size(); <br>    void display(); <br>};"] SinglyLinkedList [/info]
Write following functions for class “SinglyLinkedList”
    int search(int N)
that accepts an integer N. The function should search N in the list and return 1 if found else 0.
    void insert(int N, int OP)
that accept an integer N and an operation OP. The function should insert N at the beginning if OP is 1, insert N at the end if OP is 2.
    int remove(int N)
that accept an integer N. The function should return 1 if N is found and removed from the list else 0 if not found in the list.
    int size()
that returns the size of the list.
    void display()
that prints the list of elements starting from the head. Elements are separated by single space. If the list is empty then print “Empty List”.
Input
    13 
    0 2 4 7 6 2 5 0 7 0 0 0 0
    6 1 2 1 2 4 4 6 3 6 4 5 6
    where,
First line of input represents the number of operations.
Second line represents a number of data values to be performed operations.
Third line represents a same number of operations to be performed on values. (1 for insert at the beginning, 2 for insert at the end,3 for remove, 4 for search, 5 for size, 6 for display)
Output

    Empty List 
    2 is found
    5 is not found
    7 2 4 6 
    1
    2 4 6 
    0 is not found
    3
    2 4 6 
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node node;
typedef node* list;

list makelist()                 // Creates new list
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = -999999;
    newnode-> next = NULL;
    return newnode;
}

void append(list L, int elem)   // adds element to the end of the list
{
    while(L->next != NULL)
    {
        L = L->next;
    }
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = elem;
    newnode->next = NULL;
    L->next = newnode;
    return;
}

int length(list L)        // returns length of list
{
    int res = 0;
    while(L->next != NULL)
    {
        res = res + 1;
        L = L -> next;
    }
    return res;
}

void printlist(list L)       // Displays elements of the list
{
    if(length(L) == 0)
    {
        printf("Empty List ");
    }
    else{
        while(L->next != NULL)
        {
            L = L->next;
            printf("%d ",L->data);
        }
    }
}

int removeelem(list L, int elem)      // Removes element from the list
{
    if(L -> next == NULL) 
    {
        printf("0\n");
        return -1;
    }
    else{
        node* prevnode = L;
        node* currnode = L->next;
        while(1==1) 
        {
            if(currnode->data == elem) 
            {
                prevnode->next = currnode->next;
                free(currnode);
                printf("1\n");
                return 0; 
            }
            else if(currnode->next == NULL)
            {
                break; 
            }
            prevnode = currnode;
            currnode = currnode->next; 
        }
        printf("0\n");
        return - 1;
    }
}

int access(list L, int x)      // Returns element in ith position in the list
{
    int i = 0;
    while(i<=x) 
    {
        L = L->next;
        i = i + 1; 
    }
    return L->data;
}

void search(list L, int n )    // Searches for first occurence in the list.
{
    for(int i = 0; i<length(L); i++)
    {
        if(access(L,i) == n)
        {
            printf("%d is found",n);
            return;
        }
    }
    printf("%d is not found",n);
}

int insert(list L, int elem, int x)        // Helps to insert element at specific position
{
    if(x>length(L)) 
    {
        return -1;
    }
    else{
        node* newnode = (node*)malloc(sizeof(node));
        newnode->data = elem; 
        for(int i = 0; i<x; i++)
        {
            L = L->next; 
        }
        newnode->next = L->next;
        L->next = newnode;
        return 0; 
    }
}

int main()
{
    list L = makelist();
    int n;
    scanf("%d",&n);
    int a[n];
    int cmd[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&cmd[i]);
        if(cmd[i] == 1)
        {
            insert(L,a[i],0);
        }
        else if(cmd[i] == 2)
        {
            insert(L,a[i],length(L));
        }
        else if(cmd[i] == 3) 
        {
            removeelem(L,a[i]);
        }
        else if(cmd[i] == 4)
        {
            search(L,a[i]);
            printf("\n");
        }
        else if(cmd[i] == 5)
        {
            printf("%d",length(L));
            printf("\n");
        }
        else if(cmd[i] == 6)
        {
            printlist(L);
            printf("\n");
        }
    }
    return 0;
}