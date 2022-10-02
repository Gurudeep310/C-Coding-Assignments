/*Given a number N as input, find whether N is a perfect square or not using a function.
Write a function isPerfectSquare that accepts an integer N and returns 1 if N is perfect square otherwise 0.
Input:
    64    
    where:
First line represents a value of N
Output:
    1
Explanation: 42=64
*/

#include<stdio.h>
#include<math.h>
int isPerfectSquare(int s1,int n)
{
    if(s1==n)
        return 1;
    else
        return 0;
}
int main()
{
    long long n,k;
    int s1,s2;
    scanf("%lli",&n);
    k=sqrt(n);
    s1=k*k;
    printf("%d",isPerfectSquare(s1,n));
}