/*Given an integer N as input, where N is the age of a person, check whether the person is eligible for voting or not. Display "Yes" if he/she is eligible for voting otherwise "No".
Input:
    55
    where:
First line represents the integer N, here N is the age of a person
Output:
    Yes
Explanation:
As N=55 satisfies the condition N>=18 as 18 is the minimum age required for eligibility to vote, hence the output "Yes".
Assumption:
Value of N can be a positive integer.
*/
#include<stdio.h>
int main()
{
unsigned int N;
printf("\n");
scanf("%d",&N);
if(N>=18)
{
    printf("\nYes");
}
else
{
    printf("\nNo");
}
}