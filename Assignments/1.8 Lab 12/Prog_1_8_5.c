/*[L12 P5] Reading matrix from a file
Consider the following 4x4 matrix:
-2 -5 -1 -8 
1 10 8 -4 
0 -4 -10 1 
3 5 7 -2 
The trace of this matrix is (sum of elements in principle diagonal) -2 + 10 - 10 - 2 = -4 
Write a program that takes the name of a file that contains the elements of a 4x4 matrix and prints its trace.
If the filename is non-existant, the program whould print "UNKNOWN" and terminate.
Example:
Input:
matrixFile.txt
Output:
-4
ASSUME: filenames contain no spaces.
              length of the filenames is < 50
*/

#include <stdio.h>

int main(){
    int matrix[4][4]; 
    int filename[50];
    scanf("%s",filename);
    FILE* fp=fopen(filename, "r");
    if(fp==NULL)
    {
         printf("UNKNOWN");
         return 0;
    }
    //Transfers elements from file to matrix form
    for(int i=0;i<4;i++)
    {
         for(int j=0;j<4;j++)
         {
                fscanf(fp,"%d",&matrix[i][j]);
         }
     }
    //Find Trace of the Matrix
    int sum=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(i==j)
            {
              sum=sum+matrix[i][j];
            }
        }
     }
    printf("%d",sum);
    return 0;
}