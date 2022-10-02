#include<stdio.h>

int main()
{
    int n,sum,flag=0;
    scanf("%d",&sum);
    scanf("%d",&n);
    long int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%ld",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(flag==0)
        {
            for(int j=i+1;j<n-1;j++)
            {
                if((arr[j]+arr[i])==sum)
                {
                    flag=1;
                    break;
                }
            }
        }
    }
    if(flag==1)
    {
        printf("%d",flag);
    }
    else
    {
        printf("%d",flag);
    }

}