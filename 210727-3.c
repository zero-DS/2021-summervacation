#include <stdio.h>
#include <stdlib.h>
//#2630
int** paper;
void cut(int**,int,int,int);
int zeroCNT=0,oneCNT=0;
int main(void){
    int i,j;
    int N;//N=2,4,8,16,32,64,128
    scanf("%d",&N);
    paper=(int**)malloc(sizeof(int*)*N);
    for(i=0;i<N;i++)paper[i]=(int*)malloc(sizeof(int)*N);
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d",&paper[i][j]);
        }
        getchar();
    }
    cut(paper,0,0,N);
    printf("%d\n%d",zeroCNT,oneCNT);




    /*
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",paper[i][j]);
        }
        printf("\n");
    }*/
    for(i=0;i<N;i++)free(paper[i]);
    free(paper);
    

    return 0;
}
void cut(int** arr,int startX,int startY,int length){
    int i,j;
    int color;//-1이면 섞인거 0이면 전부0 1이면 전부1
    int cnt=0;//1인 칸 카운트
    for(i=startY;i<startY+length;i++){
        for(j=startX;j<startX+length;j++){
            if(arr[i][j]==1)cnt++;
        }
    }
    if(cnt==0){
        color=0;
        zeroCNT++;
    }
    else if(cnt==length*length){
        color=1;
        oneCNT++;
    }
    else color=-1;
    if(color==-1){
        length/=2;
        cut(arr,startX,startY,length);
        cut(arr,startX+length,startY,length);
        cut(arr,startX,startY+length,length);
        cut(arr,startX+length,startY+length,length);
    }
}
