/*
0-1 Knapsack problem
Array
Given weight array and profit array of n items, put these items in a knapsack(bag) of capacity W to get the maximum total profit in the knapsack. In other words, given two integer arrays Profit [0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[ ] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).
Input:
    3
    10 20 30
    60 100 120
    50
    where:
First line represents the number of items.
Second line represents the array of weights of items.
Third line represents the array of profits from items.
Fourth line represents the maximum total allowable weight of the Knapsack(bag).
Output:
    220
Explanation: From the weight and the profit matrix above
weight = 10, profit = 60
weight = 20, profit = 100    
weight = 30, profit = 120  
        So to have maximum profit and total weight < = 50 we will select 2nd and 3rd item, such that weight = 20 + 30  = 50 and profit is 100 + 120 = 220. Hence the output 220.
Assumptions:
Number of items can be in the range 1 to 1000.
Elements of the weight and profit arrays can be in the range 1 to 1000.
*/
#include<stdio.h>

int main() 
{
    int n;
    scanf("%d",&n);
    int arr1[n]; 
    int arr2[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr2[i]);
    }
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr1[i]);
    }
    int W;
    scanf("%d",&W);
    int knap_sack[n+1][W+1];     // Declaring a 2d array with columns = total number of weights rows = total number of costs given.
    for (int i = 0; i <= n; i++) 
    {
      for (int j = 0; j <= W; j++) 
      {
         if (i==0 || j==0)
         {
            knap_sack[i][j] = 0;
         }
         else if (arr2[i-1] <= j)    // Calculate maximum weights accomdated for every combination of weights and profit and storing those in a 2d array.
         {
             if(arr1[i-1] + knap_sack[i-1][j-arr2[i-1]] > knap_sack[i-1][j])
             {
                 knap_sack[i][j] = arr1[i-1] + knap_sack[i-1][j-arr2[i-1]];    
             }
             else
             {
                 knap_sack[i][j] = knap_sack[i-1][j];
             }
         }
         else
         {
            knap_sack[i][j] = knap_sack[i-1][j];
         }
      }
   }
   printf("%d", knap_sack[n][W]);     // Printing the last element in the mthrow and nth column where we actually get the max profit obtained by above procedure
   return 0;
}