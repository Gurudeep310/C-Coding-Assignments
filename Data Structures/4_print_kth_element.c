/*
Given an array Arr[] of N positive integers, find K largest elements from the array. 
The output elements should be printed in decreasing order
*/

#include <stdio.h>

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

int main(){
    int arr[20000]; //the arrays itself has 20000 elements. But we only use N slots.
    int N;
    scanf("%d", &N); //takes the size of the arrary from the user.
    for(int i = 0; i < N; i++){
        scanf("%d", &arr[i]);   //scans the elements of the array
    }   
    bubbleSort(arr, N); //Notice that we are passing the array name: which is in fact the pointer to the first element of the array.    
    for(int i = 0;i<N;i++)
    {
        printf("%d ",arr[i]);
    }
    int k;
    scanf("%d",&k);
    for(int i = N-k; i<N;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}