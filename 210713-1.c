#include <stdio.h>
#include <stdlib.h>
//#10448
//t1=1 t2=3 t3=6 t4=10 t5=15 t6=21  t=n(n+1)/2

int three(int,int*);

int main(void){
    int i,j,k,sum=0;
    int N;
    int* arr;//어떤 정수들의 배열
    int triarr[50]={0};//1부터1000이하의 삼각수들의 배열
    
    scanf("%d",&N);//테스트케이스 개수
    getchar();
    arr=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++){
        scanf("%d",arr+i);
        getchar();
    }
    //printf("\n%d %d %d\n",arr[0],arr[1],arr[2]);
    for(i=0;i<50;i++){
        if(sum>1000) break;
        sum+=(1+i);
        triarr[i]=sum;
    }//삼각수들을 저장
    for(i=0;i<N;i++){
        printf("%d\n",three(arr[i],triarr));
    }

    free(arr);
    return 0;
}

int three (int Q,int* triarr){
    int i,j,k;
    int flag=0;
    //printf("\n%d %d %d %d\n",Q,triarr[0],triarr[1],triarr[2]);
    for(i=0;i<50;i++){
        if(triarr[i]==0)break;
        for(j=i;j<50;j++){
            if(triarr[j]==0)break;
            for(k=j;k<50;k++){
                if(triarr[k]==0)break;
                if((triarr[i]+triarr[j]+triarr[k])==Q){
                    //printf("%d %d %d : ",triarr[i],triarr[j],triarr[k]);
                    flag=1;
                    break;
                }
            }
        }
    }
    return flag;
}
