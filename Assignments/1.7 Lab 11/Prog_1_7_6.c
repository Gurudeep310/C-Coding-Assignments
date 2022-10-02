/*[L11 P7] Time difference
Given two structure variables of type “struct Time” (given below), Calculate the absolute difference between them. 
struct Time { 
    int hours; 
    int minutes; 
    int seconds; 
};  
Input 
    10  45  30 
    6    20  15 
    where, 
    First line of input represents startTime (hours, minutes, seconds) separated by single space. 
    Second line of input represents endTime (hours, minutes, seconds) separated by single space. 
Output 
    4:25:15 
*/

#include<stdio.h>
#include<math.h>

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

int main()
{
    struct Time t1;
    struct Time t2;
    struct Time diff;
    scanf("%d",&t1.hours);
    scanf("%d",&t1.minutes);
    scanf("%d",&t1.seconds);
    scanf("%d",&t2.hours);
    scanf("%d",&t2.minutes);
    scanf("%d",&t2.seconds);
    diff.hours=abs(t1.hours-t2.hours);
    diff.minutes=abs(t1.minutes-t2.minutes);
    diff.seconds=abs(t1.seconds-t2.seconds);
    printf("%d:%d:%d",diff.hours,diff.minutes,diff.seconds);
    return 0;
}