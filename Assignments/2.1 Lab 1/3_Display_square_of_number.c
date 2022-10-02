/*
Display square of number in array
Array
Given an array of integers A and size of an array N. Write a program to display the square of each number in the array. 
Write a function:
    void solution(int A[], int N)
that accepts an array of integer A and size of array N. The function should display square of each number in the array.
Input
    10
    1 2 3 4 5 6 7 8 9 10
    where,
First line represents a value of N.
Second line represents array elements.  
Output
    1 4 9 16 25 36 49 64 81 100
Note: Print the numbers separated by single space. Do not print space before first and after last element.
Assume that,
N is an integer within the range [1 to 10000].
Array elements are integers within the range [1 to 10000].
*/
#include<stdio.h>
#include<stdlib.h>
void solution(int *A, int N)
{
    for(int i = 0; i<N;i++)
    {
        A[i] = A[i] * A[i];
    }
    for(int i = 0; i < N; i++)
    {
        if(i== N-1)
        {
            printf("%d",A[i]);
        }
        else{
            printf("%d ",A[i]);
        }
    }

}

int main()
{
    int *A,N,i;
    scanf("%d",&N);
    A = (int *)malloc(sizeof(int)*N);
    for(i=0;i<N;i++)
        scanf("%d",&A[i]);
    solution(A,N);
    return 0;
}