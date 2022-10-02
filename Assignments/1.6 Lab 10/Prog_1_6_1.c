/*[L10 P0] Modify value stored in variable using pointer in C
Given is an integer variable, change the value of this integer using pointers.
Step 1: Store value 5 in integer variable a.
Step 2: Create integer pointer p that stores address of a.
Step 3: Accept a value using pointer p.
Step 4: Display the updated value of the variable a.
Input:
    23
    where:
Input represents the value took in step 3 using pointer p.
Output:
    23
Explanation: Output displays the changed value of the variable a.*/

#include<stdio.h>

int main()
{
    int a=5;
    //scanf("%d",&n)
    int* p=&a;
    scanf("%d",p);  //NOTE THIS no need &p only p
    printf("%d",a);
}