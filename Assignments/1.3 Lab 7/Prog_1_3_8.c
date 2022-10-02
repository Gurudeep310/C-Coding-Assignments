/*[Lab7] Check if the string is a Palindrome
A string is said to be a palindrome if the original string and the reverse of the string are the same. MALAYALAM is a plaindrome (see why?) 
Write a program that takes a string (character array) and displays 1 if string is palindrome else 0. 
Hint: This can be solved without using any library functions. But do Google for string.h and learn how to use the funciton strlen in case you want to.
Input
    level 
Output
    1 
Assume that, 
The length of string S is within the range [0 to 10000].
*/

#include<stdio.h>
#include<string.h>
int main()
{
    char str[10000];
    int i,j=0,k,len;
    scanf("%s",str);
    len=strlen(str); //Takes the length of the string
    for(i=0;i<len;i++)
    {
        if(str[i]!=str[len-i-1])   //checks if the first letter in the string is not to last letter in the string
            j=1;
    }  
    if(j==1)
        printf("0");
    else
        printf("1");
    return 0;
}

/*
      OR
#include<stdio.h>
#include<string.h>
int main()
{
    char str[10000];
    int i,j,k;
    scanf("%s",str);
    //if(str>'0' && str <='10000')
    {
        if(str==strrev(str))
            printf("1");
        else
            printf("0");
    }  
    return 0;
}*/