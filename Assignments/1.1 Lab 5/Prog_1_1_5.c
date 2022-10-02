/*Given a number N, print natural numbers in reverse from N to 1.
Input:
    10
    where:
First line represents value of N.
Output:
    10 9 8 7 6 5 4 3 2 1
Assumptions:
N can be in the range 1 to 1000.*/

#include<stdio.h>
int solution(int N)
{
    //write your code here
    for(int i=N; i>1; i--)
    {
        printf("%d ", i);
    }
    return 1;
    
}
//Your program will be evaluated by this main method and several test cases.
int main()
{
    int N;
    scanf("%d",&N);
    printf("%d",solution(N));
}