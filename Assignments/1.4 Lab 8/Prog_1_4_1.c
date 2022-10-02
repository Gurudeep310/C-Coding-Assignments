/*[L8 P1] Odd occurrence of element in an array
Given an array of positive integers A, check the array for the odd occurrence(s) of at least one element.
Display 1 if an array has odd occurrences of at least one element otherwise 0.
Input 
    12 
    1 2 3 4 5 1 2 3 4 5 6 7 
    Where, 
First line contains size of array N. 
Second line contains array elements. 
Output 
    1 
Here for the given array, all elements of array repeated an even number of times except 6 and 7. Hence output is 1.*/


#include<stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    if(n==0)
    {
        printf("0");
    }
    else
    {
        int arr[n];
        int c[n];
        
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            c[i]=0;
        }
        
        /*
        for(i=0;i<n;i++)
        {
        printf("%d ",arr[i]);
        }
        
        printf("\n");
        */
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i]==arr[j])
                {
                c[i]++;
                }
            }
            if(c[i]%2==1)
            {
                printf("1");
                break;
            }
        }
        
        /*
        printf("Count: \n");
        for(i=0;i<n;i++)
        {
        printf("%d ",c[i]);
        }
        */
        
        int count_even = 0;
        for(i=0;i<n;i++)
        {
            if(c[i]%2==0)
            {
                count_even++;
            }
        }
        
        if(count_even == n)
        {
            printf("0");
        }
    }    
}
/*#include<stdio.h>

int main()
{
    int n,count,min=0,a;
    scanf("%d",&n);
    int arr[n],max=n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=j+1;j<n-1;j++)
        {
            if(arr[j]==arr[i])
            {
                count=count+1;
                printf("\n Count: %d",count);
            }
            printf("\n Count: %d",count);
        }
    }
    
    printf("\nMAx: %d",max);
    printf("\n Min: %d",min);
}*/