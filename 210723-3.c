#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#10845
/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
int queue[10000]={0};
int frontN=-1,backN=-1;
void push(int);
int pop();
int size();
int empty();
int front();
int back();
int main(void){
    int i,j;
    int N;
    char command[6]={0};//명령어가 최대 5글자여서
    int cmdNum;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%s",command);
        if(strcmp(command,"pop")==0)printf("%d\n",pop());
        else if(strcmp(command,"size")==0)printf("%d\n",size());
        else if(strcmp(command,"empty")==0)printf("%d\n",empty());
        else if(strcmp(command,"front")==0)printf("%d\n",front());
        else if(strcmp(command,"back")==0)printf("%d\n",back());
        else{
            scanf("%d",&cmdNum);
            if(strcmp(command,"push")==0)push(cmdNum);
        }
    }



    return 0;
}
void push(int n){
    if(frontN==-1)frontN++;
    backN++;
    queue[backN]=n;
}
int pop(){
    if(frontN==-1)return -1;
    int temp=queue[frontN];
    queue[frontN]=0;
    frontN++;
    if(frontN>backN){
        frontN=-1;
        backN=-1;
    }
    return temp;
}
int size(){
    int size;
    if(frontN==-1)return 0;
    size=backN-frontN+1;
    return size;
}
int empty(){
    if(frontN==-1)return 1;
    else return 0;
}
int front(){
    if(frontN==-1)return -1;
    else return queue[frontN];
}
int back(){
    if(frontN==-1)return -1;
    else return queue[backN];
}