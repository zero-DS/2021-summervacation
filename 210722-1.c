#include <stdio.h>
#include <stdlib.h>

//#2164
int main(void){
    int i,j;
    int N;//1<=N<=500000
    scanf("%d",&N);
    int cardN=N;
    int top=0;
    int bottom=N-1;
    int* Narr=(int*)malloc(sizeof(int)*(N+1)*2);
    for(i=0;i<N;i++)Narr[i]=i+1;
    while(1){
        if(N==1)break;
        Narr[top]=0;
        cardN--;
        top++;
        if(cardN==1)break;
        Narr[bottom+1]=Narr[top];
        Narr[top]=0;
        top++;
        bottom++;
    }
    printf("%d",Narr[top]);



    free(Narr);
    return 0;
}