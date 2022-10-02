/*[L10 P7] Compare two strings without using system library functions
Given two strings S1 & S2, compare without using system library function. String comparison happens character by character based on the ASCII value of a character. 
Display integer value based on following conditions. 
1 if S1 is greater than S2. 
-1 if S2 is greater than S1. 
0 if S1 is equal to S2. 
Input
    Hello world 
    Hello world 
Where, 
The first line of input represents string S1. 
The second line of input represents string S2. 
Output
    0 
Assume that, 
Length of strings S1 & S2 are in the range [0 to 10000] 
Strings S1 & S2 contains characters in the range [A...Z a...z] */

/*#include<stdio.h>
#include<string.h>

int main()
{
    char s1[10000],s2[10000];
    scanf ("%[^\n]%*c",s1);
    scanf ("%[^\n]%*c",s2);
    if(strlen(s1)>strlen(s2))
    {
        printf("1");
    }
    else if(strlen(s2)>strlen(s1))
    {
        printf("-1");
    }
    else
    {
        printf("0");
    }
    return 0;
}*/

//OR

#include<stdio.h>
#include<string.h>

int main()
{
    char s1[10000],s2[10000];
    scanf ("%[^\n]%*c",s1);
    scanf ("%[^\n]%*c",s2);
    int count=0,flag=0;
    int i=0;
    while(s1[i]!='\0')
    {
        count=count+1;
        i=i+1;
    }
    int j=0;
    while(s2[j]!='\0')
    {
        flag=flag+1;
        j=j+1;
    }
    if(count>flag)
    {
        printf("1");
    }
    else if(count<flag)
    {
        printf("-1");
    }
    else
    {
        printf("0");
    }
    
}
