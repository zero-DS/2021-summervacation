#include <stdio.h>
#include <stdlib.h>

//#2503
int checkStrike(int,int);
int checkBall(int,int);
int main(){
    int i,j,k,N;
    int hun,ten,one,temp;
    int thousand[1000]={0};
    int* guess;//물어본 숫자, 스트라이크, 볼
    int* S;
    int* B;
    int ans;//정답
    int possibleCnt=0;

    scanf("%d",&N);//질문한 횟수 1<=N<=100
    getchar();
    guess=(int*)malloc(sizeof(int)*N);
    S=(int*)malloc(sizeof(int)*N);
    B=(int*)malloc(sizeof(int)*N);
    for(i=111;i<1000;i++){
        thousand[i]=i;
    }
    for(i=111;i<1000;i++){
        temp=i;
        one=temp%10;
        temp/=10;
        ten=temp%10;
        temp/=10;
        hun=temp%10;
        if((one==ten)||(ten==hun)||(one==hun))thousand[i]=0;
        if((one==0)||(ten==0)||(hun==0))thousand[i]=0;
    }

    
    
    for(i=0;i<N;i++){
        scanf("%d %d %d",guess+i,S+i,B+i);
    }
    getchar();
    /*for(i=111;i<1000;i++) printf("%d ",thousand[i]);
    for(i=0;i<N;i++){
        printf("guess: %d S: %d B: %d \n",guess[i],S[i],B[i]);
    }*/

    for(i=0;i<N;i++){
        for(j=111;j<1000;j++){
            if(thousand[j]==0)continue;
            if(!((S[i]==checkStrike(thousand[j],guess[i]))&&(B[i]==checkBall(thousand[j],guess[i])))){
                //printf("\nthousand%d=0",j);
                thousand[j]=0;
            }//스트라이크와 볼이 동시에 일치하지 않으면 111-999배열의 해당 값을 0으로 만듦
            
        }
    }
    
    for(i=111;i<1000;i++){
        if(thousand[i]!=0){
            possibleCnt++;
            //printf("일치하네염: %d\n",thousand[i]);
        }
    }
    
    
    printf("%d",possibleCnt);

    free(guess);
    free(S);
    free(B);
    return 0;
}
int checkStrike(int thous, int gue){
    int i,j;
    int strcnt=0;
    int th[3]={0};
    int gu[3]={0};
    for(i=0;i<3;i++){
        th[i]=thous%10;
        thous/=10;
    }
    for(j=0;j<3;j++){
        gu[j]=gue%10;
        gue/=10;
        }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if((i==j)&&(th[i]==gu[j]))strcnt++;
        }
    }
    /*
    while(thous/10){
        if(thous%10==gue%10){
            strcnt++;
            
        }
        thous/=10;
        gue/=10;
    }
    */
    //printf("strcnt: %d\n",strcnt);
    return strcnt;
}
int checkBall(int thous, int gue){
    int i,j;
    int temp;
    int balcnt=0;
    int th[3]={0};
    int gu[3]={0};
    for(i=0;i<3;i++){
        th[i]=thous%10;
        thous/=10;
    }
    for(j=0;j<3;j++){
        gu[j]=gue%10;
        gue/=10;
    }
 
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if((i!=j)&&(th[i]==gu[j])){
                
                balcnt++;
            }
        }
    }
    /*
    do{
        temp=gue;
        do{
            if(thous%10==temp%10){
                balcnt++;
            }
            temp/=10;
        }while(temp/10);
    thous/=10;
    }while(thous/10);
    */
    
    //printf("balcnt: %d\n",balcnt);
    return balcnt;
}