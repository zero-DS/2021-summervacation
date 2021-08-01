#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#1764
char* address[1000000]={0};
int uhuscnt=0;
char* uhus[500000]={0};
void unheardunseen(char**,char*,int,int);
void divide(char**,int,int);
void mergeNsort(char**,int,int,int);
int main(void){
    int i;
    int N,M;//500000이하
    char** person;
    scanf("%d %d",&N,&M);
    person=(char**)malloc(sizeof(char*)*(N+M+1));
    for(i=0;i<N+M;i++)person[i]=(char*)malloc(sizeof(char)*21);
    for(i=0;i<N;i++){
        scanf("%s",person[i]);
    }
    for(i=0;i<M;i++){
        scanf("%s",person[N+i]);
    }
    divide(person,0,N-1);
    divide(person,N,N+M-1);
    for(i=N;i<N+M;i++){
        unheardunseen(person,person[i],0,N-1);
    }
    printf("%d\n",uhuscnt);
    for(i=0;i<uhuscnt;i++){
        printf("%s\n",uhus[i]);
    }
    


    for(i=0;i<N+M;i++){
        free(person[i]);
    }
    free(person);

    return 0;
}
void unheardunseen(char** arr,char* key,int left,int right){
    int mid=(left+right)/2;
    if(left<=right){
    if(strcmp(key,arr[mid])<0)unheardunseen(arr,key,left,mid-1);
    else if(strcmp(key,arr[mid])>0)unheardunseen(arr,key,mid+1,right);
    else {
        uhus[uhuscnt]=key;
        uhuscnt++;
    }
    }
}
void divide(char** arr, int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        divide(arr,left,mid);
        divide(arr,mid+1,right);
        mergeNsort(arr,left,mid,right);
    }
}
void mergeNsort(char** arr, int left, int mid, int right){
    int i=left,j=mid+1;
    int s=left;
    int k;
    while(1){
        if(i>mid || j>right)break;
        if(strcmp(arr[i],arr[j])<0){
            address[s]=arr[i];
            s++;
            i++;
        }
        else{
            address[s]=arr[j];
            s++;
            j++;
        }
    }
    if(i>mid){
        for(k=j;k<right+1;k++){
            address[s]=arr[k];
            s++;
        }
    }
    else if(j>right){
        for(k=i;k<mid+1;k++){
            address[s]=arr[k];
            s++;
        }
    }
    for(k=left;k<right+1;k++)arr[k]=address[k];

}

