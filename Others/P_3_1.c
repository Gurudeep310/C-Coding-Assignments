/*Check for uppercase characters
Given a string S, check whether all characters are in uppercase or not 
Input:
    HELLO
    where:
First line represents the input string
Output:
   Yes
Input:
    Hello
Output:
    No
Assumptions:
Length of the string S can be 0 to 10000
The string S contains [A...Z, a...z]. */

#include<stdio.h>

void main()
{
    char str[10000];
    int a,i,flag=0;
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++)
    a=i;
    for(int i=0;i<=10000;i++)
    {
        if(str[i]>='A' && str[i]<='Z')
            flag++;
        else
            flag=0;
    }
    if(flag==1)
        printf("Yes");
    else
        printf("No");
}