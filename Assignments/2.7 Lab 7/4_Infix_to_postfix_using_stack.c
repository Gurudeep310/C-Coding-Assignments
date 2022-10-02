/*
Infix to postfix conversion using stack - clone
Tags:	StackData Structures
Given an infix expression, convert it to postfix expression using stack.
Reference: csis.pace.edu/~wolf/CS122/infix-postfix.htm
Write a function:
        char* solution(char* IEXP)
that accept infix expression IEXP as a string. The function should return postfix expression string. If IEXP not valid then return “Invalid Expression”.
Note: Expression is invalid if parentheses are not balanced in expression. 
    e.g. IEXP = “a+b*((a/b)” 
    Here one parentheses ')' is missing in expression.
Input
    a+b*c/(a-b^c)
    where,
The first line of input represents an expression as a string.
Output
    abc*abc^-/+
Note: Precedence order of operators are ^, *, /, +, - (from higher to lower).
Assume that,
The expression contains only operands, operators and parentheses.
Possible operands are within the range ['a' to 'z'] and ['A' to 'Z'].
Possible operators are '^', '*', '/', '+' and '-' .
Possible parentheses are '(' and ')'.
Length of expression is in the range from [1 to 10000] 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define BUFFERSIZE 2

char stack[20];
int top = -1;
void push(char x) 
{
    top = top + 1;
    stack[top] = x; 
}

char pop()
{
    if(top==-1) 
        return -1; 
    else 
        return stack[top--];
}

int priority(char x)          // Assigning numerical priorities to symbols
{
    if(x=='(')               // Priority of ( is 0
        return 0;
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/')
        return 2;
}

void solution(char *S)
{
    char *e,x;
    e = S;     // Pointer to an array 
    while(*e!='\0')         // Reads untill null character is encountered
    {
        if(isalnum(*e))        // Checks if char is alphabet or numeric
            printf("%c",*e);
        else if(*e=='(')       // Checks if its (
            push(*e);
        else if(*e == ')')     // Checks if its )
        {
            while((x=pop())!='(') // Prints or pops everything in stack untill all elements in () are popped out
                printf("%c",x);
        }
        else 
        {
            while(priority(stack[top]) >= priority(*e)) //Checks if symbol in stack has higher priority than the character 
            {
                printf("%c",pop());                    // Is its higher then pop top
            }
            push(*e);                                 // If not then push character
        }
        e++;
    }
    while(top!=-1) 
    {
        printf("%c",pop());                       // Print rest of elements in the stack
    }
}

//Your program will be evaluated by this main method and several test cases.
int main()
{
    char *S,buffer[BUFFERSIZE];
    S = (char*)calloc(1,1);
	fflush(stdin);
	while( fgets(buffer, BUFFERSIZE , stdin) )
	{
		S = realloc( S, strlen(S)+1+strlen(buffer) );
		if(S!=NULL && strcmp(buffer,"\n")!=0){
			strcat( S, buffer ); 
		}
		
        if(strcmp(buffer,"\n")==0)
			break;
	}
	solution(S);
    return 0;
}