/*[L9 P5] Product of Prime Frequencies of Characters in a String
Given string S containing only lowercase English alphabets, find the product of all the prime frequencies of the characters in S.
Input:
    abaccdcdbbbd
    where:
First line represents input string S
Output:
    18
Explanation:
Only characters a, c,d have prime frequencies and product of their frequencies=2*3*3=18*/

//THIS WORKS EXCEPT TO LAST TEST CASE

#include<stdio.h>
#include<string.h>

int isPrime(int n)
{
    if(n==1)
    {
        return 0;
    }
    int half=n/2;
    for(int i=2;i<=half;i++)  //if any number between 2 and n/2 divides n, you say n is not prime.
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;//Otherwise n is prime.
}

int main()
{
    char s[100]; //assume the length of the string <100
    scanf("%s",s); //scan the string and put it in s
    int k=strlen(s);
    int freqarr[k+1],l=0,count;
    for(int i=0;i<k;i++)
    {
        count=0;
        for(int j=0;j<i;j++)
        {
            if(s[i]==s[j])
            {
                count=count+1;
            }
        }
        printf("\n Number of times %c got repeated is %d",s[i],count);
        freqarr[l]=count;
        l=l+1;
    }
    printf("\n Elements in l are: ");
    for(int i=0;i<l;i++)
    {
        printf("%d ",freqarr[i]);
    }
    int pro=1;
    for(int i=0;i<l;i++)
    {
        int m=isPrime(freqarr[i]);
        if(m==1 && freqarr[i]!=0)
        {
            pro=pro*freqarr[i];
        }
    }
    printf("\n%d",pro);
}