/*
[L11 P1] Crazy Math.
If you try evaluating the following in C, It will throw an error. (What kind of error?)
printf("%d", 1++-1--+1-----1+1);
Python is a crazy language. If you go to a Python temrinal and type the following:
>>> 1++-1--+1-----1+1
Rather than insulting us with an error message, it produces the answer: 1
Q) How?
A) It basically evaluates 1-1+1-1+1
Q) How?
A) When there are even no. of +'s and a single - before 1  it counts as -1.
     When there are even no. of -'s and a single + before 1  it counts as +1.
and so on.
    Basically something like 1---+1 is interpreted as 1-(-(-(+1))).
Now, write a C program that takes a string as shown in the above example, and produces the required output.
Constraints:
The string always ends with 1.
The maximum length of the string is 1000.
Additional challenge (not for grading): Python can also evaluate expressions such as ---+13---++1-333++++--11+555. How can you modify your code to make it work for expressions like these?
*/

#include<stdio.h>
#include<string.h>
#define ll unsigned long long int

int main()
{
    char hachu[2000];
    scanf("%s",hachu);
    ll sum =0;
    int op=1;// stores which operation to perform
    for (int i=0; i<strlen(hachu);)
    {
        if (hachu[i]=='-')
        {
            op*=-1;
            i++;
        }
        else if (hachu[i]=='+')
            i++;
        else if ((hachu[i]>='0' && hachu[i]<='9'))
        {
         
         ll num=0;
          while((hachu[(i)]>='0' && hachu[(i)]<='9'))
          {
          num = num*10 + (hachu[(i)]-48);
          ++(i);
          }//converting string to integer
            sum = sum + op*num;
            op=1;
        }
    }
    printf("%lld",sum);
}