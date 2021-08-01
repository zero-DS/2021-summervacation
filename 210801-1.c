#include <stdio.h>
#include <stdlib.h>
//#11724
#define MAX_VERTEX 1001
int visited[MAX_VERTEX]={0};
int unitcount=0;
typedef struct list{
    int data;
    struct list* link;
}List;
typedef struct graph{
    int listnum;
    List* listarr[MAX_VERTEX];
}Graph;
Graph* initgraph();
void addvertex(Graph*);
void addedge(Graph*,int,int);
void checkvisited(Graph*,int);
void DFS(Graph*,int);
int main(void){
    Graph* graph=initgraph();
    int V,E;
    int a,b;
    scanf("%d %d",&V,&E);
    for(int i=0;i<V;i++){
        addvertex(graph);
    }
    for(int i=0;i<E;i++){
        scanf("%d %d",&a,&b);
        addedge(graph,a,b);
    }
    for(int i=1;i<=V;i++){
        checkvisited(graph,i);
    }
    printf("%d",unitcount);

    return 0;
}
Graph* initgraph(){
    Graph* new=(Graph*)malloc(sizeof(Graph));
    new->listnum=1;
    for(int i=0;i<MAX_VERTEX;i++){
        new->listarr[i]=NULL;
    }
    return new;
}
void addvertex(Graph* g){
    g->listarr[g->listnum]=(List*)malloc(sizeof(List));
    g->listarr[g->listnum]->data=-1;
    g->listarr[g->listnum]->link=NULL;
    g->listnum++;
}
void addedge(Graph* g,int a,int b){
    if(a>g->listnum || b>g->listnum)return;
    List* temp_a=(List*)malloc(sizeof(List));
    List* temp_b=(List*)malloc(sizeof(List));
    temp_a->data=a;
    temp_b->data=b;

    temp_a->link=g->listarr[b]->link;
    g->listarr[b]->link=temp_a;
    temp_b->link=g->listarr[a]->link;
    g->listarr[a]->link=temp_b;
}
void checkvisited(Graph* g, int n){
    if(visited[n]==0){
        unitcount++;
        DFS(g,n);
    }
}
void DFS(Graph* g, int n){
    if(visited[n]==0){
        visited[n]=1;
    
        List* curr=g->listarr[n]->link;
        while(curr!=NULL){
            if(visited[curr->data]==0){
                DFS(g,curr->data);
            }
            curr=curr->link;
        }
    }
}
