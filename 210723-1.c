#include <stdio.h>
#include <stdlib.h>
//#10814
int sorted[100000]={0};
char* sortedName[100000]={0};
void divide(int*,char**,int,int);
void mergeNsort(int*,char**,int,int,int);
int main(void){
    int i,j;
    int N;//1<=N<=100000,나이는 200이하, 이름은 100자 이하
    int *agearr;
    char** namearr;
    scanf("%d",&N);
    agearr=(int*)malloc(sizeof(int)*N);
    namearr=(char**)malloc(sizeof(char*)*(N+1));
    for(i=0;i<N;i++)namearr[i]=(char*)malloc(sizeof(char)*101);
    for(i=0;i<N;i++){
        scanf("%d %s",&agearr[i],namearr[i]);
        getchar();
    }
    divide(agearr,namearr,0,N-1);
    for(i=0;i<N;i++)printf("%d %s\n",agearr[i],namearr[i]);


    for(i=0;i<N;i++)free(namearr[i]);
    free(namearr);
    free(agearr);
    return 0;
}
void divide(int* arr, char** name, int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        divide(arr,name,left,mid);
        divide(arr,name,mid+1,right);
        mergeNsort(arr,name,left,mid,right);
    }
}
void mergeNsort(int* arr, char** name, int left, int mid, int right){
    int i=left,j=mid+1;
    int k;
    int s=left;
    while(1){
        if(i>mid || j>right)break;
        if(arr[i]<=arr[j]){
            sorted[s]=arr[i];
            sortedName[s]=name[i];
            i++;
            s++;
        }
        else {
            sorted[s]=arr[j];
            sortedName[s]=name[j];
            j++;
            s++;
        }
    }
    if(i>mid){
        for(k=j;k<right+1;k++){
            sorted[s]=arr[k];
            sortedName[s]=name[k];
            s++;
        }
    }
    else if (j>right){
        for(k=i;k<mid+1;k++){
            sorted[s]=arr[k];
            sortedName[s]=name[k];
            s++;
        }
    }
    for(k=left;k<right+1;k++){
        arr[k]=sorted[k];
        name[k]=sortedName[k];
    }
}