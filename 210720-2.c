#include <stdio.h>
#include <stdlib.h>
//#11050
int fact(int);
int main (void){
    int N,K;
    int ans;
    int boonja=1,boonmo;
    scanf("%d %d",&N,&K);
    //boonja=fact(N);
    for(int i=N;i>N-K;i--){
        if(i==0)continue;
        boonja*=i;
    }
    boonmo=fact(K);
    ans=boonja/boonmo;
    printf("%d",ans);


    return 0;
}

int fact(int n){
    if(n==0)return 1;
    else return fact(n-1)*n;
}