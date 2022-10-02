/*[Lab7] Display array elements in reverse order
Write a program takes N integers and stores them in an array Arr and prints the values in reverse order.
Input
    5 
    1 5 8 2 0 
    Where, 
The first line of input represents the size of an array. 
The second line contains array elements separated by a single space.
Output
    0 2 8 5 1  
Assume that, 
N is an integer within the range [0 to 100].
*/

#include<stdio.h>
int main()
{
    int i,j,n;
    scanf("%d",&n);
    if(n>=0 && n<=100)
    {
        int arr[n];
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        for(j=n-1;j>=0;j--)
            printf("%d ",arr[j]);
        return 0;
    }
}
