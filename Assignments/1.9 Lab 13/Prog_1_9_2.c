/*
[L13 P1] The h->u->u->u->g->e Linked List Problem!
We have seen how a Linked List (LL) works.
The basic building block on an LL is a structure - called Node - which can hold two pieces of information:
    1) The peice of data : a number, a character or something else.
    2) An address to another Node.
A linked list is essentially a collection of such nodes that are connected with each other in a sequential manner - as shown in the picture below.
Question) Why do we need linked lists? Can't we just use arrays?
Ans) We can. But as it happens there are some good aspects of linked lists. One of them is: they are very frugal in terms of memoey usage. When we add an element to the list do we create a new Node and link it to the list. And when we delete an element we free the memory required to store the Node. This kind of dynamic resizing is not possible with arrays. 
L here which serves practically as the name of the list is actually a variable whose value is the pointer to the first Node of the list. The first node may sometimes be referred to as the head of the List. As a choice we do not save anything useful in the head of the list -- so we just put some ridiculous value (eg:-999999) in it. 
Question) Why should we put some ridiculous value? Can't we just leave it alone since some junk occupies it anyway?
Ans) Sure. However, it is safer to know what this junk value is as it may help us identify the head just in case. So it is better to assign it ourselves.
In the lectures we developed various functions to operate on the list:
makeList //creates a fresh list
append //adds a new element at the end of the list
printList //prints all the elements in the list without having to use a forloop everysingle time
removeElem //removes a given element from the list
length //computes the number of elements in the list
access //finds the ith element in the list
The code that corresponds to all these functions is already give to you in the folder LinkedList.h. 
This is has already been included in the solution.c file. 
Your task is simply to define the function int insert(List L, int elem, int pos) in the solution.c file such that the main function produces the desired output.
The insert function takes 3 arguments:
                - The list
                - the element to be inserted
                 - the position in which it should be inserted
The function must return 0 when the insertion is a success; and returns -1 when it fails.
Question) When does insertion fail?
Ans) If the position is beyond the length of the range of the index 0 <= ix <= size-1 the insertion operation fails.
Example1:
Input:
5
-1 2 3 4 -5    
3
1,0
2,3
4,2
Where:
    5 in the first line is the size of the list.
    -1 2 3 4 -5 are the elements of the lsit
    3 in the third line is the number of insert operations to be made
    1,0  insert 1 in 0th position
    2,3  insert 2 in 3rd position
    4,2  insert 4 in 2nd position
Output:
[1 -1 4 2 2 3 4 -5 ]
Explanation: Initially the list is [-1, 2, 3, 4, -5 ]. After inserting 1,2 and 4 in positions 0,3 and 2 in the given order the list has become [1 -1 4 2 2 3 4 -5 ].
Example 2:
Input:
1
5
3
1,2
Output:
Insertion operation failed
Explanation: The list is [5 ] and we tried to insert 1 in the second position. This is bound to fail because the list is singleton and does not have a secon position.
Example 3:
Input:
7
-1 0 1 -1 0 1 0
4
1,2
2,3
4,5
6,7
Output:
[-1 0 1 2 1 4 -1 6 0 1 0 ]
Explanation: Self evident.
*/

#include "LinkedList.h"
/*#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node; //don't bug me again
typedef Node* List;

//------------
List makeList(){ 
    //this function create a fresh new list
    //eg: List L = makeList();
    Node* newNode_p = (Node*)malloc(sizeof(Node));
    newNode_p->data = -99999;
    newNode_p->next = NULL;

    return newNode_p;
}

//------------

void append(List L, int elem){
    //append elem to the end of L
    //eg: append(L, 4);
    while(L->next != NULL){
        L = L->next;
    }
    Node* newNode_p = (Node*)malloc(sizeof(Node));
    newNode_p->data = elem;
    newNode_p->next = NULL;

    L->next = newNode_p;

    return;
}

//------------
void printList(List L){
    //prints the elements of list from first to last
    //eg: printList(L);
    printf("[");
    while(L->next != NULL){
        L = L->next;
        printf("%d ", L->data); //note that there will be an extra space after the last element.
    }
    printf("]\n");
}

//------------

int removeElem(List L, int elem){
    //removes the first occurance of an element from the list
    //suppose L = [3, -5, 6, 7, 8, 7, 9, -1]
    //remove(L, 7) returns [3, -5, 6, 8, 7, 9, -1]
    if(L->next == NULL){
        printf("can't perform deletion operation on an empty list\n");
        return -1;
    }
    /* else if((L->next)->data == elem){
        Node* currNode_p = L->next;
        L->next = currNode_p->next;
        free(currNode_p);
    } */
    /*
    else{
        Node* prevNode_p = L;
        Node* currNode_p = L->next;

        while(1 == 1){
            
            if(currNode_p->data == elem){
                prevNode_p->next  = currNode_p->next;
                free(currNode_p);
                printf("%d has been removed\n", elem);
                return 0;
            }
            else if(currNode_p->next == NULL){
                break;
            }
            prevNode_p = currNode_p;
            currNode_p = currNode_p->next;
        }
        printf("%d does not exist in the given list\n", elem);
        return -1;
    }
}

//------------

int length(List L){
    //returns the no. of elements in a list
    //eg: length(L)
    int res = 0;
    while(L->next != NULL){
        res++;
        L = L->next;
    }
    return res;
}

//------------

int access(List L, int ix){
    //returns the element sitting in the ixth position of the list.
    if(ix >= length(L)){
        printf("the index is outofRange\n");
        return -88888;
    }

    int i = 0;
    while(i <= ix){
        L = L->next;
        i += 1;
    }
    return L->data;
}

//------------
*/
int insert(List L, int elem, int ix){
    //If position is not there like exceeded then return -1
    if(ix>length(L))
    {
        return -1;
    }
    Node* pointer= L;
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=elem;
    //go to the position of ix and insert elem
    int i=0;
    while(i<ix)
    {
        pointer=pointer->next;
        i=i+1;
    }
    temp->next=pointer->next;
    pointer->next=temp;
    return L;
    
}

int main(){
    
    List L = makeList();

    int sizeofList;
    scanf("%d", &sizeofList);
    
    for(int i = 0; i < sizeofList; i++){
        int x;
        scanf("%d", &x);
        append(L, x);
    }
    
    int trials;
    scanf("%d", &trials);
    for(int t = 0; t < trials; t++){
        int new_elem;
        int index;
        scanf("%d,%d", &new_elem, &index);
        int token = insert(L, new_elem, index);
        if(token == -1){
            printf("insertion operation failed\n");
            return 1;
        }
    }
    printList(L);
    return 0;
}