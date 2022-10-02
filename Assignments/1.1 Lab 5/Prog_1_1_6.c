/*Given two integers N1 and N2, write a program to display a number based on following conditions:
0 if N1 is 5 and N2 is 2.
1 if N1 is 5 and N2 is not 2.
2 if N1 is not 5 and N2 is 2.
3 if N1 is not 5 and N2 is not 2. 
Use nested-if-else statement.
Input
    5 
    4 
Output
    1 
Here, N1 = 5 and N2 != 2. Hence, the result is 1 according to the given conditions.*/
#include<stdio.h>
int main()
{
    long int N1,N2;
    scanf("%ld",&N1);
    scanf("%ld",&N2);
    if(N1==5)
    {
        if(N2==2)
            printf("0");
        else
            printf("1");
    }
    else
    {
        if(N2==2)
            printf("2");
        else
            printf("3");
    }
}    