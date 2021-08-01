#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#10845 연결리스트로 풀기
/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
typedef struct node{
    int data;
    struct node* next;
}Node;
typedef struct queue{
    Node* front;
    Node* back;
    int size;
}Queue;
Queue* initqueue();
Node* makenode(int);
void push(Queue*,Node*);
int pop(Queue*);
int size(Queue*);
int empty(Queue*);
int front(Queue*);
int back(Queue*);
int main(void){
    int i,j;
    int N;
    char command[6]={0};//명령어가 최대 5글자여서
    int cmdNum;
    Queue* queue=initqueue();
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%s",command);
        if(strcmp(command,"pop")==0)printf("%d\n",pop(queue));
        else if(strcmp(command,"size")==0)printf("%d\n",size(queue));
        else if(strcmp(command,"empty")==0)printf("%d\n",empty(queue));
        else if(strcmp(command,"front")==0)printf("%d\n",front(queue));
        else if(strcmp(command,"back")==0)printf("%d\n",back(queue));
        else{
            scanf("%d",&cmdNum);
            if(strcmp(command,"push")==0)push(queue,makenode(cmdNum));
        }
    }
    return 0;
}
Queue* initqueue(){
    Queue* queue=(Queue*)malloc(sizeof(Queue));
    queue->size=0;
    queue->front=NULL;
    queue->back=NULL;
    return queue;
}
Node* makenode(int num){
    Node* new=(Node*)malloc(sizeof(Node));
    new->data=num;
    new->next=NULL;
    return new;
}
void push(Queue* queue,Node* add){
    queue->size++;
    if(queue->size==1){
        queue->front=add;
        queue->back=add;
    }
    else{
        Node* temp=queue->back;
        queue->back=add;
        temp->next=add;
    }
}
int pop(Queue* queue){
    if(queue->size==0)return -1;
    Node* temp=queue->front;
    int value=temp->data;
    queue->front=queue->front->next;
    queue->size--;
    free(temp);
    return value;
}
int size(Queue* queue){
    return queue->size;
}
int empty(Queue* queue){
    if(queue->size==0)return 1;
    else return 0;
}
int front(Queue* queue){
    if(queue->size==0)return -1;
    else return queue->front->data;
}
int back(Queue* queue){
    if(queue->size==0)return -1;
    else return queue->back->data;
}