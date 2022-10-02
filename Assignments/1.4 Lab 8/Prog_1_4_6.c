/*[L8 P6] Segregation of even and odd numbers in an array.
Given an array of integers in random order. Segregate even numbers on the left side and odd numbers on the right side of the array.
Input:
    10
    0 3 4 11 223 4 44 7 8 9
    where:
First line represents the number of elements in the array.
Second line represents the elements in the array.
Output:
    0 4 4 44 8 3 11 223 7 9
Explanation: Output displays the array which contains all the even numbers segregated to the left and odd numbers to the right, according to their occurance
Assumptions:
Array can be of size from 1 to 1000.
Array elements can be in the range -1000 to 1000.*/

#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n],arr1[n],counte=0,counto=0,count=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    /*for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            counte=counte+1;
        }
        else
        {
            counto=counto+1;
        }
    }
    printf("\n Number of even num: %d",counte);
    printf("\n Number of odd no: %d",counto);*/
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            arr1[count]=arr[i];
            count=count+1;
        }
    }
    /*printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr1[i]);
    }*/
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2!=0)
        {
            arr1[count]=arr[i];
            count=count+1;
        }
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr1[i]);
    }
}