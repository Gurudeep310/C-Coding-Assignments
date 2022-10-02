/*
Check whether bookings are possible
Tags:
Array
Given two arrays for arrival and departure dates of same size N, find whether the advance booking is possible or not.
A hotel manager has to process N advance bookings. His hotel has K rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand.
Input:
    5
    1 7 8 10 11
    9 8 15 16 17
    3
    where:
First line represents the number of bookings, N.
Second and third lines represent the arrival and departure date arrays respectively.
Fourth line represents the number of rooms in the hotel, K.
Output:
    Yes
Explanation: First room is booked on 1st. Now there are two vacant rooms.
                       Second room is booked on 7th. Now there is one vacant room.
                       Third room is booked on 8th. Now there is no vacant room.
                       Second room is vacated on 8th. Now there is one vacant room.
                       First room is vacated on 9th. Now there are two vacant rooms.
                       First room is booked on 10th. Now there is one vacant room.
                       Second room is booked on 11th. Now there is no vacant room.
                       Since all bookings were possible, hence the output 'Yes'. 
Assumptions:
Dates of arrival or departure can be in the range 1 to 30.
*/
#include<stdio.h>
int main()
{
    int n;
    int k;
    scanf("%d",&n);
    int arr1[n];
    int arr2[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr1[i]);
    }
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr2[i]);
    }
    scanf("%d",&k);
    int arr3[k];
    int overlap = 0;
    // Note: Arrays are sorted.
    // Fail case: When arrival at kth date is is lesser then departure of ith date.
    for(int i = 0; i<sizeof(arr1);i++)
    {
        if (arr1[i+k]<arr2[i])
        {
            printf("No");
            overlap = overlap + 1;
            break;
        }
    }
    if(overlap==0)
    {
        printf("Yes");
    }
}