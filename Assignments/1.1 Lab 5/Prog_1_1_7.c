/*Given GENDER (1 for male and 0 for female) and AGE of a person, find the discount applicable using nested if-else statements.
 Write a program to display discount based on following conditions::
If the age of a male is less than or equal to 15, discount is 20 or 15 if the age is greater than 15.  
If the age of a female is less than or equal to 15, discount is 30 or 25 if the age is greater than 15.
Use nested if-else statement.
Input 
    1 
    30 
   where, 
The first line of input represents GENDER. 
The second line of input represents AGE. 
Output 
    15 
Here, gender is male and age is greater than 15. Hence, the discount will be 15.
Assume that, 
GENDER is an integer that can be 0 or 1.  
AGE is an integer within the range [1 to 99].*/

#include<stdio.h>
int main()
{
    int gen,age;
    scanf("%d",&gen);
    scanf("%d",&age);
    if(gen==1)
    {
        if(age<=15)
            printf("20");
        else
            printf("15");
    }
    else if(gen==0)
    {
        if(age<=15)
            printf("30");
        else
            printf("25");
    }
    
}