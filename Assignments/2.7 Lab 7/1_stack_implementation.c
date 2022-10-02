/*
Stack Implementation - clone
Tags:	ArrayStackString
Create and implement an interface Stack. 
Stack interface has following methods
push with an input parameter of type String and void return type. 
pop with no parameter and void return type.
StringStack class has following characteristics
Must implement Stack interface.
printStack with no input parameters. The method should print stack data. 
push will insert a string in the string array and pop will remove the string.
If a stack is empty, print “Stack is empty” during pop.
If a stack is full, print “Stack is full”.  
Input
    3
    1
    First String
    Second String
    Third String
    where,
First line represents the number of strings to push.
Second line represents the numberer of strings to pop.
Third line represents the first string.
Fourth line represents the second string.
Fifth line represents the third string.
Output
    Third String
    Second String
    First String
    Second String
    First String
    where,
First three lines of output represent stack data after all the push operations.
Fourth and fifth line of output represents stack data after all the pop operation.
Assume that,
The maximum size of the stack is 10.
*/
#include<stdio.h>
#include<string.h> 
int push(char stack[][100],int top,char value[50]) 
{
    if(top==9) 
    {
        printf("Stack is full\n");
    }
    else 
    {
        top = top + 1;
        strcpy(stack[top],value);           // Pushing a string into stack
    }
    return top;
}

int pop(char stack[][100],int top)
{
    if(top==-1) 
    {
        printf("Stack is empty\n");
    }
    else 
    {
        top = top - 1;              // Pop operation in stack
    }
    return top;
}

int display(char stack[][100],int top) 
{
    if(top==-1) 
    {
        printf("Stack is empty\n");
    }
    else  
    {
        printf("%s",stack[top]);
        top = top - 1; 
    }
    return top;
}
int main()
{
    int n;                       // Number of push op
    int p;                       // Number of pop op
    int top = -1;
    scanf("%d",&n);
    scanf("%d",&p);
    char stack[10][100];        // Stack which will contain strings
    char value[50];             // var for taking a string value
    for(int i = 0; i<=n; i++)
    {
        fgets(value,50,stdin);   // Taking a string
        if(i!=0)
        { 
            top = push(stack,top,value);  // Pushing string 
        }
    }
    int g = top;
    
    // PRINTING AFTER ALL PUSH OPERATIONS
    if(top == -1) 
    {
         printf("Stack is empty\n");
    }
    else 
    {
        while(g!=-1) 
        {
            g = display(stack,g);
        }
    }
    
    //PERFORMING ALL POP OPERATIONS
    for(int i = 1; i<=p; i++)
    {
        top = pop(stack,top);               // performing pop
    }
    //PRINTING REMAINING ELEMENTS IN STACK AFTER ALL POP OPERATIONS
    if(top == -1) 
    {
         printf("Stack is empty");
    }
    else 
    {
        while(top!=-1) 
        {
            top = display(stack,top);
            if(top == -1) 
            {
                break;
            }
        }
    }
    return 0;
}
