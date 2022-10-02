/*
Given an array of n integers where each value represents the number of 
chocolates in a packet. Each packet can have a variable number of chocolates. There are 
m students, the task is to distribute chocolate packets such that: 
1. Each student gets one packet.
2. The difference between the number of chocolates in the packet with maximum 
chocolates and packet with minimum chocolates given to the students is minimum.
Examples:
Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3 
Output: Minimum Difference is 2 
Explanation:
We have seven packets of chocolates and we need to pick three packets for 3 students 
If we pick 2, 3 and 4, we get the minimum difference between maximum and minimum packet 
sizes.
*/
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

void bubbleSort(int* arr, int size)
{
    int temp=0;
    while(1 == 1)
    {
        int flag=0;
        for(int i=0;i<size-1;i++)//Go through all the elements
        {
            if(arr[i]>arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                flag=flag+1;
            }
        }    
        //If you find any consecutive elements such that arr[i] > arr[i+1] swap them.
        //If you don't find any swap-worthy pairs at all: you are done, break from the while loop
        if(flag==0)
        {
            break;
        }
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    int arr[N];
    int arr_1[N-1];
    for(int i = 0; i<N; i++)
    {
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr, N);       // Sorting
    int m;
    scanf("%d",&m);
    for(int i = 0; i<N; i++)          // Subtracting consecutive elements to get minimum difference and storing in arr_1
    {
        arr_1[i] = arr[i+1] - arr[i];
    }
    printf("Minimum difference is %d",arr_1[m-1]-arr_1[0]);   //Priting minimum difference
    return 0;
}