/*
Split circular linked list in two halves - clone
Tags:	Circular linked listData Structures
Given a Circular Linked List, split into two halves. 
Write a function:            
        void solution(struct node *H, struct node **H1, struct node **H2)
that accept a pointer to the first node in linked list H of type “struct node”, the pointers to first (H1) and second (H2) half of lists. The function should split the list into two equal halves and store those values in H1 and H2. If an odd number of nodes present then first half list contains one extra node.
Input
    7    
    2 6 4 7 8 2 9 
    where, 
The first line represents a number of elements in the linked list.
The second line represents elements in the linked list.
Output
    2 6 4 7
    8 2 9
Assume that,
Structure “struct node” is already defined. 
The linked list is already created based on input provided.
Number of elements in the list is within the range 0 to 1000.
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
    p = last;
    do
    {
        if(p->next != last) {
            printf("%d ",p -> data);
        } else {
            printf("%d",p -> data);
        }
        p = p -> next;
    }
    while(p != last);
}
  
void solution(struct Node *last, struct Node **h1, struct Node **h2)
{
    struct Node* temp;
    struct Node* head = last->next;
    temp = head;
    int count=1;
    while(temp->next!=head) 
    {
        count = count + 1;
        temp = temp->next;
    }
    if (count%2 == 0)
    {
        struct Node* head1;
        struct Node* head2;
        head1 = head;
        for(int i = 0; i<count/2-1; i++)
        {
            head2 = head1;
            printf("%d ",head1->data);
            head1 = head1->next;
        }
        printf("%d",head1->data);
        head2 = head1->next;
        head1->next = head; // Linked First half of circular linked list
        printf("\n");
        struct Node* temp2;
        temp2 = head2;
        for(int i = 0; i<count/2-1; i++) 
        {
            printf("%d ",temp2->data);
            temp2 = temp2->next;
        }
        printf("%d",temp2->data);
        temp2->next = head2; // Linked second half of circular linked list
    }
    else{
        struct Node* head3;
        struct Node* head4;
        head3 = head;
        int count3 = (count+1);
        int i;
        for(i = 0; i<count3/2-1; i++)
        {
            head4 = head3;
            if(i<(count3/2)-1)
                printf("%d ",head3->data);
            head3 = head3->next;
        }
        printf("%d",head3->data);
        head4 = head3->next;
        head3->next = head;              // Linked first half of the linked list as circular linked list   
        printf("\n");
        struct Node* temp3;
        temp3 = head4;
        for(; i<count3-3; i++) 
        {
            printf("%d ",temp3->data);
            temp3 = temp3->next;
        }  
        printf("%d",temp3->data);
        temp3->next = head4;               // Linked last half of the linked list as circular linked list
    }
}

//Your program will be evaluated by this main method and several test cases.
int main()
{
    int n,x;
    scanf("%d",&n);
    if(n==0)                   // Checking if no element is present
    {
        printf("no element present");
        return 0;
    }
    struct Node *last = NULL;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&x);
        last = addEnd(last,x);
    }
    if(n==1)               // Checking if only one element is present
    {
        printf("%d",last->next->data);
        return 0;
    }
    struct Node *h1 = NULL;
    struct Node *h2 = NULL;
    solution(last,&h1,&h2);
    traverse(h1);
    printf("\n");
    traverse(h2);
    return 0;
}