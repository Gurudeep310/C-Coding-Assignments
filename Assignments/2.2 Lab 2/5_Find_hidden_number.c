/*
Find the hidden number
Tags:
ArrayDynamic Programming
Given an array of integers, find another integer such that, if all the elements of the array are subtracted individually from that number, then the sum of all the differences should add to 0. If any such integer exists, print its value otherwise print '-1'.
Input:
    3
    1 2 3
    where:
First line represents the number of elements in the array.
Second line represents the elements in the array.
Output:
    2
Explanation: Substracting all the elements of arrays from 2, The sum of difference is: 1 + 0 + (-1) = 0.
Assumptions:
Array can be of size 1 to 1000.
Array elements can be in the range -1000 to 1000.
*/
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int hidden_number = 0;
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum = arr[i] + sum;
    }
    hidden_number = sum/n;
    printf("%d",hidden_number);
}