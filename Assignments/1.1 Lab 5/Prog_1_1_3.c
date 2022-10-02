/*Given is an integer, which represents the amount as an input from the user, display the minimum number of notes $ (500, 100, 50, 20, 10, 5, 2, 1) required for the amount.
Input:
    575
    where:
Input is the amount for which we have to calculate the number of notes.
Output:
    4
Explanation: Total amount = 1(500 dollar note) + 1(50 dollar note) + 1(20 dollar note) + 1(5 dollar note) = 575, hence the minimum number of notes required is 4.*/

#include <stdio.h>

int main()
{
    int amount;
    int note500, note100, note50, note20, note10, note5, note2, note1;
    int number;
    note500 = note100 = note50 = note20 = note10 = note5 = note2 = note1 = 0;   
    //printf("Enter amount: ");
    scanf("%d", &amount);
    while(amount >= 500)
    {
        note500 = amount/500;
        amount -= note500 * 500;
    }
    while(amount >= 100)
    {
        note100 = amount/100;
        amount -= note100 * 100;
    }
    while(amount >= 50)
    {
        note50 = amount/50;
        amount -= note50 * 50;
    }
    while(amount >= 20)
    {
        note20 = amount/20;
        amount -= note20 * 20;
    }
    while(amount >= 10)
    {
        note10 = amount/10;
        amount -= note10 * 10;
    }
    while(amount >= 5)
    {
        note5 = amount/5;
        amount -= note5 * 5;
    }
    while(amount >= 2)
    {
        note2 = amount /2;
        amount -= note2 * 2;
    }
    while(amount >= 1)
    {
        note1 = amount;
    }
    number=note500+note100+note50+note20+note10+note5+note2+note1;

    /* Print required notes */
    printf("\n%d",number);
    return 0;    
}