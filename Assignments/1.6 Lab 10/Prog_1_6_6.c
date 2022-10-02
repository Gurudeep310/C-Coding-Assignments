/*[L10 P5] Swap two numbers with call by reference
Given two integer pointers P1 and P2. Interchange values of P1 and P2, using call by reference.
Input
    4 10 
    where
First number represents value at P1 pointer. 
Second number represents value at P2 pointer.
Output
    10 4 
Assume that, 
Values pointed by P1 and P2 pointers are integers within the range [-2,147,483,648 to 2,147,483,647].*/

#include<stdio.h>

int main()
{
    int a,b;
    int* p=&a;
    int* q=&b;
    scanf("%d",&a);
    scanf("%d",&b);
    int temp=*p;
    *p=*q;
    *q=temp;
    printf("%d %d",*p,*q);
    return 0;
      
}