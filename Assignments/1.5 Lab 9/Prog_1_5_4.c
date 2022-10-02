/*[L9 P4] Product of ASCII value of characters
Given string S, find the product of ASCII values of characters in the string S.
Input:
    ab
    where:
First line represents string S.
Output:
    9506*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
        //printf("%c",num_string[i]);
    }
    //count=count-1;
    char* string[13]={"_,@","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ","|_|"," ","#"};
    char number[13]={'1','2','3','4','5','6','7','8','9','*','0','#'};
    int only_numbers[count+1];
    for(int i=0;i<count;i++)
    {
        int k=0;
        for(int j=0;j<12;j++)
        {
            for(int k=0;k<4;k++)
            {
                if(only_string[i]==*(*(string+j)+k))  //Comparing two strings
                { 
                    only_numbers[i]=(int)number[j]-48;  //Converting number to ascii
                }
            }
        }
    }
    int flag=0;
    int kal=3;
    //printf("\nOnly numbers:");
    for(int i=0;i<6;i++)     //Printing first part
    {
        printf("%c",num_string[i]);
    }
    for(int i=0;i<count;i++)  //Printing second part
    {
        char ifen='-';
        if(flag==kal)
        {
            printf("%c",ifen);
            kal=kal+3;
        }
        printf("%d",only_numbers[i]);
        flag=flag+1;
    }

    return 0;
}