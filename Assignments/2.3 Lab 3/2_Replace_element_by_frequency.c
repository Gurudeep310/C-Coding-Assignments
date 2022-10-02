/*
Replace every element of an array by its frequency
Tags:
Array
Given an array of integers, replace every element by its frequency in the array.
Input:
    6
    1 2 5 2 2 5
    where
First line represents the number of elements in the array.
Second line represents the elements in the array.
Output:
    1 3 2 3 3 2
Explanation: In the array, the element 1 has occurred only once so it's frequency is 1. Element 2 has occurred thrice so its frequency is 3, and element 5 has occurred twice so its frequency is 2.
Assumptions:
Array element can be in the range -1000 to 1000.
*/
#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    int A[N];
    for(int i = 0; i<N; i++)
    {
        scanf("%d",&A[i]);      // Scanning Array
    }
    for(int i = 0; i<N; i++)
    {
        int count = 0;
        int x = A[i];
        for(int j = 0; j<N;j++)
        {
            if(A[j] == A[i])       // Equating an element of an array with other elements in the same array and calculating its frequencies.
            {
                count = count + 1;  
            }
        }
        printf("%d ",count);                // Printing the array which is updated with frequecies of elements that were replaced respectively.
    }
}