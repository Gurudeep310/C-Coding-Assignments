/*[L11 P3] Bubble sort with a twist
Remember Bubble sort from the last lab?
https://en.wikipedia.org/wiki/Bubble_sort
Write a program to sort n elements of an array in ascending order of their magnitude (using Bubble sort algorithm) and repalces all the duplicate entries. That is, your program should only output the unique values in the array in ascending order.
Input:
6
1 7 1 3 4 1
        where: the first line takes N: the no. of elements in the array
                   the second line takes the elements.
Output:
1 3 4 7
*/

#include<stdio.h>
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
            /*for(int i=0;i<size-1;i++)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");*/
        }    
        if(flag==0)
        {
            break;
        }
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    //FILTERING
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                arr[j]=9285;
            }
        }
    }
    //printf("\nAfter Filter 1\n");
    /*for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");*/ //CHECKED AND WORKED
    //FILTERING 2
    int arr2[n],count2=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=9285)
        {
            arr2[count2]=arr[i];
            count2=count2+1;
        }
    }
    n=count2;
    /*for(int i=0;i<n;i++)
    {
        printf("%d ",arr2[i]);
    }
    printf("\n");*/ //CHECKED AND WORKED
    bubbleSort(arr2, n); 
    return 0;
}



