/*[L9 P3] Check Palindrome number using recursion
Given an integer N, find whether N is a Palindrome using recursion. 
Write a function that accepts an integer N. The function should return 1 if N is a palindrome else 0. 
Input:
    121 
Output:
   1
The reverse of 121 is also 121.
Assume that, 
N is an integer within the range [0 to 1000000000]. */

#include<stdio.h>
#include<math.h>

int reverse(int N,int r)
{
    if(N==0)
    {
        return 0;
    }
    r=(r*10)+(N%10);  //Stores reverse of a number.
    return reverse(N/10,r);
}

int main()
{
    int N;
    scanf("%d",&N);
    if(N==reverse(N,0))
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
    return 0;
}