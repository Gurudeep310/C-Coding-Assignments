/*
Read a 2D-array
Tags:
ArrayMatrix
Write a function to read values of a number of rows, number of columns, 2 dimensional (2D) array elements and display the 2D array in a matrix form.
Input 
    2 
    3 
    1 4 5 
    2 3 0 
    Where, 
First line of represents the number of rows.  
Second line of input represents the number of columns.  
Third line contains array elements of the 1st row and so on. 
Output 
    1 4 5 
    2 3 0
    where
There must be single space between 2 numbers in the row.
There should not be any space after the last number in the row. e.g. in the 2nd row, there should not be any space after number 0. 
Assume that, 
Row and column values are integers within the range [1 to 100]. 
2D Array elements are within the range [-2147483648 to 2147483647].
*/
#include<stdio.h>
int main()
{
    int m = 0;
    int n = 0;
    scanf("%d",&m);
    scanf("%d",&n);
    int arr[m][n];
    for(int i = 0; i<m;i++)
    {
        for(int j = 0; j<n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i = 0; i<m;i++)
    {
        for(int j = 0; j<n; j++)
        {
            if (j == n-1)
            {
                printf("%d",arr[i][j]);
            }
            else
            {
                printf("%d ",arr[i][j]);
            }
        }
        printf("\n");
    }
}
