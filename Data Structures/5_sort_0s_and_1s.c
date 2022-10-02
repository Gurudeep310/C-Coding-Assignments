/*
Given an array which consists of only 0, 1 and 2. Sort the array without using any 
sorting algorithm. 
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    for(int i = 0; i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    int count_1 = 0;
    int count_2 = 0;
    int count_0 = 0;
    for(int i = 0; i<N;i++)
    {
        if(arr[i] == 0)
        {
            count_0 = count_0 + 1;
        }
        else if(arr[i] == 1)
        {
            count_1 = count_1 + 1;
        }
        else 
        {
            count_2 = count_2 + 1;
        }
    }
    int i = 0;
    for(int j = 0; j<count_0; j++)
    {
        arr[i] = 0;
        i = i + 1;
    }
    for(int j = 0; j<count_1; j++)
    {
        arr[i] = 1;
        i = i + 1;
    }
    for(int j = 0; j<count_2; j++)
    {
        arr[i] = 2;
        i = i + 1;
    }
    for(int i = 0; i<N; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}