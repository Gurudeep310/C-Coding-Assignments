/*
Find the Union and Intersection of the two sorted arrays not containing 1 element 
twice
*/
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr_1[n];
    int arr_2[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr_1[i]);
    }
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr_2[i]);
    }

    int union_op[2*n];
    int index_union = 0;
    int index_intersection = 0;
    int intersection_op[2*n];
    for(int i = 0; i<n; i++)
    {
        union_op[i] = arr_1[i];
        index_union = index_union + 1;
    }
    for(int i = 0; i<n;i++)
    {
        int count = 0;
        int x = arr_2[i];
        for(int j = 0; j<n; j++)
        {
            if(x == union_op[j])
            {
                count = count + 1;
            }
        }
        if(count==0)
        {
            union_op[index_union] = x;
            index_union = index_union + 1;
        }
        else 
        {
            intersection_op[index_intersection] = arr_2[i];
            index_intersection = index_intersection + 1;
        }
    }
    printf("union:");
    for(int i = 0; i<index_union; i++)
    {
        printf("%d ",union_op[i]);
    }
    printf("intersection:");
    for(int i = 0; i<index_intersection; i++)
    {
        printf("%d ",intersection_op[i]);
    }
    return 0;
}