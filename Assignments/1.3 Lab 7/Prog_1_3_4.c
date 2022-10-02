/*[Lab7] Find the hidden number
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
//That element is nothing but average of all the elements
int main()
{
    int n,i,j,k,sum=0;
    float avg;
    scanf("%d",&n);
    if(n>-1000 && n<=1000)
    {
        int arr[n];
        for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        for(i=0;i<n;i++)
        sum=sum+arr[i];
        k=sum/n;
        float k1=(float)k;
        avg=(float)sum/n;
        if(avg==k1)
            printf("%d",(sum/n));
        else
            printf("-1");
    }
    return 0;
}