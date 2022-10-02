/*
Implement fixed size stack - clone
Tags:	Data StructuresStack
Given a struct Stack, implement a fixed size stack. 
Write a function: 
      struct Stack * solution(int A[], int N) 
that accept an array of integers A represents a sequence of operations to be performed on stack along with values to pushed to stack and size of an array N. The function should perform the given operations on a stack and return a pointer to stack.
The array element contains operation codes and values to be inserted in the stack.
Push (code 1): Push the next value in an array into the stack. If a stack is full, print "stack is full" on a new line. 
Pop (code 2): Removing an element from the stack. If a stack is empty, print "stack is empty" on a new line. 
Return (code 3): Return pointer to Stack. 
Input
    8
    1 10 1 20 1 30 2 3 
    where,    
First line represents the size of an array.
Second line represents an array elemennts.
Output
    20 10 
The first element is 1, hence push the next element 10 in the stack.
Next is 1, push 20 to the stack.
Next is 1, push 30 to the stack.
Next is 2, pop the top element 30.
Next is 3, a function returns a pointer to stack. 
Assume that, 
The stack is initially empty. 
The maximum size of the stack is 10. 
Value in the stack can be in the range from [-2,147,483,648 to 2,147,483,647]
*/
#include<stdio.h>


int push(int stack[], int max_size, int elem, int top )
{
    if(top == max_size-1)
    {
        printf("stack is full\n");    // If stack is full tell stack is full
    }
    else 
    {
        top = top + 1;              // Updating toop
        stack[top] = elem;          // Push operation
    }
    return top;
}

int pop(int stack[],int max_size,int top)
{
    if(top<=-1) 
    {
        printf("stack is empty\n");     // If stack is empty tell stack is empty
    }
    else 
    {
        top = top - 1;                // Pop operation
    }
    return top;
}
//Your program will be evaluated by this main method and several test cases.
int main()
{
    int n;
    int max_size = 10;   
    int top = -1;
    int stack[10];
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i<n; i++)
    {
        int elem = 0;
        if(arr[i] == 1 && arr[i] !=3) 
        {
            elem = arr[i+1];
            top = push(stack,max_size,elem,top);  // Perform push operation and update top value
        }
        else if(arr[i] == 2 && arr[i]!=3) 
        {
            elem = arr[i-1];
            top = pop(stack,max_size,top);   // Perform pop operation and update the top value
        }
    }
    if(top == -1) 
    {
        
        printf("stack is empty");   // If top is -1 stack is empty
        return 0;
    }
    while(top!=-1)
    {
        printf("%d ",stack[top]);
        top = pop(stack,max_size,top);
    }
}