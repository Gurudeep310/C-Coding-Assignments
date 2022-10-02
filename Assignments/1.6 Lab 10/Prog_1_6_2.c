/*[L10 P1] Average random numbers
rand() is a function that can be accessed by including the library file stdlib.h.
This function will produce a random integer from the range [0, RAND_MAX]. 
We have seen also that this function can be cleverly used to produce a random number within a specified range [min, max] where a and b are integers. 
This can be achieved through the expression: rand()%(max - min + 1) + min
Write a program that produces desired number of random numbers and finds the average of the random values. To make sure all your computers produce the same sequence of random numbers, insert srand(12345) in the main function. Output the average only up to 3 decimal values.
Example:
Input:
13 31 10
13 is the value of min
31 is the value of max
10 is the number of random numbers to be generated N
Output:
23.700
Note 1: Do you notice that when N is very large the answer turns out to be very close to (min+max)/2 ? Can you explain why?
Note 2: Codezinger uses gcc-9 compiler. If your computer has gcc-10 the sequence of random number may be different on your computer.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    srand(12345);
    int min, max, N;
    float avg=0;
    int sum=0;
    scanf("%d %d %d", &min, &max,  &N);
    for(int i=0;i<N;i++)
    {
        int k=rand()%(max-min+1)+min;
        sum=sum+k;
    }
    avg=(float)sum/N;
    printf("%0.3f",avg);
    return 0;
}

