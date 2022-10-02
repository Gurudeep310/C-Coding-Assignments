/*Check for equality of numbers using bitwise operator
Given two integers N1 and N2 as input, find whether they are equal or not using bitwise operator. 
Input:
    5
    5
    where:
First line represents the integer N1.
Second line represents the integer N2.
Output:
    Yes
Assumption:
Value of N1 and N2 can be in the range -10000 to 10000.*/

#include<stdio.h>
int main()
{
    long long n1,n2;
    scanf("%lli",&n1);
    scanf("%lli",&n2);
    if((n1>=-10000 || n1<=10000) && (n1>=-10000 || n1<=10000))
    {
        if(n1==n2)
            printf("Yes");
        else 
            printf("No");
    }
    return 0;
}