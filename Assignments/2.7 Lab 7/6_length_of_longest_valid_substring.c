/*
Length of longest valid sub-string - clone
Tags:	Data StructuresStack
Given a string consisting of opening and closing parenthesis, find the length of the longest valid parenthesis sub-string using the Stack.
Write a function:
        int solution(char S[])
that accept string S as input, find the length of the longest valid parenthesis sub-string using the stack and return the length.
Input
    ()(()))))
Output
    6
Here input contains ()(()) as a longest valid substring of parenthesis, hence 6.
Assume that,
Size of the string is within the range from 1 to 10000.
*/
#include <stdio.h>
#include <stdlib.h>

void solution(char* input)
{
    char *p = input;
    int result = 0;
    int size = 10000, flag = -1, len = 0;
    int *stack = malloc(size * sizeof(int));        // Creating a stack
    int *top = stack;                              // Pointer to stack
    while (*p != '\0')                             // Checking till end of expression
    {
        if(*p == '(')                             
        {
            if(top + 1 - stack >= size)           
            {
                size =size * 2;
                stack = realloc(stack, size* sizeof(int));
            }
            *top++ = p - input;
        } 
        else
        {
            if(top > stack)
            {
                if(--top == stack)
                {
                     len = p - (input + flag);
                } 
                else
                {
                    len = p - (input + *(top - 1));
                }
                if(len > result)
                {
                    result = len;
                }
            } 
            else
            {
                flag = p - input;
            }
        }
        p++;
    }
    printf("%d", result);
}

int main()
{
    char input[10000];
    scanf("%s", input);
	solution(input);
    return 0;
}