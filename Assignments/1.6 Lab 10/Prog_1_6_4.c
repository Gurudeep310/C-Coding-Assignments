/*[L10 P3] Incrementing the Pointer
Given a pointer to an integer array P and an integer offset value O, increment the pointer by the given offset value and return the value at a new location. 
Write a function: 
        int solution(int* P, int O) 
that accept a pointer to an integer array P and integer offset value O. The function should increment the pointer by the given offset value and returns the value at the new location. 
Input
    10
    10 20 30 40 50 60 70 80 90 100 
    5 
    where, 
First line represents a size of an array. 
Second line represents an elements in the array. 
Third line represents an offset value. 
Output
    60 
Assume that, 
Size of the array within the range [1 to 10000].
Array elements within the range [-32,768 to 32,767].*/

#include<stdio.h>

int solution(int* P,int O){ //note that this function should return an int
    return *(P+O);
}

int main()
{
    int O, N;
    
    scanf("%d", &N);
    int P[10000] = {};
    
    for(int i=0; i<N; i++){
        scanf("%d", &P[i]);
    }
    scanf("%d", &O);    
    
    printf("%d",solution(P,O)); //P is the pointer to the first element of the array P
}