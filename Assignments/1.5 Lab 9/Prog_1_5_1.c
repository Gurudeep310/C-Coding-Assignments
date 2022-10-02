/*[L9 P1] Product using recursion
Q. How can mutliplication of two posive integers be defined inductively?
Ans: Something like should do
           multRecur(m,n) : 0                     if m is zero
                           n                     if m is 1
                           n+multRecur(m-1, n)   otherwise.
Create a function that accepts integers m and n. The function should return product of m and n using recursion. 
Input:
    20
    15
    where:
First line represents number m
Second line represents number n
Output:
    300*/

#include<stdio.h>
int recurMult(int m,int n)
{
    if(m==0)
    {
        return 0;
    }
    else if(m==1)
    {
        return n;
    }
    else
    {
        return (n+recurMult(m-1,n));
    }
}

int main()
{
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    printf("%d",recurMult(m,n));
    return 0;
}