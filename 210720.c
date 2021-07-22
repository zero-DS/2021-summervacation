#include <stdio.h>
#include <stdlib.h>
//#2798
int main(void){
    int i,j,k;
    int N;//N은 카드의 개수, M은 딜러가 선언한 정답, 
    int M;//카드 중 3장을 골라 M이 넘지 않으면서 가장 근접한 3장의 합을 출력
    
    int blackjack=0;
    int* Narr;
    scanf("%d %d",&N,&M);
    getchar();
    Narr=(int*)malloc(sizeof(int)*N);
    for(i=0;i<N;i++){
        scanf("%d",Narr+i);
    }
    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            for(k=j+1;k<N;k++){
                if(Narr[i]+Narr[j]+Narr[k]<M+1 && Narr[i]+Narr[j]+Narr[k]>blackjack){
                    blackjack=Narr[i]+Narr[j]+Narr[k];
                }
            }
        }
    }
    printf("%d",blackjack);




    free(Narr);
    return 0;
}