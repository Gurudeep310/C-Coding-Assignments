/*[Lab7] Find larger of the two
Given two integers N1 and N2, find the maximum between them using a function. 
Write a function that accepts integers N1 and N2. The function should return the maximum of N1 and N2. 
Input:
    20
    15
    where:
First line represents a value of N1
Second line represents a value of N2
Output:
    20
*/
#include<stdio.h>
int large(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);           
    printf("%d",large(a,b));    //Call fun large and display number
    return 0;
}