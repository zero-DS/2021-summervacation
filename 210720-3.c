#include <stdio.h>

//#1259
int main(void){
    int N;//N<99999
        
    while(1){
        scanf("%d",&N);
        if(N==0)break;
        if(N<10)printf("yes\n");
        else if(N>9 && N<100){
            if(N%10==N/10)printf("yes\n");
            else printf("no\n");
        }
        else if(N>99 && N<1000){
            if(N%10==N/100)printf("yes\n");
            else printf("no\n");
        }
        else if (N>999 && N<10000){
            if(N%10==N/1000 && (N/10)%10==(N/100)%10)printf("yes\n");
            else printf("no\n");
        }
        else if(N>9999 && N<100000){
            if(N%10==N/10000 && (N/10)%10==(N/1000)%10)printf("yes\n");
            else printf("no\n");
        }
        else break;
        
        
    }


    return 0;
}