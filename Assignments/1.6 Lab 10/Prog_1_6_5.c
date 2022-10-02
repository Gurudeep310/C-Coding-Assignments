/*[L10 P4] Decrementing the Pointer
Given a pointer to the last element of an integer array P and an integer offset value O, decrement the pointer by the given offset value and return the value at a new location. 
Write a function:
        int solution(int* P, int O)
that accepts a pointer P which points to last element of an integer array and integer variable O. The function should decrement the pointer by the given offset value and return value at a new location. 
Input
    10
    10 20 30 40 50 60 70 80 90 100 
    5 
    where, 
First line represents a number of array elements. 
Second line represents elements of an array. 
Third line represents the offset value. 
Output
    50
Assume that, 
Size of the array within the range [1 to 10000].
Array elements within the range [-32,768 to 32,767].*/

#include<stdio.h>

int solution(int* P, int O){  
    return *(P-O);    
}    

int main()
{
    int O, N;
    scanf("%d",&N);
    int P[10000] = {}; 
    
    for(int i=0; i<N; i++){
        scanf("%d",&P[i]);
    }
    
    scanf("%d",&O);
    printf("%d",solution(&P[N-1],O)); //&P[N-1] is the pointer to the last elem of the array P
     
}