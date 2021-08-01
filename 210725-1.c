#include <stdio.h>

//#1003

int main(void){
    int T;
    int i;
    int num;
    int fibo[41]={0,1,1};
    for(i=3;i<41;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    scanf("%d",&T);
    getchar();
    for(i=0;i<T;i++){
        scanf("%d",&num);
        getchar();
        if(num==0){
            printf("%d %d\n",1,0);
            continue;
        }
        printf("%d %d\n",fibo[num-1],fibo[num]);
    }


    return 0;
}
