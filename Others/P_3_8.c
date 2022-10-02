/*Star Pattern - Rectangle Star pattern
Given two integers N1 and N2, display the Rectangle Star pattern as described in output. 
Input:
    5
    3
    Where:
First line represents the value of N1( number of rows ).
Second line represents the value of N2( number of columns ).
Output:

    * * *

    * * *

    * * *

    * * *

    * * *
*/

#include<stdio.h>
int main()
{
    int n1,n2,i,j,k;
    scanf("%d",&n1);
    scanf("%d",&n2);
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            if(j==(n2-1))
                printf("*");
            else
                printf("* ");
        }
            
        printf("\n");
    }
    return 0;
}


