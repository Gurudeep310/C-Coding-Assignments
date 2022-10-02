/*[L9 P2] Print numbers in a range using recursion
There can be functions that don't return anything at all. Technically we say such function return a void. In C a void is a small piece of data which doesn't store any information in it. We use suck functions to printout stuff. For example, the following function takes an array and the size of the array as inputs and produces nothing fruitful. Nevertheless as a nice side effect it prints the elements of the array in a sequence:
void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d", arr[i]);
        if(i != size - 1){
                printf(", ");
           }
        printf("\n");
        }
    return;
}
---------------------------- 
Now, suppose you are given two positive integers N1 and N2. You can create a void function printNums that recursively prints all the numbers between N1 and N2 in the order. The funciton can be inductively defined as follows:
printNums(N1, N2) :   if N1 > N2  return;
                                                otherwise  print N1 and return printNums(N1+1, N2);
Input:
    16
    25
    where:
First line represents a value of N1
Second line represents number N2
Output:
    16 17 18 19 20 21 22 23 24 25*/

#include<stdio.h>
void printNums(int N1,int N2)
{
    if(N1>N2)
    {
        return;
    }
    else
    {
        printf("%d ",N1);
        return printNums(N1+1,N2);
    }
}

int main()
{
    int N1,N2;
    scanf("%d",&N1);
    scanf("%d",&N2);
    printNums(N1,N2);
    return 0;
}