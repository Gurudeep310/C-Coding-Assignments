/*Given a positive integer, find factorial of it. 
Reference: https://en.wikipedia.org/wiki/Factorial
Use the for loop.
Input:
    5
Output:
    120
For N = 5, factorial of 5 (5!) = 5 * 4 * 3 * 2 * 1 = 120
Assume that, 
Value of N can be in the range from [0 to 20]*/

#include<stdio.h>
int main()
{
    long int i,number;
    long int fact=1;
    scanf("%ld",&number);
    for(i=1;i<=number;i++)
    {
        fact=fact*i; 
    }
    printf("%ld",fact);
    return 0;
 }