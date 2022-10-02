/*[Lab7] Sum of distinct elements
Given an array of N integers, find the sum of all the distinct elements of the array.
Elements of the array would be in the range of 1 to N.
Input:
    9
    5 1 2 4 6 7 3 6 7
    where:
First line represents the number of elements in the array.
Second line represents the elements in the array.
Output:
    28
Explanation: The distinct elements in the array are 1, 2, 3, 4, 5, 6, and 7,
                       Hence their sum: 1+2+3+4+5+6+7 = 28, so the output is 28.*/

/*IDEA: For every element, check if there is another element present or not whose value is the same and has an index less than the current index. If there is no such element, add the current element to the answer otherwise skip it*/
//FROM WEB SOURCE

#include<stdio.h>
int main()
{
    int n,i,j,k,sum=0,flag=0;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==i)        //If it has same index then it is a new value and not a duplicate 
            {
                sum=sum+arr[j];
            }
            if(arr[i]==arr[j])  //If both index has same elements ignore and dont calculate sum.
            {
                break;
            }
        }
    }
    printf("%d",sum);
}