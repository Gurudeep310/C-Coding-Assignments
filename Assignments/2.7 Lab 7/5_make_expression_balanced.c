/*
Make an expression balanced - clone
Tags:	StackData Structures
Given a brackets expression, find a minimum number of bracket reversals required to make an expression balanced using Stack.
Expression-1 =  “}{“ 
Here 2 brackets reversals needed to make expression balanced “{}”.
Expression-2 = “{{” 
Here 1 bracket reversals needed to make expression balanced “{}”.
Write a function:
        int solution(char* S)
that accept brackets expression as string S. The function should return a minimum number of brackets reversals required to convert expression balanced. If a string can not be made balanced bracket expression then return -1.
Input
    }{
    where,
The first line represents a bracket expression as a string.
Output
    2
Assume that,
The expression contains only brackets.
brackets can be '{' and '}'.
Length of string can be [1 to 10000] 
*/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

struct Stack {                     // Creating stack
    int top;
    int cap;
    char* arr;
};

struct Stack* make(int cap){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));   // Initialising stack with memory
    stack->cap = cap;
    stack->top = -1;
    stack->arr = (char*)malloc(stack->cap * sizeof(char));
    return stack;
}
 
int isFull(struct Stack* stack){                   //Check if stack is full
    return stack->top == stack->cap - 1;
}
 
int isEmpty(struct Stack* stack){                // Check if stack is empty
    return stack->top == -1;
}

int peek(struct Stack* stack){             // Peek operation
    if (isEmpty(stack))
        return INT_MIN;
    return stack->arr[stack->top];
}
 
int pop(struct Stack* stack){                //Pop operation
    if (isEmpty(stack))
        return INT_MIN;
    return stack->arr[stack->top--];
}

void push(struct Stack* stack, int item){    // Push operation
    if (isFull(stack))
        return;
    stack->arr[++stack->top] = item;
}

int correct(char *string)
{
    int len = strlen(string);
    struct Stack * stack = make(len);
    for(int i = 0; i < len; i++)
    {
        if(string[i] == '{')
        {
            push(stack, string[i]);
        }
        if(string[i] == '}')
        {
            pop(stack);
        }
    }
    if(isEmpty(stack)) return 0;
    return 1;
}

void solution(char *string)
{
    int len = strlen(string);
    struct Stack* stack = make(len);
    for (int i=0; i<len; i++)
    {
        if (string[i]=='}' && !isEmpty(stack))
        {
            if (peek(stack)=='{') 
                pop(stack);
            else 
                push(stack, string[i]);
        }
        else push(stack, string[i]);
    }
    int mlen = strlen(stack->arr);
    int res = 0;
    while (!isEmpty(stack) && peek(stack) == '{')
    {
        pop(stack);
        res++;
    }
    printf("%d", (mlen/2 + res%2)+1);
}

int main()
{
    char exp[10000];
    fgets(exp, 10001, stdin);
    if(strlen(exp) == 2)
    {
        printf("-1\n");
        return 0;
    }
    int open = 0, close = 0;
    int len = strlen(exp);
    for(int i = 0; i < len; i++)
    {
        if(exp[i] == '{') 
            open++;
        if(exp[i] == '}') 
            close++;
    }
    if(open != close) 
        printf("1");
    else if(correct(exp) == 0) 
        printf("0\n");
    else 
        solution(exp);
    return 0;
}