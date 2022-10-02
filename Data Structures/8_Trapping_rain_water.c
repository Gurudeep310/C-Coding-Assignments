/*
Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar 
is 1, compute how much water it is able to trap after raining
*/
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    int arr_1[N];
    int arr_2[N];
    int arr_3[N];
    for(int i = 0; i<N; i++)
    {
        scanf("%d",&arr[i]);
    }
    int max_start = arr[0];
    int max_end = arr[N-1];
    //arr_1[0] = arr[0];
    for(int i = 0; i<N; i++)       // Calculate max from LHS to RHS and storing each comparision in arr_1
    {
        if(max_start<arr[i])
        {
            max_start = arr[i];
        }
        arr_1[i] = max_start;
    }
    for(int i = N-1; i>=0; i--)  // Calculate max from RHS to LHS and storing each comparision in arr_2
    {
        if(max_end<arr[i])
        {
            max_end = arr[i];
        }
        arr_2[i] = max_end;
    }
    for(int i = 0; i<N; i++)        // Getting minimum of element in each position and storing in arr_3
    {
        if(arr_1[i]<arr_2[i])
        {
            arr_3[i] = arr_1[i];
        }
        else 
        {
            arr_3[i] = arr_2[i];
        }
    }
    for(int i = 0; i<N;i++)       // Subtracting the minimum from the array given to us to find empty places above the blocks to store water.
    {
        arr[i] = arr_3[i] - arr[i];
    }
    int sum = 0;
    for(int i = 0; i<N; i++)    // Calculating total droplets that can be stored.
    {
        sum = sum + arr[i];
    }
    printf("the number units of water that can be stored between the blocks is %d",sum);
    return 0;
}