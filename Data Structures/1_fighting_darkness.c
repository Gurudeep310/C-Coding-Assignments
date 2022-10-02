/*
Given an array arr[] of size N representing the size of candles which reduce by 1 unit 
each day. The room is illuminated using the given N candles. Find the maximum number of 
days the room is without darkness.
Input: Array of size n with some positive value in each cell
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// Idea: Find max size of candles.
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    } 
   int max = arr[0];
   for(int i = 0;i<n;i++)
   {
       if(max<arr[i])
       {
           max = arr[i];
       }
   }
   printf("Maximum days the room with be without darkness is: %d",max);
}