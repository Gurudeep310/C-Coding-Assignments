/*
Given a year, determine whether it is a leap-year or not. 
Reference to determine whether a year is a leap year or not: https://www.mathsisfun.com/leap-years.html
Display the output according to the following condition:
1 if the value represents a leap year.
2 if the value does not represent a leap year.
3 if the value is less than 1 or greater than 9999.
Input 
    2000 
Output 
    1 
Here, 2000 is a leap year because it is divisible by 100 as well as 400.*/

#include<stdio.h>
int main()
{
    //write your code here
    int a;
    scanf("%d",&a);
    if(a<1 || a>9999)
    {
        printf("3");
    }
    else if((a%4 && a%100!=0) || a%400==0)
    { 
        
        //{
            printf("1");
        //}
        //else if(a%400==0 && a%4==0)
        //{
          //  printf("1");
    }
    else
    {
        printf("2");
    }
    
}