#include <stdio.h>
#include <stdlib.h>

//#2609
int getGCD(int,int);
int getLCM(int,int);
int main(void){
    int a,b;
    int GCD,LCM;//최대공약수 최소공배수
    scanf("%d %d",&a,&b);
    printf("%d\n%d",getGCD(a,b),getLCM(a,b));

    return 0;
}

int getGCD(int a, int b){
    int GCD;
    int bignum;
    if(a<b){
        GCD=a;
        bignum=b;
    }
    else {
        GCD=b;
        bignum=a;
    }
    for(int i=GCD;i>0;i--){
        if(bignum%i==0 && GCD%i==0){
            GCD=i;
            break;
        }
    }
    return GCD;
}
int getLCM(int a, int b){
    int smallnum;
    int bignum;
    int LCM;
    if(a<b){
        smallnum=a;
        bignum=b;
    }
    else {
        smallnum=b;
        bignum=a;
    }
    for(int i=1;i<smallnum+1;i++){
        if((bignum*i)%smallnum==0){
            LCM=bignum*i;
            break;
        }
    }
    return LCM;
}