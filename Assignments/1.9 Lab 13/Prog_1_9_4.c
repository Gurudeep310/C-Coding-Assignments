/*[L13 P4] Telephone keypad
Have you ever wondered why they always have alphabet next to the digits on the keys?  Historically, have been used, mainly in the United States, as a technique for remembering telephone numbers easily. For example, an interior decorator might license the telephone number 1-800-724-683-7, but advertise it as the more memorable phone word 1-800-PAINTER. Notice how there's an hyphen after every 3 digits.
Question) How?
Ans) When you type PAINTER you will actually end up typing on the keys 724-683-7
Write a program, which accepts a code word of the format "1-800-H0LIDAY” and converts that into the original phone number.
Example 1:
Input:
1-800-H0LIDAY
Output:
1-800-465-432-9
Example 2:
Input:
1-800-BHANUPIZZA
Output:
1-800-242-687-499-2
Hint: 
1) Ignore the 1-800-part and focus on the alphabetic string part.
2) For every character figure out the digit of the key it belongs to.
    To achieve this, create an arrays with strings {"ABC", "DEF" ..  "WXYZ"}
    For every character check the index of the string that it is a member of.
Constraints:
Always assume the strings are uppercase.
Always assume the strings are not longer than 20 characters.
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char num_string[10000];
    char only_string[10000];
    scanf("%s",num_string);
    int len=strlen(num_string);
    int count=0;
    //printf("%d",len);
    //Ignores and print only after 1-800- and copies the string part to other string
    for(int i=6;i<len;i++)
    {
        
        only_string[count]=num_string[i];
        count=count+1;
        printf("%c",num_string[i]);
    }
    count=count-1;
    char* string[13]={"_,@","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ","|_|"," ","#"};
    char number[13]={'1','2','3','4','5','6','7','8','9','*','0','#'};
    int only_numbers[count+1];
    for(int i=0;i<count;i++)
    {
        int k=0;
        for(int j=0;j<12;j++)
        {
            if(only_string[i]==*(*(string+k)+j))
            {
                only_numbers[i]=number[k]-48;
                k=k+1;
            }
        }
    }
    printf("\nOnly numbers:");
    for(int i=0;i<count;i++)
    {
        printf("%d",only_numbers[i]);
    }

    return 0;
}