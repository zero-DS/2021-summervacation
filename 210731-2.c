#include <stdio.h>
#include <stdlib.h>
//#1260
#define MAX_VERTEX 1001
int visited[MAX_VERTEX]={0};//DFS시 방문했는지 확인하기 위한 배열
int bisited[MAX_VERTEX]={0};//BFS시
int queue[MAX_VERTEX]={0};
int front=-1,rear=-1;
typedef struct list{
    int data;
    struct list* link;
}List;
typedef struct graph{
    int listnum;//리스트가 몇 개 있는지, 즉 버텍스가 몇 개 있는지
    List* listarr[MAX_VERTEX];//인덱스와 인접한 노드들을 저장하는 배열. listarr[i]는 헤드노드이고 이것의 링크부터가 노드
}Graph;
Graph* initgraph();
void addvertex(Graph*);
void addedge(Graph*,int,int);
void DFS(Graph*,int);
void printgraph(Graph*);
void BFS(Graph*,int);
void push(int);
int pop();
int main(void){
    int V,E,S;
    int a,b;
    Graph* graph=initgraph();
    scanf("%d %d %d",&V,&E,&S);
    for(int i=0;i<V;i++){
        addvertex(graph);
    }
    for(int i=0;i<E;i++){
        scanf("%d %d",&a,&b);
        addedge(graph,a,b);
    }
    
    DFS(graph,S);
    printf("\n");
    BFS(graph,S);
    //printgraph(graph);

    return 0;
}
Graph* initgraph(){
    Graph* new=(Graph*)malloc(sizeof(Graph));
    new->listnum=1;//원래는 0으로 초기화 해야하는데 문제 조건이 노드가 1번부터니까 1로 초기화
    for(int i=0;i<MAX_VERTEX;i++){
        new->listarr[i]=NULL;
    }
    return new;
}
void addvertex(Graph* graph){//그래프에 빈 버텍스를 추가하는 함수
    graph->listarr[graph->listnum]=(List*)malloc(sizeof(List));
    graph->listarr[graph->listnum]->data=-1;
    graph->listarr[graph->listnum]->link=NULL;//버텍스 동적할당 및 초기화
    graph->listnum++;
}
void addedge(Graph* graph, int a, int b){//a와 b 버텍스 간의 연결을 만드는 함수
    if(graph->listnum<=a || graph->listnum<=b)return;//존재하지 않는 버텍스일 경우 리턴
    List* temp_a=(List*)malloc(sizeof(List));
    List* temp_b=(List*)malloc(sizeof(List));
    List* curr;
    List* before;
    List* temp;

    temp_a->data=a;
    temp_a->link=graph->listarr[b]->link;
    graph->listarr[b]->link=temp_a;//a를 그래프의 b리스트의 맨 앞에 넣는다
    
    curr=temp_a;
    before=graph->listarr[b];
    while(curr->link!=NULL && curr->data > curr->link->data){
        temp=curr->link;

        curr->link=temp->link;
        before->link=temp;
        temp->link=curr;

        before=temp;
    }//curr은 위치가 바뀌었기 때문에 curr=curr->link 불필요함

    temp_b->data=b;
    temp_b->link=graph->listarr[a]->link;
    graph->listarr[a]->link=temp_b;
    
    curr=temp_b;
    before=graph->listarr[a];
    while(curr->link!=NULL && curr->data > curr->link->data){
        temp=curr->link;

        curr->link=temp->link;
        before->link=temp;
        temp->link=curr;

        before=temp;
    }
    
}
void DFS(Graph* graph, int n){
    if(visited[n]==0){//아직 방문한 적이 없는 경우
        printf("%d ",n);
        visited[n]=1;

        List* curr=graph->listarr[n]->link;
        while(curr!=NULL){//연결돼있는 노드가 방문한 적이 없다면 DFS
            if(visited[curr->data]==0)DFS(graph,curr->data);
            curr=curr->link;
        }
    }
}
void printgraph(Graph* graph){
    for(int i=1;i<graph->listnum+1;i++){
        List* l=graph->listarr[i]->link;
        printf("%d와 연결된 노드들 :",i);
        while(l!=NULL){
            printf("%d ",l->data);
            l=l->link;
        }
        printf("\n");
    }
}
void BFS(Graph* graph,int n){
    int popped;
    if(bisited[n]==0){
        printf("%d ",n);
        bisited[n]=1;
    }
    List* curr=graph->listarr[n]->link;
    while(curr!=NULL){
        if(bisited[curr->data]==0){
            printf("%d ",curr->data);
            bisited[curr->data]=1;
            push(curr->data);
        }//방문한 노드의 인접노드들이 아직 방문한 적 없다면 큐에 저장
        curr=curr->link;
    }
    popped=pop();
    while(popped!=-1){//큐에 남은 게 없을 때까지 pop
        BFS(graph,popped);
        popped=pop();
    }
}
void push(int n){
    if(front==-1)front++;
    rear++;
    queue[rear]=n;
}
int pop(){
    if(front==-1)return -1;
    int temp=queue[front];
    queue[front]=0;
    front++;
    if(front>rear){
        front=-1;
        rear=-1;
    }
    return temp;
}