/*
Largest gap in an array
Array
Given an array of N integers, find the largest gap between any two elements of the array.
In simple words, find max(|Ai-Aj|) where 0 ≤ i < N and 0 ≤ j < N.
Input:
    4
    3 6 7 10 
    where:
First line represents the number of elements in the array.
Second line represents the elements in the array.
Output:
    7
Explanation: Here, the largest gap can be found between 3 and 10 which is 10 - 3 = 7, hence the output 7.
Assumptions:
Array element can be in the range -1000 to 1000.
*/
#include<stdio.h>
int main()
{
    int n = 0;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int max = arr[0];
    int min = arr[0];
    for(int i = 0; i<n; i++)
    {
        if(max <= arr[i])
        {
            max = arr[i];
        }
        if(arr[i] <= min)
        {
            min = arr[i];
        }
    }
    int gap = max - min;
    printf("%d",gap);
    
}