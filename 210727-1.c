#include <stdio.h>
//#1463
#define TABLENUM 1000001
int ThreeTwoTable[TABLENUM]={0,1,1};
int main(void){
    int N;//1<=N<=1000000
    int i=0;
    int tempminus,temp2,temp3;
    for(i=3;i<TABLENUM;i++){
        tempminus=ThreeTwoTable[i-1]+1;
        if((i+1)%2==0 && (i+1)%3==0){
            temp3=ThreeTwoTable[i/3]+1;
            temp2=ThreeTwoTable[i/2]+1;
            if(tempminus<=temp2 && tempminus<=temp3)ThreeTwoTable[i]=tempminus;
            else if(temp2<=tempminus && temp2<=temp3)ThreeTwoTable[i]=temp2;
            else if(temp3<=tempminus && temp3<=temp2)ThreeTwoTable[i]=temp3;
            continue;
        }
        if((i+1)%3==0){
            temp3=ThreeTwoTable[i/3]+1;
            if(tempminus<=temp3)ThreeTwoTable[i]=tempminus;
            else ThreeTwoTable[i]=temp3;
            continue;
        }
        if((i+1)%2==0){
            temp2=ThreeTwoTable[i/2]+1;
            if(tempminus<=temp2)ThreeTwoTable[i]=tempminus;
            else ThreeTwoTable[i]=temp2;
            continue;
        }
        if((i+1)%3!=0 && (i+1)%2!=0)ThreeTwoTable[i]=tempminus;   
    }
    
    scanf("%d",&N);
    printf("%d\n",ThreeTwoTable[N-1]);
    
    return 0;
}
