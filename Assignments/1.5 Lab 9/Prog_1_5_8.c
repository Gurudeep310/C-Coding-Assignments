/* [L9 P8] Find all the prime numbers in the array
Given an array of integers, find all the prime numbers in the array. 
Note: You can use the isPrime function from problem [L9 P5].
Input:
    5
    2 3 5 7 9
    where:
First line represents the number of elements in the array.
Second line represents the elements in the array.
Output:
    2 3 5 7*/

#include<stdio.h>
int prime(int n)
{
    int r=1;
    if(n==1)
    {
        r=0;
    }
    else
    {
        for(int i=2;i<=n/2;i++)
        {
            if(n%i==0)
            {
                r=0;
                break;
            }
        }
    }
    return r;
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(prime(arr[i]==1))
        {
            printf("%d",arr[i]);
        }
    }
    return 0;
}