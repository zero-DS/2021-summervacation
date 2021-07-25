#include <stdio.h>
#include <stdlib.h>
//#11866
int getYoseNum(int*,int,int,int);
int main(void){
    int i;
    int N, K;//1<=N,K<=1000
    scanf("%d %d",&N,&K);
    int* Narr=(int*)malloc(sizeof(int)*N);
    int* Yose=(int*)malloc(sizeof(int)*N);
    int temp;
    for(i=0;i<N;i++){
        Narr[i]=i+1;
    }
    
    Yose[0]=getYoseNum(Narr,0,N,K);
    for(i=1;i<N;i++){
        if(Yose[i-1]!=N) Yose[i]=getYoseNum(Narr,Yose[i-1],N,K);
        else Yose[i]=getYoseNum(Narr,0,N,K);
    }
    for(i=0;i<N;i++){
        if(N==1){
            printf("<1>");
            break;
        }
        if(i==0)printf("<%d, ",Yose[i]);
        else if(i==N-1)printf("%d>",Yose[i]);
        else printf("%d, ",Yose[i]);
    }
    

    free(Narr);
    free(Yose);
    return 0;
}
int getYoseNum(int* circle,int start,int N, int K){
    int i;
    int countK=0;
    i=start;
    int YoseNum;
    while(1){
        if(circle[i]==0){
            i++;
            if(i>N-1)i=0;
            continue;
        }
        else{
            countK++;
            if(countK==K){
                YoseNum=circle[i];
                circle[i]=0;
                return YoseNum;
            }
            i++;
            if(i>N-1)i=0;
        }

    }
}