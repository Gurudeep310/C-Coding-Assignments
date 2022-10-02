/*[L10 P2] Add two numbers using pointers
Given two integers as input, add them using pointers.
Input:
    23
    12
    where:
First line represents the first integer.
Second line represents the second integer.
Output:
    35
*/

#include<stdio.h>

int main()
{
    int a,b;
    int* p=&a;
    int* q=&b;
    int sum;
    scanf("%d",&a);
    scanf("%d",&b);
    sum= *p+*q; //Using dereferencing operator to get the values stored in a and b instead of adding address
    printf("%d",sum);
    return 0;
}