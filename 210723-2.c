#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#10828
/*
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
int stack[10000]={0};
int topN=-1;

void push(int);
int pop();
int size();
int empty();
int top();
int main(void){
    int N;
    char command[6]={0};
    int cmdNum;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%s",command);
        if(strcmp(command,"pop")==0)printf("%d\n",pop());
        else if(strcmp(command,"size")==0)printf("%d\n",size());
        else if(strcmp(command,"empty")==0)printf("%d\n",empty());
        else if(strcmp(command,"top")==0)printf("%d\n",top());
        else{
            scanf("%d",&cmdNum);
            if(strcmp(command,"push")==0)push(cmdNum);
        }
    }
       

    return 0;
}
void push(int n){
    topN++;
    stack[topN]=n;
}
int pop(){
    int temp;
    if(topN==-1)return -1;
    else{
        temp=stack[topN];
        stack[topN]=0;
        topN--;
        return temp;
    }
}
int size(){
    return topN+1;
}
int empty(){
    if(topN==-1)return 1;
    else return 0;
}
int top(){
    if(topN==-1)return -1;
    else return stack[topN];
}