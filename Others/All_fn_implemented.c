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


//#################################################################################################################
//#################################################################################################################
//                       THE FUNCTIONS WHICH ARE NEEDED TO BE INCLUDED   

int length(node* head)  // function used for getting the lenght of the linked list
{
    if (head == NULL)
    {
        return 0;
    }

    int len = 0;
    node* scannner =head;
    while (scannner != NULL)
    {
        len += 1;
        scannner = scannner -> next;
    }
    return len;
}

//-------------------------------------------------------------------------------------------------------------

void insertAtLoacation(node* head, int pos)  // function used for inserting an element at a particular position in the linked list
{
    if (pos > length(head) || pos < 0) 
    {
        printf("The given position is out of the range\n");
    }

    else
    {
        int ele;
        printf("Enter the value to be inserted at position %d ", pos);
        scanf("%d", &ele);
        node* newnode = (node*)malloc(sizeof(node));  // creating a new node which needs to inserted at the given position
        newnode->item = ele;

        node* curr = head;  
        node* prevnode =  head;
        node* nextnode = head;
        int i =0;             // i id for counting the position
        while (nextnode != NULL)  // We iterate through the linked list till we reach the position
        {
            if (i == pos)  // when we reached the given position, we update the coneections
            {
                prevnode->next = newnode;  // we connect previous node of the current node to newnode
                newnode->next = curr;  // and then, connect the new node to current
            }
            i += 1;

            prevnode = curr;
            curr = curr->next;
            nextnode = curr->next;
        }
    }
}

//-----------------------------------------------------------------------------------------------------------

int deleteElement(node* head, int ele)  // function for deleting an element in a linked list, deletes on one element. 
{
    node* curr = head;
    node* prevnode =  head;
    node* nextnode = head;
    int i =0;
    while (nextnode != NULL)
    {
        if (curr->item == ele)
        {
            curr->next = NULL;
            prevnode->next = nextnode;
            free(curr);
            return i;
        }
        
        i +=1;
        prevnode = curr;
        curr = curr->next;
        nextnode = curr->next;
    }

    printf("Th element to be removed is not present in the given linkedlist\n");
    return -1;
}

//-----------------------------------------------------------------------------------------------------------

node* midpoint(node* head)
{
    node* p1 = head;  // pointer 1(p1) and pointer 2(p2), both point to head initially
    node* p2 = head;
    /*p1 traverses one node whicle p2 traverses 2 nodes at a time. So when p2 reaches the end of the linked list, 
    p1 reaches exactly to the midpoint of the linked list, as they both start form the same node(head)*/
    while (p2->next != NULL && p2->next->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    return p1; // now, p1 points to the midpoint of the linked list
}

//#####################################################################################################################
//#####################################################################################################################

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
   
   insertAtLoacation(head, 4);
   printf("%d\n", length(head));
   printlist(head);

   int index = deleteElement(head, 66);
   printf("Th index is :- %d\n", index);

   printlist(head);

   node* mid = midpoint(head);
   printf("The midpoint of the linked list is %d\n",mid->item);
}

//---------------------------------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------------------------------------

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
