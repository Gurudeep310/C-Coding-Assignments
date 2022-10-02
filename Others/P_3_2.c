/*Given a number N as input, find whether N is a perfect square or not using a function.
Write a function that accepts an integer N. The function should return 1 if N is perfect square otherwise 0.
Input:
    64    
    where:
First line represents a value of N
Output:
    1
Explanation: 42=64*/

#include<stdio.h>
#include<math.h>
int main()
{
    long long n,k;
    int s1,s2;
    scanf("%lli",&n);
    k=sqrt(n);
    s1=k*k;
    if(s1==n)
        printf("1");
    else
        printf("0");
    return 0;
}