#include <stdio.h>
#include <stdlib.h>
//#11726
int main(void){
    int i;
    int N;
    int* DP;
    scanf("%d",&N);
    DP=(int*)malloc(sizeof(int)*N);
    DP[0]=1;
    DP[1]=2;
    for(i=2;i<N;i++){
        DP[i]=(DP[i-1]+DP[i-2])%10007;
    }
    
    printf("%d",DP[N-1]);


    return 0;
}