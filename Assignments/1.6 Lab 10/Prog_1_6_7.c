/*[L10 P6] Bubble Sort
Sorting
+ Sorting is a big deal in programming.
  - Why?
  - If you sort, you can search faster!
  - Remember binary search? It is possible only when you sort the elements of an array in monotonic order.
+ There are several ways (algorithms) of sorting a given set of elements.
  - .. some algorithms that are easy for humans to understand, but takes the computer longer to execute.
  - .. some algorithms that are hard for humans to understand, but takes the computer less time to execute.
+ We will look a method that is easy for humans to understand. 
Bubble sort
+ This is one of the easiest algorithms to understand. 
+ Suppose you have an array of elements:  6,5,3,1,8,7,3,4
+ We can sort it (to ascending order - smallest to the largest) by the following method
  - Traverse through the array and consider the elements pairwise.
  - If you notice a pair of adjacent elements  such that right element being smaller than the left element, 
       swap them.
  - else
        leave them alone
  - Go through the array again and again (and perform these swaps wherever possible)
  - When no more swaps are possible, stop it. You have sorted the array already!
+ Observe the following animation to see this process in action.

Define a function  void bubbleSort(int arr, int size); that takes the (pointer to the first element of the) array and modifies the array to sorted form.
Example
Input:
6
1 3 4 5 6 2
Where the first line takes the number of elements in the array N.
The second line takes the elements of the array.
Output:
1 2 3 4 5 6
*/

//sort in descending order

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
            /*for(int i=0;i<size;i++)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");*/
        }    
        //If you find any consecutive elements such that arr[i] > arr[i+1] swap them.
        //If you don't find any swap-worthy pairs at all: you are done, break from the while loop
        //WRITE YOUR CODE HERE
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
    for(int i = 0; i < N; i++){  //a simple for loop to print the elements of the array after the bubbleSort function is invoked.
        printf("%d ", arr[i]);
    }  
    return 0;
}