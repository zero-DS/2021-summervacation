#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#1012
//가로세로가 헷갈리니 주의....
int bat[50][50]={0};
int M,N,cabbage;
void DFS(int,int);
int main(void){
    int i,k;
    int T;
    int x,y;
    scanf("%d",&T);
    getchar();
    for(i=0;i<T;i++){
        memset(bat,0,sizeof(bat));
        int worms=0;//테스트케이스마다 밭 초기화 및 지렁이수 초기화
        scanf("%d %d %d",&M,&N,&cabbage);
        getchar();
        for(k=0;k<cabbage;k++){
            scanf("%d %d",&x,&y);
            getchar();
            bat[y][x]=1;
        }
        for(y=0;y<N;y++){
            for(x=0;x<M;x++){
                if(bat[y][x]==1){
                    DFS(x,y);
                    worms++;
                }
            }
        }
        printf("%d\n",worms);
    }

    
    return 0;
}
void DFS(int x, int y){
    bat[y][x]=0;//방문하면 0으로
    if(x+1<M && bat[y][x+1]==1)DFS(x+1,y);
    if(x-1>=0 && bat[y][x-1]==1)DFS(x-1,y);
    if(y+1<N && bat[y+1][x]==1)DFS(x,y+1);
    if(y-1>=0 && bat[y-1][x]==1)DFS(x,y-1);
}
