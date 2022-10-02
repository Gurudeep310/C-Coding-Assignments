/*Given a coordinate point P(x, y) in an X-Y coordinate system as an input, determine in which quadrant the coordinate point lies.
print '1' if point is in 1st quadrant.
print '2' if point is in 2nd quadrant.
print '3' if point is in 3rd quadrant.
print '1' if point is in 4th quadrant.
point (0, 0) is the origin, print '0' for origin.
Input:
    12
    4
    where:
First line represents the x-coordinate of the point.
Second line represents the y-coordinate of the point.
Output:
    1
Explanation:
Point (12, 4) lies in 1st quadrant, hence the output 1.
*/
#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    if(a<0 && b<0)
        printf("3");
    else if(a<0 && b>0)
        printf("2");
    else if(a>0 && b<0)
        printf("1");
    else if(a>0 && b>0)
        printf("1");    
    else if(a==0 && b==0)
        printf("0");
    return 0;
}