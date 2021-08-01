#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#9012 스택으로 풀기
typedef struct node{
    char data;
    struct node* next;
}Node;
typedef struct stack{
    Node* top;
    int size;
}Stack;
Stack* initstack();
void resetstack(Stack*);
Node* makenode(char);
void push(Stack*,Node*);
char pop(Stack*);
int main(void){
    int N;
    char** parenstring;
    int i,j;
    Stack* stack=initstack();
    scanf("%d",&N);
    parenstring=(char**)malloc(sizeof(char*)*N+1);
    for(i=0;i<N;i++){
        parenstring[i]=(char*)malloc(sizeof(char)*51);
    }
    for(i=0;i<N;i++){
        resetstack(stack);
        int flag=1;
        scanf("%s",parenstring[i]);
        int len=strlen(parenstring[i]);
        for(j=0;j<len;j++){
            if(parenstring[i][j]=='(')push(stack,makenode(parenstring[i][j]));
            else if(parenstring[i][j]==')'){
                char temp=pop(stack);
                if(temp==')' || temp=='\0')flag=0;//temp가 널일때는 스택이 비었을때
            }
        }
        if(stack->size!=0)flag=0;//위의 과정을 거쳐도 스택에 노드가 남아있다면 VPS가 아니다
        if(flag==1)printf("YES\n");
        else printf("NO\n");
    }
    for(i=0;i<N;i++){
        free(parenstring[i]);
    }
    free(parenstring);
    free(stack);
    return 0;
}
Stack* initstack(){
    Stack* new=(Stack*)malloc(sizeof(Stack));
    new->top=NULL;
    new->size=0;
    return new;
}
void resetstack(Stack* stack){
    if(stack->size==0)return;
    int i=stack->size;
    Node* curr=stack->top;
    while(i--){
        Node* temp=curr;
        curr=curr->next;
        free(temp);
    }
    stack->top=NULL;
    stack->size=0;
}
Node* makenode(char paren){
    Node* new=(Node*)malloc(sizeof(Node));
    new->data=paren;
    return new;
}
void push(Stack* stack, Node* add){
    stack->size++;
    Node* temp=stack->top;
    stack->top=add;
    add->next=temp;//새로운 탑노드의 넥스트가 기존의 탑노드
}
char pop(Stack* stack){
    if(stack->size==0)return 0;
    stack->size--;
    Node* temp=stack->top;
    char value=temp->data;
    stack->top=temp->next;
    free(temp);
    return value;
}