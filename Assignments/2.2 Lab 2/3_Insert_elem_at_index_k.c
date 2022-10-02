/*
Insert an element at index 'K'
Tags:
Array
Given an array of integers, write a program to insert an element X at index K.
Input:
    5
    10 20 30 40 50
    15
    1
    where:
First line represents the number of elements in the array.
Second line represents the elements in the array.
Third line represents element X to be inserted.
Fourth line represents the index K, where the element is to be inserted.
Output:
    10 15 20 30 40 50
Explanation: Output displays the elements of the array after inserting the element X=15 at index K=1.
*/
#include<stdio.h>
int main()
{
    int n;
    int x;
    int k;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&x);
    scanf("%d",&k);
    for(int i = n; i>k;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[k] = x;
    n = n + 1; 
    for(int i = 0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
}