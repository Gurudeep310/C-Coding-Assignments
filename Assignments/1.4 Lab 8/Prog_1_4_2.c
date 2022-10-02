/*[L8 P2] Push zero to front.
Given an array A, push all the zeros of the array to the front. The order of all other elements should remain same. 
Input 
    10 
    2 0 3 4 0 4 0 10 9 0 
    where,
First line represents size of an array N.
Second line represents array elements.
Output 
    0 0 0 0 2 3 4 4 10 9 */

#include<stdio.h>

int main()
{
    int n,count=0;
    scanf("%d",&n);
    int arr[n],arr1[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            count=count+1;
        }
    }
    //printf("\nNumber of Zero elements: %d",count);
    //printf("\nArray Modified: ");

    for(int i=0;i<n;i++)
    {
        if(i<count)
        {
            arr1[i]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0 && count<=n)
        {
            arr1[count]=arr[i];
            count=count+1;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr1[i]);
    }
}