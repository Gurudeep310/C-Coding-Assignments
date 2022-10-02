/*
Display perfect square numbers in an array
Tags:
Array
Given an array of integers A and size of array N. Write a program to display only those numbers in an array that are perfect squares. 
Write a function:
    void solution(int A[], int N)
that accepts an array of integer A and size of array N. The function should display numbers in array those are a perfect square. If there is no perfect square number present in an array then print 0.
Input
    10
    8 2 3 4 16 9 5 6 25 10 
    where,
First line represents value of N.
Second line represents array elements.   
Output
    4 16 9 25
Note: Print the numbers separated by single space. Do not print space after the last element.
Assume that,
N is an integer within the range [1 to 10000]
Array elements are integers within the range [1 to 10000].
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void solution(int *A, int N)
{
    int count = 0;
    int flag = 0;
    int new_array[N];
    int num = 0;
    float square = 0;
    for(int i = 0; i<N; i++)
    {
        square = sqrt((double)A[i]);
        num = square;
        if( num == square)
        {
            new_array[count] = A[i];
            count = count + 1;
            flag = 1;
        }
    }
    if (flag != 1)
    {
        int x = 0;
        printf("%d",x);
    }
    else{
        for(int i = 0; i<count ; i++)
        {
            printf("%d ",new_array[i]);
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