#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#10866 연결리스트로 풀기
/*
push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
typedef struct node{
    int data;
    struct node* next;
}Node;
typedef struct dequeue{
    Node* front;
    Node* back;
    int size;
}Dequeue;
Dequeue* initdequeue();
Node* makenode(int);
void push_front(Dequeue*,Node*);
void push_back(Dequeue*,Node*);
int pop_front(Dequeue*);
int pop_back(Dequeue*);
int size(Dequeue*);
int empty(Dequeue*);
int front(Dequeue*);
int back(Dequeue*);

int main(void){
    int N;
    int i;
    char command[11]={0};
    int cmdNum;
    Dequeue* dequeue=initdequeue();
    scanf("%d",&N);
    getchar();
    for(i=0;i<N;i++){
        scanf("%s",command);
        if(strcmp(command,"pop_front")==0)printf("%d\n",pop_front(dequeue));
        else if (strcmp(command,"pop_back")==0)printf("%d\n",pop_back(dequeue));
        else if (strcmp(command,"size")==0)printf("%d\n",size(dequeue));
        else if (strcmp(command,"empty")==0)printf("%d\n",empty(dequeue));
        else if (strcmp(command,"front")==0)printf("%d\n",front(dequeue));
        else if (strcmp(command,"back")==0)printf("%d\n",back(dequeue));
        else{
            if(strcmp(command,"push_front")==0){
                scanf("%d",&cmdNum);
                getchar();
                push_front(dequeue,makenode(cmdNum));
            }
            else if(strcmp(command,"push_back")==0){
                scanf("%d",&cmdNum);
                getchar();
                push_back(dequeue,makenode(cmdNum));
            }
        }
    }
    
    

    return 0;
}
Dequeue* initdequeue(){
    Dequeue* dequeue=(Dequeue*)malloc(sizeof(Dequeue));
    dequeue->size=0;
    dequeue->front=NULL;
    dequeue->back=NULL;
    return dequeue;
}
Node* makenode(int num){
    Node* new=(Node*)malloc(sizeof(Node));
    new->data=num;
    new->next=NULL;
    return new;
}
void push_front(Dequeue* dequeue, Node* add){
    dequeue->size++;
    if(dequeue->size==1){
        dequeue->front=add;
        dequeue->back=add;
    }
    else{
        Node* temp=dequeue->front;
        dequeue->front=add;
        add->next=temp;
    }
}
void push_back(Dequeue* dequeue, Node* add){
    dequeue->size++;
    if(dequeue->size==1){
        dequeue->front=add;
        dequeue->back=add;
    }
    else{
        Node* temp=dequeue->back;
        dequeue->back=add;
        temp->next=add;
    }
}
int pop_front(Dequeue* dequeue){
    if(dequeue->size==0)return -1;
    Node* temp=dequeue->front;
    int value=temp->data;
    dequeue->front=dequeue->front->next;
    dequeue->size--;
    free(temp);
    return value;
}
int pop_back(Dequeue* dequeue){
    if(dequeue->size==0)return -1;
    Node* curr=dequeue->front;
    if(dequeue->size==1){
        Node* temp=dequeue->back;
        int value=temp->data;
        dequeue->size--;
        free(temp);
        return value;
    }
    else{
    while(1){
        if(curr->next==dequeue->back)break;
        curr=curr->next;
    }
    Node* temp=dequeue->back;
    int value=temp->data;
    dequeue->back=curr;
    dequeue->size--;
    free(temp);
    return value;
    }
}
int size(Dequeue* dequeue){
    return dequeue->size;
}
int empty(Dequeue* dequeue){
    if(dequeue->size==0)return 1;
    else return 0;
}
int front(Dequeue* dequeue){
    if(dequeue->size==0)return -1;
    else return dequeue->front->data;
}
int back(Dequeue* dequeue){
    if(dequeue->size==0)return -1;
    else return dequeue->back->data;
}