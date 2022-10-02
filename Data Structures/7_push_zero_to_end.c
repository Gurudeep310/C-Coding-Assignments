/*
Move all zeroes to end of array.
Given an array of random numbers, Push all the zero’s of a given array to the end of the 
array. For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed 
to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be same
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    int arr_new[N];
    for(int i = 0; i<N; i++)
    {
        scanf("%d",&arr[i]);
    }
    int count = 0;
    int index_new = 0;
    for(int i = 0; i<N ; i++)
    {
        if(arr[i] == 0)
        {
            count = count + 1;
        }
        else 
        {
            arr_new[index_new] = arr[i];
            index_new = index_new + 1;
        }
    }
    for(int i = 0; i<count; i++)
    {
        arr_new[index_new] = 0;
        index_new = index_new + 1;
    }
    for(int i = 0; i<N; i++)
    {
        printf("%d ",arr_new[i]);
    }
}