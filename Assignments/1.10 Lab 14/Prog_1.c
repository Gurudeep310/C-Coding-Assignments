#include<stdio.h>
#include<string.h>

int main()
{
    char arr_string[1000];
    char arr_modified[1000];
    int j = 0;
    for(int i = 0; i < 1000; i++)
    {
        scanf("%c",&arr_string[i]);
    }
    int len = strlen(arr_string);
    for(int i = 0; i < len; i++)
    {
        int count = 1;
        while(i < len  && arr_string[i] == arr_string[i+1])
        {
            count = count + 1;
            i = i + 1;
        }
        if(count == 1)
        {
            arr_modified[j] = arr_string[i];
            j = j + 1;
        }
        else
        {
            arr_modified[j] = arr_string[i];
            j = j + 1;            
            arr_modified[j] = count + 48;
            j = j + 1;
        }
    }
    for(int i = 0; i < j; i++)
    {
        printf("%c",arr_modified[i]);
    }
}