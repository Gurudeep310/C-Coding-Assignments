/*[L9 P6] Count repeated character in string
Given a string S, count the repeated character(s). 
Write a function: 
        int countRepChars(char S[ ])
that accepts string S. The function should return the count of repeated characters('A' to 'Z' and 'a' to 'z').
Input
    repeatedchar 
Output 
    3 
Here in the given string a, e and r characters are repeated. 
Assume that: 
The length of String S within the range [1 to 2,0000] 
The character comparison will be case-sensitive. */

#include<stdio.h>
#include<string.h>

int countRepChars(char S[])
{
    int r=0;
    int len=strlen(S);
    int freqarr[256];
    for(int i=0;i<len;i++)
    {
        if(S[i]>='a' && S[i]<='z' || S[i]>='A' && S[i]>='Z')
        {
            int count=0;
            for(int j=i+1;j<len;j++)
            {
                if(S[i]==S[j])
                {
                    count=count+1;
                    S[j]='0';
                }
            }
            if(count>0 && S[i]!='0')
            {
                r=r+1;
            }
        }
    }
    return r;
}

int main()
{
    char givenString[20000];
    scanf("%s",givenString);
    printf("%d",countRepChars(givenString));
    return 0;
}