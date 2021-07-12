#include <stdio.h>
#include <stdlib.h>
//#3085
/*
가장 처음에 N×N크기에 사탕을 채워 놓는다. 사탕의 색은 모두 같지 않을 수도 있다. 상근이는 사탕의 색이 다른 인접한 두 칸을 고른다. 
그 다음 고른 칸에 들어있는 사탕을 서로 교환한다. 이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.

사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.


첫째 줄에 보드의 크기 N이 주어진다. (3 ≤ N ≤ 50)

다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다. 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.

사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.
*/
int findMax(char**,int);
int change(char**,int);
int main(){
    int N;
    int i,j;
    int max=0,temp;
    char** board;//N보다 보드를 한 칸씩 넓게 만든다
    scanf("%d",&N);//3<=n<=50
    getchar();
    board=(char**)malloc((N+1)*sizeof(char*));
    for(i=0;i<N+1;i++){
        board[i]=(char*)malloc((N+1)*sizeof(char));
        for(j=0;j<N+1;j++) board[i][j]=0;
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%c",&board[i][j]);
        }
        getchar();
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            //printf("%c",board[i][j]);
        }
        //printf("\n");
    }
    //printf("\n%d\n",change(board,N));
    printf("%d",change(board,N));

    for(i=0;i<N+1;i++){
        free(board[i]);
    }
    free(board);
    
    
    return 0;
}

int findMax(char** board, int N){
    int i,j,cntR=0,cntC=0;
    int tempmax[10000]={0};
    int max=0;
    for(i=0;i<N;i++){//가로줄 훑기
        for(j=1;j<N;j++){
            if(board[i][j]==board[i][j-1]) {
                //printf("%d %d\n",i,j);
                tempmax[cntR]++;
            }
            else {
                //printf("맥스%d\n",tempmax[cntR]);
                cntR++;
            }
        }
        cntR++;
    }
    //printf("cntR: %d\n",cntR);
    //for(i=0;i<cntR;i++)printf(" %d ",tempmax[i]); 
    for(i=0;i<cntR;i++){
        //printf("tempmax :%d ",tempmax[i]);
        if (max<tempmax[i]) {
            max=tempmax[i];
            //printf("\nstore %d to max\n",max);
        }
    }
    for(i=0;i<cntR;i++){
        tempmax[i]=0;
    }
    for(j=0;j<N;j++){//세로줄 훑기
        for(i=1;i<N;i++){
            if(board[i][j]==board[i-1][j]) {
                //printf("%d %d\n",i,j);
                tempmax[cntC]++;
            }
            else cntC++;
        }
        cntC++;
    }
    for(i=0;i<cntC;i++){
        if (max<tempmax[i]) {
            max=tempmax[i];
            //printf("\nstore %d to max\n",max);
        }
    }
    max+=1;//tempmax값이 최대로 먹을수 있는 구슬 개수의값 -1 이므로
    return max;
}
int change(char** board, int N){
    int max=0;
    char temp;
    int i,j;
    /*
    char** record=(char**)malloc((N+1)*sizeof(char*));
    for(i=0;i<N+1;i++) record[i]=(char*)malloc((N+1)*sizeof(char));
    */
    
    for(i=0;i<N;i++){//가로줄 바꾸기
        for(j=0;j<N-1;j++){
            temp=board[i][j];
            board[i][j]=board[i][j+1];
            board[i][j+1]=temp;
            if(max<findMax(board,N)) {
                max=findMax(board,N);
                //printf("\n가로 바꿧당 %d %d max: %d\n",i,j,max);
                /*for(int k=0;k<N;k++){
                    for(int l=0;l<N;l++){
                        record[k][l]=board[k][l];
                    }
                }*/
            }
            board[i][j+1]=board[i][j];
            board[i][j]=temp;
        }
    }
    for(j=0;j<N;j++){//세로줄 바꾸기
        for(i=0;i<N-1;i++){
            temp=board[i][j];
            board[i][j]=board[i+1][j];
            board[i+1][j]=temp;
            if(max<findMax(board,N)) {
                max=findMax(board,N);
                //printf("\n세로 바꿧당 %d %d max: %d\n",i,j,max);
                /*for(int k=0;k<N;k++){
                    for(int l=0;l<N;l++){
                        record[k][l]=board[k][l];
                    }
                }*/
            }
            board[i+1][j]=board[i][j];
            board[i][j]=temp;
        }
    }
    /*printf("\nrecorded board\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%2c",record[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<N+1;i++){
        free(record[i]);
    }
    free(record);*/
    return max;
}