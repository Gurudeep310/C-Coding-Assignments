/*
Maximise the number of toys that can be purchased with an amount K
Tags:	Array
Given an array consisting of the cost of toys. Given an integer K depicting the amount of money available to purchase toys. Write a program to find the maximum number of toys one can buy with the amount K.
Input:
    10
    1 12 5 111 200 1000 10 9 12 15
    50
    where:
First line represents the number of elements in the array.
Second line represents the elements in the array(cost array).
Third line represents the value of K.
Output:
    6
Explanation: Toys with amount 1, 5, 9, 10, 12, and 12 can be purchased resulting in a total amount of 49( 49 <50 ). Hence, maximum number of toys is 6.
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d",&k);
    int total = 0;
    int count = 0;
    for(int i = 0; i<n; i++)
    {
        if(total<=k)                      // Checking we have balance to buy
        {
            if((total+arr[i])<=k)        // Checking if we can afford to buy.
            {
                count = count + 1;
                total = total + arr[i];      
            }
        }
    }
    printf("%d",count);
    return 0 ;
}