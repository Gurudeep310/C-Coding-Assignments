/*
Delete an array element at index 'K'
Tags:
Array
Given an array of integers, write a program to delete the element at index K.
Input:
    5
    10 20 30 40 50
    1
    where:
First line represents the number of elements in the array.
Second line represents the elements in the array.
Third line represents the value of index K.
Output:
    10 30 40 50
Explanation: Output displays the elements of the array after deleting the element at index K=1.
*/
#include<stdio.h>
int main()
{
    int n;
    int k;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&k);
    for(int i = k; i<n;i++)
    {
        arr[i] = arr[i+1];
    }
    n = n - 1;
    for(int i = 0; i<n;i++)
    {
        printf("%d ",arr[i]);
    } 
}