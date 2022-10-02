/*[L13 P3] Create and display a matrix using array of pointers
Given two integers M and N, write a program to create and display a M X N matrix using an array of pointers.
Input:
    3
    3
    1 2 3
    2 3 4
    3 4 5
    where:
First line represent M, the number of rows.
Second line represent N, the number of columns.
Third to fifth lines represent the elements in the matrix.
Output:
    1 2 3
    2 3 4
    4 5 6
*/

#include<stdio.h>

int main()
{
    int rows,columns;
    scanf("%d",&rows);
    scanf("%d",&columns);
    int arr[rows][columns];
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            printf("%d ",*(*(arr+i)+j));
        }
        printf("\n");
    }
    return 0;
}