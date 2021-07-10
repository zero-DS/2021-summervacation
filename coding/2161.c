#include <stdio.h>
#include <stdlib.h>

void func(int*,int*,int,int);
int* left(int*,int,int);

int main(void){
    int N;
    int* array;
    int* discard;
    
    printf("1이상 1000이하 정수입력 : ");
    scanf("%d",&N);
    array=(int*)malloc(sizeof(int)*N);
    discard=(int*)malloc(sizeof(int)*(N-1));
    for(int i=0;i<N;i++){
        array[i]=i+1;
    }
    
    for(int i=0;i<N-1;i++){
        func(array,discard,N,i);
    }
    for(int i=0;i<N-1;i++) printf("%d ",discard[i]);
    printf("%d",array[0]);
    
    free(array);
    free(discard);

return 0;
}

void func(int* arr,int* dis,int N,int disI){
    dis[disI]=arr[0];
    arr[0]=arr[N-disI-1];
    arr[N-disI-1]='\0';
}
int* left(int* arr,int N,int disI){
    int temp=arr[0];
    for(int i=0;i<N-disI-1;i++){
        arr[i]=arr[i+1];
    }
    arr[N-disI-1]=temp;
    return arr;
}
