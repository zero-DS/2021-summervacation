#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#10828 연결리스트로 풀기
/*
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
typedef struct node{
    int data;
    struct node* next;
}Node;
typedef struct stack{
    Node* topnode;
    int size;
}Stack;
Stack* initstack();
Node* makenode(int);
void push(Stack*,Node*);
int pop(Stack*);
int size(Stack*);
int empty(Stack*);
int top(Stack*);
int main(void){
    int N;
    char command[6]={0};
    int cmdNum;
    Stack* stack=initstack();
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%s",command);
        if(strcmp(command,"pop")==0)printf("%d\n",pop(stack));
        else if(strcmp(command,"size")==0)printf("%d\n",size(stack));
        else if(strcmp(command,"empty")==0)printf("%d\n",empty(stack));
        else if(strcmp(command,"top")==0)printf("%d\n",top(stack));
        else{
            scanf("%d",&cmdNum);
            if(strcmp(command,"push")==0)push(stack,makenode(cmdNum));;
        }
    }
    return 0;
}
Stack* initstack(){
    Stack* s;
    s=(Stack*)malloc(sizeof(Stack));
    s->topnode=NULL;
    s->size=0;
    return s;
}
Node* makenode(int num){
    Node* newnode;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=num;
    newnode->next=NULL;
    return newnode;
}
void push(Stack* stack,Node* add){
    Node* temp=stack->topnode;//기존의 탑노드
    stack->topnode=add;//푸쉬하는 새로운 탑노드
    stack->topnode->next=temp;//새로운 탑노드의 넥스트가 기존의 탑노드
    stack->size++;
}
int pop(Stack* stack){
    if(stack->size==0)return -1;
    Node* temp=stack->topnode;
    stack->size--;
    int data=temp->data;
    stack->topnode=temp->next;
    free(temp);
    return data;
}
int size(Stack* stack){
    return stack->size;
}
int empty(Stack* stack){
    if(stack->size==0)return 1;
    else return 0;
}
int top(Stack* stack){
    if(stack->size==0)return -1;
    return stack->topnode->data;
}