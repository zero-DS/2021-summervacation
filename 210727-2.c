#include <stdio.h>
#include <stdlib.h>
//#2606
int computerboard[102][102]={0};//0 번째 행과 열은 고려안하고 비워둔다
int visited[101]={0};
void DFS(int);
int lines,computers,cnt=0;
int main(void){
    int i;
    int a,b;
    scanf("%d",&computers);
    scanf("%d",&lines);
    for(i=0;i<lines;i++){
        scanf("%d %d",&a,&b);
        computerboard[a][b]=1;
        computerboard[b][a]=1;
    }
    DFS(1);
    printf("%d",cnt-1);

    

    return 0;
}
void DFS(int n){
    if(visited[n-1]==0){//연결돼있길래 DFS해서 왔는데 처음 와본것이면,
        visited[n-1]=1;
        cnt++;
    }
    else return;//연결돼있길래 왔는데 이미 와본 컴퓨터이면 종료
    
    for(int i=1;i<=computers;i++){//n번째 행을 처음부터 끝까지 훑으며 연결돼있는 컴퓨터를 찾는다
        if(computerboard[n][i]==1){
            //printf("여기%d %d\n",n,i);
            DFS(i);
        }
    }
    
}