#include <stdio.h>
//2309
int main (void){
    int nanj[9]={0,};
    int real[7]={0,};
    int i=0,j=0;
    int sum=0;
    int gajja1=0,gajja2=0;
    for(i=0;i<9;i++) {
        scanf("%d",nanj+i);
        sum+=nanj[i];
    }
    
   
    for(i=0;i<9;i++){//i가 첫번째 가짜
        for(j=i+1;j<9;j++){//j가 두번째 가짜
            if(sum-nanj[i]-nanj[j]==100){
                gajja1=i;
                gajja2=j;
                //printf("\n %d %d \n",gajja1,gajja2);
                break;
            }
        }
    }
    
    j=0;
    for(i=0;i<9;i++){
        if (i==gajja1||i==gajja2) continue;
        real[j]=nanj[i];
        j++;
    }
    int temp;
    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            if(real[i]<real[j]){
                temp=real[i];
                real[i]=real[j];
                real[j]=temp;
            }
        }
    }
   
    for(i=0;i<7;i++) printf("%d\n",real[i]);
    


    return 0;
}
