#include <stdio.h>
//#9095
int main(void){
    int T;
    int num;//0<N<11
    int i;
    int arr[11]={1,2,4};
    for(i=3;i<11;i++)arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&num);
        printf("%d\n",arr[num-1]);
    }

    return 0;
}