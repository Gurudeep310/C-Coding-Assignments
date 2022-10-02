#include<stdio.h>
#include<stdlib.h>

// Below is the definition of the new data type node, accomplished using structures.
struct node
{
    int item; //The desired value
    struct node* next; // Pointer to the next node
};
/* Kindly note that above definition only tells the compiler what is a "struct node" data type. 
It does not create any variable/node for you*/

typedef struct node node;
/* The above line enables you to address "struct node" as "node" to keep your code clean */

/* FUNCTIONS IMPLEMENTED: Below are the prototypes of the functions. See their definitions after main()
1. All the functions extensively use the "node *head" pointer. This pointer stored the address of the first node.
2. head is NULL if there is no node in the list. 
3. Note that the address stored in head might change during insert and delete operations. 
*/

node* insert(node* );// Inserts a new node (with values as input from the user) at the end of the linked list. Returns the new value of head pointer. 
void printlist(node* );// Prints the linked list

int main()
{
   node* head=NULL; // Initially the list is empty, there is no node. So head is NULL. 
   // Note that head is a pointer of type node, means it can store the address of a variable of type node. 
   // head stores the address of the first node. Since there is no node in the list, head stores NULL
   
   int ch = 1;// A choice variable
   printf("Let's populate our list by inserting the elements one by one.\n");
   do
   {
        head = insert(head); 
        printlist(head);
        printf("Enter 1 if you want to insert more nodes.\n");
        scanf("%d",&ch);
   } while (ch==1);


   printf("The linked list is populated.\n");
   printlist(head);
   
   
}


node* insert(node* h) //This function takes the current value of head as argument and returns the new value of head 
// The value of head in main is copied to a new pointer variable h.
{
    //CREATE THE NEW NODE
    node* newnode= (node*)malloc(sizeof(node)); //Create the new node
    
    //POPULATE THE FIELDS OF THE NODE. AS WE KNOW THAT THE NODE IS TO BE INSERTED AT END, ITS NEXT FIELD WILL BE NULL
    printf("Enter the integer value you want to insert.\n");
    int key;
    scanf("%d",&key);
    newnode->item = key;
    newnode->next = NULL; 

    //To insert the node at end, we need to come to the last node of the current linked list, and modify its next pointer to hold the address of the new node. 

    // If the head is NULL, coming to the last node doesn't make any sense as there is no node. 
    // In that case, we insert a new node in the linked list and make it head. 
    // See here, since head changes its value here, we ensure that we return its value. Or else make it global. 
    
    if(h==NULL)
    {
        h = newnode;   
        return(h);
    }

    // If there is at least one node in the linked list, we traverse to the last node using scanner. 
    node* scanner = h;
    while(scanner->next!=NULL)
    {
        scanner = scanner -> next;
    }
    scanner -> next = newnode;// Modify the next field of the last node, thereby making newnode as the last node.
    return(h);
}

void printlist(node* h) //One of the most simple functions
{
    printf("Current List: ");
    node* scanner = h;
    while(scanner!=NULL)    //Keep printing the values till the pointer becomes NULL
    {
        printf("%d -> ",scanner->item);
        scanner = scanner -> next ;
    }
    printf("NULL\n*****************************************\n"); 
    printf("*****************************************\n");
}
