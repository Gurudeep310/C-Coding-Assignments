/*
Find sum of array elements using pointer
Tags:
Pointer
Given a pointer to an array of integer elements and the number of elements in the array, find the sum of elements. 
Write a function: 
    long solution(int *A, int N) 
that accepts a pointer to an array of elements and the size of the array. The function should return the sum of the array elements. 
Input
    5 
    1 2 3 4 5 
    Where, 
The first line represents the size of an array.
The second line represents array elements.
Output
     15
Assume that, 
N is within the range [1 to 100].
*/
#include<stdio.h>
#include<stdlib.h>

long solution(int *A,int N)
{
    long int sum = 0;
	for(int i = 0; i<N; i++)
    {
        sum = sum + *(A+i);
    }
    return sum;
}

int main()
{
    int *A,N,i;
    scanf("%d",&N);
    A = (int*) malloc(N * sizeof(int));
    for(i=0; i<N; i++)
        scanf("%d",&A[i]);
    printf("%ld",solution(A,N)); 
}