/*
Implement operations of Doubly Linked List
Tags:	Doubly Linked List
Given classes class Node and class DoublyLinkedList.
Write following functions for class “DoublyLinkedList”
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
    void displayReverse()
that prints the list of elements in reverse order. Elements are separated by single space. If the list is empty then print “Empty List”.
Input
    14
    0 2 4 7 6 2 5 0 7 0 0 0 0 0
    6 1 2 1 2 4 4 6 3 6 4 5 6 7
    where,
First line of input represents the number of operations.
Second line represents a number of data values to be performed operations.
Third line represents a same number of operations to be performed on values. (1 for insert at the beginning, 2 for insert at the end,3 for remove,   4 for    search, 5 for size, 6 for display, and 7 for displayReverse)
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
    6 4 2 
*/
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
} *start = NULL;

void Create(int value)
{
    struct Node *last;
    start = (struct Node *)malloc(sizeof(struct Node));
    start->data = value;
    start->pre = NULL;
    start->next = NULL;
    last = start;
}

int count(struct Node *p)
{
    int length = 0;
    while (p != NULL)
    {
        length += 1;
        p = p->next;
    }
    return length;
}

void Insert(struct Node *p, int value, int OP)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    if (OP == 1)
    {
        // insert in the beginning
        temp->pre = NULL;
        temp->next = start;
        start->pre = temp;
        start = temp;
    }
    else if (OP == 2)
    {
        // insert in the end
        temp->next = NULL;
        for (int i = 0; i < count(start) - 1; i++)
        {
            p = p->next;
        }
        temp->pre = p;
        temp->next = p->next;
        p->next = temp;
    }
}

void remove_it(struct Node *p, int value)
{
    if (p == NULL)
    {
        printf("0\n");
    }
    else if (p->data == value)
    {
        start = start->next;
        if (start != NULL)
        {
            start->pre = NULL;
        }
        printf("1\n");
    }
    else
    {
        int flag = -1;
        while (p != NULL)
        {
            if (p->data == value)
            {
                flag = flag + 1;
                p->pre->next = p->next;
                if (p->next != NULL)
                {
                    p->next->pre = p->pre;
                }
                free(p);
                printf("1\n");
            }
            p = p->next;
        }
        if (flag == -1)
        {
            printf("0\n");
        }
    }
}

void search(struct Node *p, int value)
{
    int flag = -1;
    while (p != NULL)
    {
        if (p->data == value)
        {
            flag += 1;
            printf("%d is found\n", value);
            break;
        }
        p = p->next;
    }
    if (flag == -1)
    {
        printf("%d is not found\n", value);
    }
}

void Display(struct Node *p)
{
    if (p == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

void displayReverse(struct Node *p)
{
    static int flag = -1;
    if (p == NULL)
    {
        if (flag == -1)
        {
            printf("Empty List\n");
        }
        flag += 1;
    }
    if (p != NULL)
    {
        displayReverse(p->next);
        printf("%d ", p->data);
    }
}

void Reverse_display(struct Node **head_ref)
{
    struct Node *temp = *head_ref;
    if (temp == NULL)
    {
        printf("Empty List");
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp != *head_ref)
        {
            printf("%d ", temp->data);
            temp = temp->pre;
        }
        printf("%d ", temp->data);
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr_1[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr_1[i]);
    }
    int arr_2[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr_2[i]);
    }

    int flag = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr_2[i] == 1)
        {
            if (flag == -1)
            {
                Create(arr_1[i]);
                flag += 1;
            }
            else
            {
                if (start == NULL)
                {
                    Create(arr_1[i]);
                }
                else
                {
                    // insert at the beginning
                    Insert(start, arr_1[i], arr_2[i]);
                }
            }
        }
        else if (arr_2[i] == 2)
        {
            if (flag == -1)
            {
                Create(arr_1[i]);
                flag += 1;
            }
            else
            {
                if (start == NULL)
                {
                    Create(arr_1[i]);
                }
                else
                {
                    // insert at the end
                    Insert(start, arr_1[i], arr_2[i]);
                }
            }
        }
        else if (arr_2[i] == 3)
        {
            // remove
            remove_it(start, arr_1[i]);
        }
        else if (arr_2[i] == 4)
        {
            // search
            search(start, arr_1[i]);
        }
        else if (arr_2[i] == 5)
        {
            // size
            int me = count(start);
            printf("%d\n", me);
        }
        else if (arr_2[i] == 6)
        {
            // Display
            Display(start);
        }
        else if (arr_2[i] == 7)
        {
            // Reverse Display
            Reverse_display(&start);
        }
    }
}