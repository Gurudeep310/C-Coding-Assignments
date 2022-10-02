/*[L11 P5] Evaluate the continued fraction
Have a look at the following continued fraction.
- If you evaluate the value of this for depth = 1,  the answer is 4/(1 + 12) which is 2.
- If you evaluate this for depth = 2, the answer is 4/(1 + 12 /(2 + 32) which is 3.666666666... 
Write a program that takes depth as input and output the value of the expression computed to that depth. LET THE OUTPUT BE ACCURATE ONLY TO 10 DECIMAL VALUES.*/

#include<stdio.h> 
#include<math.h>
int main()
{ 
long long int depth ;  
    scanf("%lld" , &depth);  //scanning the depth 
    double c = 1 ;//counter variable
    for(int i =depth ; i >=1; i--){ 
    long double a = 2*i-1;//performing the math 
        int b = (long int)pow(a,2); 
        //typecasting it to long int
        if(i==depth) 
        {c = b/c ;} 
        //repeat the fraction
      else if (i<depth)
        { c = b/(2+c);}
    } 
    //adding the top and printing the frac 
    double ans = 4/(1+c); 
    printf("%0.10lf" , ans);
}