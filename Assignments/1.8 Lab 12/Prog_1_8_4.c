/*[L12 P4] Count vowels in the text file 
Write a program that takes the name of the textfile (located in the same folder as the program) as the input and outputs the number of vowels occurring in the file.
The progam should output -1 and terminate if the name of a non-existing file is given as the input.
ASSUME: names of the textfiles have no spaces. Except textfile5.txt, the other files are hidden.
Example 1:
Input:
textfile5.txt
Output:
359
Explanation: There are 359 vowels in the given text file. Remember to count both uppercase and lowercase vowels. You can verify your answers at this link: letter-character-word-vowel-count
Example 2:
Input:
somefilethatdoesnotexist.pdf
Output:
-1
HINT: You won't need any file operation function other than fgetc to solve this problem.
Constraints:
length of filename is < 50 characters.
*/

#include <stdio.h>

int isMember(char ch, char string[], int size){
    //this function may be used to check if a given character is vowel or not
    for(int i = 0; i < size; i++){
        if(ch == string[i]){
            return 1;//returns true if ch is in "aeiouAEIOU"
        }
    }
   return 0; //returns false otherwise
}


int main(){
    
    char filename[50];
    scanf("%s", filename);
    char vowels[10] = "aeiouAEIOU";
    FILE* f_p = fopen(filename, "r");
    char c;
    int count=0;
    if(f_p!=NULL)
    { 
        while((c=fgetc(f_p))!=EOF)
        {
            if((isMember(c,vowels,10))==1)
            {
                count=count+1;
            }
        }
       printf("%d",count);
        
    }
    else
    {
        printf("-1");
    }
    fclose(f_p);
    return 0;
}
