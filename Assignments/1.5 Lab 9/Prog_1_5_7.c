/*[L9 P7] Largest gap in an array
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
Array element can be in the range -1000 to 1000.*/

#include<stdio.h>
int main()
{
    int arr[1000],n,max=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;i<n;j++)
        {
            if(((arr[i]-arr[j]))>=max)
            {
                max=arr[i]-arr[j];
            }
        }
    }
    printf("%d",max);
    return 0;
}