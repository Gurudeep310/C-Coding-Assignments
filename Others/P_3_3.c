/* Identify if its a hexadecimal number or not*/

#include<stdio.h>

void main()
{
    char str[10000];
    int i,flag=0,a=0;
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++);
    a=i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='a' &&str[i]<='f')
            flag++;
        if(str[i]>='0'&&str[i]<='9')
            flag++;
    }
    if(flag==a)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}