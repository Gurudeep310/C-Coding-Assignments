/*Check if numbers are pythagorean triple
Given three integers A, B and C. Write a program to find out if the number is a Pythagorean triple.
Write a function:
    int solution(int A, int B, int C)
that accept three integer A, B and C. The function should return 1 if the given integers are Pythagorean triple else 0.
Input
    3
    4
    5
    where,
First line represents the value of A.
Second line represents the value of B.
Third line represents the value of C.
Output
    1
Assume that,
A, B and C are integers within the range [1 to 2,147,483,647].
*/

#include<stdio.h>
int solution(int A, int B, int C)
{
    if((A>1 || A<2147483647) && (B>1 || B<2147483647) && (C>1 || C<2147483647))
    {
        int k,l;
        k=((A*A)+(B*B));
        l=(C*C);
        if(k==l)
            return 1;
        else
            return 0;
    } 
}

int main()
{
    int A, B, C;
    scanf("%d%d%d",&A, &B, &C);
    printf("%d",solution(A, B, C));
    return 0;
}