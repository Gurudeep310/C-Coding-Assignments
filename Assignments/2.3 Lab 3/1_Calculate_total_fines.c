/*
Calculate total fines
Tags:
Array
Given an integer denoting day of month and an array of integers representing number-plates of cars traveling on that day, calculate total fines applied as per the following rules
Odd numbered cars can ply on odd days without incurring fine.
Even numbered cars can ply on even days without incurring fine.
An even numbered car plying on an odd day or an odd numbered car plying on an even day is fined $250/occurrence.
Input:
    4
    3 4 1 2
    15
    where:
First line represents number of elements in array
Second line represents number-plates of the cars in the array
Third line represents the day
Output:
    500
Explanation: Car with number-plate '4' and '2' will be fined $250 each, totaling $500. Hence output is 500.
Assumptions:
Array can be of size 1 to 1000
Array elements can be in range -1000 to 1000
Day can be in range 1 to 31
*/
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int date;
    int fine=0;
    scanf("%d",&date);
    for(int i = 0; i<n; i++)
    {
        if(date%2 != 0)                // Checking if date is odd
        {
            if(arr[i]%2 == 0)         // Fining cars if it has number plate is even.
            {
                fine = fine + 250;
            }
        }
        else 
        {
            if(arr[i] %2 != 0)       // Checking if date is even
            {
                fine = fine + 250;   // Fining cars if it has number is even.
            }
        }
    }
    printf("%d",fine);
    return 0;
}