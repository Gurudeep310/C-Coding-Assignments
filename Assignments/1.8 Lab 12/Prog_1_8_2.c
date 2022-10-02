/*The string "bhanu" is a substring of "kilogrambhaanukilobhanukilogram". The reason is fairly intuitive which is that the string "bhanu" occurs from index 18 to index 23.
But how to programmatically check if a given small piece of string (called query) is part of a larger string (called source) along with locations at which they occur?
ASSUME neither source nor query has spaces.
Example 1: 
Input:
"backbaccabckbackcabback"
"cab"
    where: the first line is source
               the second line is query
               assume there are not spaces in source of query
Output:
7
16
Example 2:
Input:
"backbaccackbackcabback"
"tommy"
Output:
NO
Constraints:  0 < query size < 50
                   0 < source size < 10000 
*/

#include <stdio.h>
#include <string.h>

int main(){
    
    char query[50];
    char source[10000];
    int k = 0, count = 0;
    scanf("%s", source);
    scanf("%s", query);
    char *ptr = strstr(source, query); //This function takes two strings s1 and s2 as an argument and finds the first occurrence of the sub-string s2
    if (ptr == NULL) 
    {
        printf("NO\n");
    }
    int lens=strlen(source);
    int lenq=strlen(query);
    for (int i = 0;i<lens; i++, k++) 
    {
        count = 0;
        for (int j = 0; query[j] != '\0'; j++) 
        {
            if (source[i] == query[j]) 
            {
                count=count+1;
                i=i+1;
            } 
            else 
            {
                break;
            }
        }
        if (count==lenq) 
        {
            printf("%d\n", k);
        }
        i=k;
    }
    return 0;
}

