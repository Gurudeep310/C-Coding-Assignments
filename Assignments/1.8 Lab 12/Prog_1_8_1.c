/*[L12 P1] Average of numbers stored in the files.
You are given 40 files with random names. 
Each file contains a number n. In fact each file only contains the number in the first line and nothing else.
For example the file BIDIKQ2696WG865HFGXO.txt contains only one line "95808".
Write a program that takes a bunch of file names and
outputs the integral value of the average of the numbers stored in them.
outputs -1 is any of the given filesnames is non-existant.
ASSUME: File names don't contain spaces.
Example 1:
Input:
6
FED6M580HXNOEGOY0.txt
FWO735O5FE4.txt
G9PEHJSVGES5G.txt
GAH8BUJNO72XEHNIGOF9.txt
LV4Z0M7HUG9ARO5.txt
LWAXJYQ5RZ5L.txt
            where: the first line is the number of files 
                       followed by the names of different files
Output:
57352
Explanation:  The numbers contained in the given 6 files are 41142, 45848, 79196, 56874, 66004, 55049. The integral value of their average can be seen to be: 57352
Example 2:
Input:
2
LV4Z0M7HUG9ARO5.txt
bhanu.txt
FWO735O5FE4.txt
Output:
-1
Explanation:  bhanu.txt is a nonexistant filename. So the program outputs -1 and terminates.
Constaints:
1) Every file name at max contains 30 characters.
2) All the numbers inside the files fall within the range 30000 <= n <= 100000
Hint:
You do not need any other file operations than fopen and fscanf to solve this problem.*/

#include<stdio.h>
int main()
{
    FILE *fp;
    char filename[100];
    int num=0;
    float sum=0;
    int nof=0;//number of files
    scanf("%d",&nof);
    for(int i=1;i<=nof;i++)
    {
        scanf("%s",filename);
        fp=fopen(filename,"r");
        if(fp==NULL)
        {
        printf("-1");
        return -1;
        }
        fscanf(fp,"%d",&num); //Scanning numbers in from file and assigning it to num
        sum=sum+num;
        fclose(fp);    
    }
    int avg=(int)(sum/nof); // calculate the average.
    printf("%d",avg);
    return 0;
}