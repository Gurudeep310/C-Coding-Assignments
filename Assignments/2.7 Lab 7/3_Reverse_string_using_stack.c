/*
Reverse string using stack - clone
Tags:	Data StructuresStack
Given a string, reverse it using the Stack.
Write a function:
        char* solution(char S[])
that accepts a string as input. The function should reverse the string using the Stack and return the reversed string.
Input
    Reverse the given String
Output
    gnirtS nevig eht esreveR
Assume that,
Size of the string is within the range 1 to 10000.
*/
#include<stdio.h>
#include<string.h>
#define BUFFERSIZE 2

int push(char new_s[],int top, char character, int max_length)   
{
    top = top + 1;                     // Incrementing top
    new_s[top] = character;            // Push character to stack
    return top;                        // Return top
}

int pop(char new_s[], int top, int max_length)
{
    printf("%c",new_s[top]);        
    top = top - 1;                   // Pop operation
    return top;
}
int solution(char *S)
{
    int top = -1;
    int x = strlen(S);
    char new_s[x];
    for(int i = 0; i<x; i++)
    {
        char character = S[i];
        top = push(new_s,top,character,x);
    }
    while(top!=-1) 
    {
        top = pop(new_s,top,x);
    }
    return 0;
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