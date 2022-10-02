/*[Lab7] Sum except smallest and largest number
Given a list, find the sum of numbers excluding largest and smallest one. If there are multiple smallest value, exclude just one, and likewise for the largest value. 
Write a function solution that accepts a list. The function should return the sum of the list. 
Input
    9 
    4 3 6 8 9 2 1 5 9
    Where, 
First line represents the size of the list, N.
The second line represents list elements separated by single space. All the elements of the list should be on a single line.
Output
     37
For the given list largest and smallest values are 9 and 1 respectively.  Also, 9 is repeated two times hence excluding just one 9. 
Sum of remaining values =  (4 + 3 + 6 + 8 + 2 + 5 + 9) = 37
*/
#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    int arr[num];
    int i,min,max,sum=0,totsum=0;
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
     min=arr[0];
    for (i=0;i<num;i++) 
    {
        if (arr[i]<min) 
         min=arr[i];  //Gets minimum number of the array
    }
    max=arr[0];
    for(i=0;i<num;i++) 
    {
      if (arr[i]>max)
         max=arr[i]; //Gets maximum number of the array
    }
    for(i=0;i<num;i++)
    {
        sum+=arr[i];
    }
    totsum=sum-(max+min);  // Prints total sum of the array removing duplicates
    printf("%d",totsum);
}