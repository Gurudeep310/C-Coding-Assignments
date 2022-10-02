/*[L8 P4] Find Majority Element
Given a list of integers, find the Majority Element.
Write a function solution that accepts a list L. The function should return the element if it is a Majority Element in the list otherwise 0. 
Input
    5 
    1 2 1 2 2
    Where, 
First line of input represents the size of the list . 
Second line contains list of elements separated by single space. All the elements of the list should be on a single line.
Output
    2 
Here for the given array element '2' is appears 3 times in the array of size 5.*/

#include<stdio.h>

int main()
{
    int n,count,m,max=0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        count=0;
        {
            for(int j=0;j<n;j++)
            {
                if(arr[j]==arr[i])
                {
                    count=count+1;
                }
                if(count>max)
                {
                    max=count;
                    m=arr[i];

                }
            }
        }
        if(max>n/2)
        {
            printf("%d",m);
        }
        else
        {
            printf("0");
        }
    }
    return 0;
}