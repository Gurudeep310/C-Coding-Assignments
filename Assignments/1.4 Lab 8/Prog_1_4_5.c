/*[L8 P5] Elements of array that are not multiples of 5
Given an array of integers, display the elements of array which are not multiples of 5
Input:
    6
    2 3 4 11 22 320
    where:
First line represents the number of elements in the array.
Second line represents the elements in the array.
Output:
    2 3 4 11 22
Explanation: Element of the array 320 is the only one in the array which is a multiple of 5, so it is removed.
Assumptions:
Array can be of size from 1 to 1000.
Array element can be in the range -1000 to 1000.*/


#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]%5!=0)
        {
            printf("%d ",arr[i]);
        }
    }
    return 0;
}