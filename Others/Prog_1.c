#include<stdio.h>

int main()
{
    int arr[]={1,6,3,4,5};
    printf("arr(hexdec address): %x\n",arr);
    printf("arr: %d\n",arr);
    printf("&arr: %d\n",&arr);
    printf("*arr: %d\n",*arr);
    printf("*arr+1: %d\n",*arr+1);
    printf("*(arr+1): %d\n",*(arr+1));
    printf("arr+1: %d\n",arr+1);
    //printf("&arr+1: %d\n",&arr+1);
    printf("arr[3]: %d\n",arr[3]);
    printf("*(arr+3): %d\n",*(arr+3));
    printf("&arr[2]: %d\n",&arr[2]);
    //printf("&arr+1: %d\n",&arr+1);
    printf("arr+1: %d\n",arr+1);
}