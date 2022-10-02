/*
Number of unique pairs in an array
Tags:
Array
Given an array of N elements, find all the unique pairs that can be formed using the elements of a given array.
Input:
    3
    1 1 2
    where:
First line represents the number of elements in the array.
Second line represents the elements in the array.
Output:
    4
Explanation: (1, 1) (1, 2) (2, 1) and (2, 2) are all the unique pairs, their count is 4, hence the output 4.
*/
//the number of unique pairs would be x**2
#include<stdio.h>
int main()
{
    int n,j,k;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                arr[j]=0;
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
            count=count+1;
    }
    printf("%d",count*count);
}