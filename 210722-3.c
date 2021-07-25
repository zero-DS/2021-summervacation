#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#9012
int checkVPS(char*);
int main(void){
    int i,j;
    int T;
    scanf("%d",&T);
    getchar();
    char** Tarr=(char**)malloc(sizeof(char*)*T);
    for(i=0;i<T;i++){
        Tarr[i]=(char*)malloc(sizeof(char)*51);
        scanf("%s",Tarr[i]);
        getchar();
    }
    for(i=0;i<T;i++){
        if(checkVPS(Tarr[i])==1)printf("YES\n");
        else printf("NO\n");
    }
    



    for(i=0;i<T;i++)free(Tarr[i]);
    free(Tarr);
    return 0;
}
int checkVPS(char* ps){
    int i;
    int left=0,right=0;
    int len=strlen(ps);
    for(i=0;i<len;i++){
        if(ps[i]=='(')left++;
        else if(ps[i]==')')right++;
        if (left<right)return 0;
    }
    if(left==right)return 1;
    else return 0;    
}