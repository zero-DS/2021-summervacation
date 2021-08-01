#include <stdio.h>
#include <string.h>
//#11723
/*
add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다. 
*/
int S[20]={0};

void add(int);
void re_move(int);
int check(int);
void toggle(int);
void all();
void empty();
int main(void){
    int M;//1<=M<=300000
    int i;
    int cmdNum;
    char command[7]={0};
    scanf("%d",&M);
    getchar();
    for(i=0;i<M;i++){
        scanf("%s",command);
        if(strcmp(command,"all")==0)all();
        else if(strcmp(command,"empty")==0)empty();
        else{
            scanf("%d",&cmdNum);
            if(strcmp(command,"add")==0)add(cmdNum);
            else if(strcmp(command,"remove")==0)re_move(cmdNum);
            else if(strcmp(command,"check")==0)printf("%d\n",check(cmdNum));
            else if(strcmp(command,"toggle")==0)toggle(cmdNum);
        }
        getchar();
    }


    return 0;
}
void add(int n){
    if(S[n-1]==1)return;
    else S[n-1]=1;
}
void re_move(int n){
    if(S[n-1]==0)return;
    else S[n-1]=0;
}
int check(int n){
    if(S[n-1]==0)return 0;
    else if (S[n-1]==1)return 1;
}
void toggle(int n){
    if(S[n-1]==1)S[n-1]=0;
    else if(S[n-1]==0)S[n-1]=1;
}
void all(){
    for(int i=0;i<20;i++)S[i]=1;
}
void empty(){
    for(int i=0;i<20;i++)S[i]=0;
}