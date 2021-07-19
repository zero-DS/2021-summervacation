#include <stdio.h>
#include <stdlib.h>
//#1018

int countChange(char**,int,int);
int main(){
    int i,j;
    int temp;
    int M, N;//가로줄이 M개 세로줄이 N개, M과 N은 8이상 50이하
    char** board;
    int mincnt=123454321;//countChange함수를 가능한 (a,b)좌표마다 모두 실행, 그때마다 반환되는 cnt가 가장 작은것을 저장

    scanf("%d %d",&M,&N);
    getchar();
    board=(char**)malloc(sizeof(char*)*(M+1));
    for(i=0;i<M+1;i++){
        board[i]=(char*)malloc(sizeof(char)*(N+1));
        for(j=0;j<N+1;j++)board[i][j]=0;
    }
    
    for(i=0;i<M;i++){
        scanf("%s",board[i]);//이거 표현법 기억해두기
        getchar();
    }
    for(i=0;i<M-7;i++){
        for(j=0;j<N-7;j++){
            temp=countChange(board,i,j);
            if(mincnt>temp){
                //printf("min:%d,i:%dj:%d\n",temp,i,j);
                mincnt=temp;
            }
        }
    }
    if(mincnt>(64-mincnt))mincnt=64-mincnt;
    printf("%d",mincnt);
    for(i=0;i<M+1;i++){
        free(board[i]);
    }
    free(board);
    return 0;
}
int countChange(char** arr,int a, int b){//a,b는 a+7<=M, b+7<=N
    int cnt=0,cnt1=0,cnt2=0;
    int i,j;
    
    char correct1[9][9]={{'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'}
    ,{'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'}};
    char correct2[9][9]={{'W','B','W','B','W','B','W','B'}
    ,{'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},{'B','W','B','W','B','W','B','W'}};
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(correct1[i][j]!=arr[a+i][b+j]){
                //printf("%d %d 번째가 정답과 다름,cnt1++\n",a+i,b+j);
                cnt1++;
            }
            if(correct2[i][j]!=arr[a+i][b+j]){
                //printf("%d %d 번째가 정답과 다름,cnt2++\n",a+i,b+j);
                cnt2++;
            }
        }
    }
    if(cnt1<cnt2)cnt=cnt1;
    else cnt=cnt2;
    
    return cnt;
}