#include<stdio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node* next;
};

typedef struct node node;

node* insert(node* h)
{
    /*
     Assume Linked list: 2|a3 -> 3|a4 -> 4|Null
      I have to insert a new node at the end
      After inserting it should look like:
      2|a3 -> 3|a4 -> 4|ak -> k|Null
      So in order to create like this we need a pointer of node.
    */

   node* newnode = (node*)malloc(sizeof(node));
   printf("Enter the key\n");
   int key;
   scanf("%d",&key);
   /*
     Now i have to insert this key to the new node.
     As new node is a pointer we cannot use like newnode.item=key
     We need to do like this: (*newnode).item=key or newnode->item=key
    */
   newnode->item=key;
   // As this is the last element in the link list the address of the last block should be NULL.
   newnode->next=NULL;
   /* Now how to attach to the existing link list??
      So i should come to last before element in the link list i.e 3|a4 and then make changes.
      So Scanf the next node untill i go to the node where i have NULL
   */
    node* scanner=h;
    if(scanner==NULL) //i.e if link list is empty
    {
        h = newnode; // |2,NULL|
        return(h);
    }
    while(scanner->next!=NULL)
    {
        scanner = scanner -> next;
    }
    /*
       So after coming to that node where NULL is present
    */
   scanner -> next =newnode;
   // But if the link list is empty i get an ERROR
   return(h);

}

void printlist(node* h)
{
     /*
        It has to print untill it encounters NULL
     */
    node* scanner=h;
    while(scanner!=NULL)
    {
        printf("%d ",scanner->item);
        scanner = scanner->next;
    }
    printf("\n");
    
}

int main()
{
    //Linked list--> |23,16x|  |67,89x| |300,NULL|
    //I need a pointer of type node
    //And initially the link list is empty so head should be NULL
    //Head tells me from where my link list is starting.
    node* head = NULL;
    int ch = 1;
    do
    {
        head = insert(head);
        printlist(head);
        printf("Do you want more nodes?? ");
        scanf("%d",&ch);
    } while (ch==1);
    
}

