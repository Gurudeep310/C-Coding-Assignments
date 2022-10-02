/*[L12 P3] Simple string search - 2
The string "bhanu" is a substring of "kilogrambhaanukilobhanukilogram". The reason is fairly intuitive which is that the string "bhanu" occurs from index 18 to index 23.
But how to programmatically check if a given small piece of string (called query) is part of a larger string (called source) along with locations at which they occur?
Modify your solution for "Simple string search - 1" such that the source string is read from a text file. Therefore the input of the program has to be the name of the file, and the second input has to the query string.
ASSUME neither the source string, not the query string has spaces.
Example 1: 
Input:
"somefilename.txt"
"cab"
    where: the first line is source
               the second line is query
               assume there are not spaces in source of query
Output:
7
15
Example 2:
Input:
"myawesomefile.txt"
"tommy"
Output:
NO
Constraints:  0 < no. of chars in query < 50
                    0 < no. of chars in file name < 50
                   0 < no. of chars in source inside the file < 10000
HINT: 1) You only need fscanf or fgetc to solve this problem.
         2) You can use strlen() function from string.h if you want although it's not necessary.
*/

#include <stdio.h>
#include <string.h>
int main()
{
    char filename[50];
    char query[50];// = "bhanu";
    char source[10000];// = "bhanuabhanucdfxyzbhanu";
    //DUMP your code here.
    int k=0,count=0;
    scanf("%s",filename);
    scanf("%s",query);
    FILE *fp=fopen(filename, "r");
    fscanf(fp,"%s", source);
    char *ptr = strstr(source,query);
    if(ptr == NULL) 
    {
        printf("NO\n");
        return 0;
    }
    for (int i=0;source[i]!='\0'; i++,k++) 
    {
        count=0;
        for(int j=0;query[j]!='\0';j++) 
        {
            if(source[i]==query[j]) 
            {
                count=count+1;
                i=i+1;
            }
            else
            {
                break;
            }
        }
        if (count==strlen(query)) 
        {
            printf("%d\n",k);
        }
        i=k;
    }
    return 0;
}