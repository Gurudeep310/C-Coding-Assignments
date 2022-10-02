/*Given an array of integers, find the sum of its elements.
Input 
    5 
    1 2 3 4 5 
    Where, 
The first line of input represents the size of the array. 
The second line contains the array's elements, separated here by a single space.
Output 
    15 
Here the given input array is [1 2 3 4 5]
Sum of elements of array = 1 + 2 + 3 + 4 + 5 = 15. 
*/
#include<stdio.h>
int main()
{
    long long n,i,j,sum=0;
    scanf("%lli",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);   //gets input for every element
    for(j=0;j<n;j++)
        sum=sum+arr[j];     //calculates sum
    printf("%lli",sum);       //prints sum
    return 0;
}