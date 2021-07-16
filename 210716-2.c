#include <stdio.h>
#include <stdlib.h>
//#2920 //#10818 #11654 #11720
int main(void){
    /* #10818
    int scale[8]={0};
    int ascendingFlag=1;
    int descendingFlag=1;
    int mixed=0;
    for(int i=0;i<8;i++){
        scanf("%d",scale+i);
    }
    for(int i=0;i<8;i++){
        if(i==0)continue;
        if(scale[i-1]<scale[i])descendingFlag=0;
        if(scale[i-1]>scale[i])ascendingFlag=0;
    }
    if((ascendingFlag==0)&&(descendingFlag==0))mixed=1;
    if(ascendingFlag==1)printf("ascending");
    if(descendingFlag==1)printf("descending");
    if(mixed==1)printf("mixed");
    */
   /*  //#10818
    int N;//입력받는 정수의 개수
    int* arr;
    int min=0,max=0;//최솟값 최댓값
    scanf("%d",&N);
    getchar();
    arr=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++){
        scanf("%d",arr+i);
    }
    for(int i=0;i<N;i++){
        if(i==0){
            min=arr[0];
            max=arr[0];
            continue;
        }
        if(min>arr[i])min=arr[i];
        if(max<arr[i])max=arr[i];
    }
    printf("%d %d",min,max);
    free(arr);

    */
    /* //#11654
    char ascii;
    scanf("%c",&ascii);
    printf("%d",ascii);
    */
    int N;//입력받을 숫자의 개수 1<=N<=100
    int sum=0;//입력받은 숫자들의 합
    char arr[100]={0};
    scanf("%d",&N);
    scanf("%s",arr);
    for(int i=0;i<N;i++){
        sum+=((int)arr[i]-48);
    }
    printf("%d",sum);





    return 0;
}