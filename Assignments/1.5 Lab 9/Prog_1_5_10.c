/*[L9 P10] Diagonal difference of a Matrix elements
Given a square matrix, find an absolute difference between sums of its diagonal elements. 
write a function solution that accept a two-dimensional (2D) array M as square matrix and size of the matrix N. The function should return absolute difference between sums of diagonals of M. 
Input 
    3 
    1 2 3 
    4 5 6 
    7 8 9 
    where, 
First line represents size of a matrix N. 
Second line represents array elements of a first row of matrix separated by space and so on. 
Output 
    0 
Here for the given matrix difference of diagonals will be 
(1+5+9) - (7+5+3) = 0 */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int n,sum=0,sum1=0;
    scanf("%d",&n);
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(i==j)
            {
                sum=sum+arr[i][j];
            }
            if(i==n-j-1)
            {
                sum1=sum1+arr[i][j];
            }
        }
    }
    printf("%d",sum-sum1);
    return 0;
}