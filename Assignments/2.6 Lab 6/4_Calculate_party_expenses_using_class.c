/*
Calculate party expenses using classes and object array
Tags:	ClassObject
Given a number of persons in the party (C), count of items for party (N) and party items details (like name, price, quantity) calculate expense for each item (price*quantity) and total party expenses. Also, calculate the amount each person will have to pay via dividing total expense with a count of persons(C) in the party using Classes and Object Array.
Input:
    6
    2
    Burger 100 5
    Pizza 200 6
    where,
First line represents count of persons in party (C)
Second line represents number of items (N)
Third line and onwards contains the details about party item like Name, price and quantity. 
Output:
    1700.00
    283.33
    Burger 500.00 
    Pizza 1200.00 
    where,
First line represents total expense of the party.
Second line represents amount each will have to pay.
Third line and onwards contains the details about party items like Name and total expense for that item.
*/
#include<stdio.h>
struct party 
{
    char name[50];
    float price;
    int quantity;
};

//Your program will be evaluated by this main method and several test cases.
int main()
{
    int c;
    scanf("%d",&c);
    int n;
    scanf("%d",&n);
    struct party arr[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%s",arr[i].name);
        scanf("%f",&arr[i].price);
        scanf("%d",&arr[i].quantity);
    }
    float total=0;
    for(int i = 0; i<n; i++)
    {
        total = total + (arr[i].price*arr[i].quantity);
    }
    printf("%.2f",total);
    float each = total/c; 
    printf("\n%.2f",each);
    for(int i = 0; i<n; i++) 
    {
        printf("\n%s %0.2f",arr[i].name,(float)(arr[i].price*arr[i].quantity));
    }
}