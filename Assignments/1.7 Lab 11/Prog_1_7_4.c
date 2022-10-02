/*[L11 P4] Determinant of an 3x3 matrix
Write a program that takes elements of a 3x3 matrix from the user and stores it in a 2D array. The program should further output the determinant of the matrix. Recollect that determinant of a 3x3 matrix is given as follows:*/

#include<stdio.h>
int main(){
    float arr[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%f",&arr[i][j]);
        }
    }
    float det=0;
     det= arr[0][0] * ((arr[1][1]*arr[2][2]) - (arr[2][1]*arr[1][2])) -arr[0][1] * (arr[1][0]
   * arr[2][2] - arr[2][0] * arr[1][2]) + arr[0][2] * (arr[1][0] * arr[2][1] - arr[2][0] * arr[1][1]);
    printf("%f",det);
    return 0;
    
    
}
