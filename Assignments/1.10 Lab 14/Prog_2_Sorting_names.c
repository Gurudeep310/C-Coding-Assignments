#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct friend{
    char name[20];
    char mobile[20];
};

typedef struct friend friends;

int main(){
    char s[20], temp[20];
    int n;
    scanf("%s", s);
    scanf("%d", &n);
    friends* myfriend = (friends*)malloc(n*sizeof(friends));
    FILE *fp = fopen( s, "r");
    for(int i = 0; i < n; i++){
        fscanf(fp, "%s", (myfriend+i)->name);
        fscanf(fp, "%s", (myfriend+i)->mobile);
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(strcmp((myfriend+i)->name,(myfriend+j)->name) > 0){
                strcpy(temp,(myfriend+i)->name);
                strcpy((myfriend+i)->name,(myfriend+j)->name);
                strcpy((myfriend+j)->name,temp);
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%s\n", (myfriend+i)->name);
    }
    fclose(fp);
    return 0;
}