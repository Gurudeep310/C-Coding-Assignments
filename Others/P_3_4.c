/*Given an integer N as input, find whether it is even or not using bitwise operator.
Input:
    50
    where:
First line represents the integer N.
Output:
    Yes
Assumption:
Value of N can be in the range 0 to 10000.
*/

#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    if(num>=0 && num<=10000)
    {
        if(num%2==0)
            printf("Yes");
        else
            printf("No");
    }
    return 0;
}