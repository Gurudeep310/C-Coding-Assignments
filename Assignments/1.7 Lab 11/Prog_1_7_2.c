/*[L11 P2] Eval it like Python
In Python there is a crazy function called eval that works something like this: 
eval("1243") returns the integer 1243.
Write a program in C that where you define a function eval that takes a string suck as "1234" and returns an integer 1234.
Constraint: The input string may have at most 20 characters.*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int arr[10000],count=0;
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<=len;i++)                     //Converting a string of numbers to its ascii values
    {
        arr[i]=(int)str[i];
        count=count+1;
    }
    /*for(int i=0;i<count-1;i++)
    {
        printf("%d ",arr[i]);   
    }*/
    for(int i=0;i<count;i++)      //Converting back from ascii values to original numbers in int form
    {
        if(arr[i]==48)
        {
            arr[i]=0;
        }
        else 
        {
            arr[i]=arr[i]-48;
        }
    }
    for(int i=0;i<count-1;i++)
    {
        printf("%d",arr[i]);   
    }
    return 0;
}
