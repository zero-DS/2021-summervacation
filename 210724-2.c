#include <stdio.h>
#include <stdlib.h>
//#10816

int sorted[500000]={0};

void divide(int*,int,int);
void mergeNsort(int*,int,int,int);
int lowerbound(int*,int,int);
int upperbound(int*,int,int);

int main(void){
    int i;
    int N,M;//1<=N,M<=500000
    int* Narr;
    int checkExistNum;
    scanf("%d",&N);
    Narr=(int*)malloc(sizeof(int)*N);
    for(i=0;i<N;i++){
        scanf("%d",Narr+i);
    }
    getchar();
    divide(Narr,0,N-1);
    scanf("%d",&M);
    getchar();
    for(i=0;i<M;i++){
        scanf("%d",&checkExistNum);
        if(i==M-1){
            if(lowerbound(Narr,N,checkExistNum)==-1)printf("%d",0);
            else printf("%d",upperbound(Narr,N,checkExistNum)-lowerbound(Narr,N,checkExistNum)+1);
        }
        else{
            if(lowerbound(Narr,N,checkExistNum)==-1)printf("%d ",0);
            else printf("%d ",upperbound(Narr,N,checkExistNum)-lowerbound(Narr,N,checkExistNum)+1);
        }
    }


    free(Narr);
    return 0;
}
void divide(int* arr, int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        divide(arr,left,mid);
        divide(arr,mid+1,right);
        mergeNsort(arr,left,mid,right);
    }
}
void mergeNsort(int* arr, int left, int mid, int right){
    int i=left,j=mid+1;
    int s=left;
    int k;
    while(1){
        if(i>mid || j>right)break;
        if(arr[i]<arr[j]){
            sorted[s]=arr[i];
            s++;
            i++;
        }
        else {
            sorted[s]=arr[j];
            s++;
            j++;
        }
    }
    if(i>mid){
        for(k=j;k<right+1;k++){
            sorted[s]=arr[k];
            s++;
        }
    }
    else if(j>right){
        for(k=i;k<mid+1;k++){
            sorted[s]=arr[k];
            s++;
        }
    }
    for(k=left;k<right+1;k++){
        arr[k]=sorted[k];
    }
}
int lowerbound(int* arr, int arrNum, int num){
    int left,mid,right;
    left=0;
    right=arrNum-1;
    while(1){
        mid=(left+right)/2;
        if(left>right){
            if(arr[left]==num)return left;
            else return -1;
        }
        if(arr[mid]<num){
            left=mid+1;
        }
        else if(arr[mid]>=num){
            right=mid-1;
        }
    }
}
int upperbound(int* arr, int arrNum, int num){
    int left,mid,right;
    left=0;
    right=arrNum-1;
    while(1){
        mid=(left+right)/2;
        if(left>right){
            if(arr[right]==num)return right;
            else return -1;
        }
        if(arr[mid]<=num){
            left=mid+1;
        }
        else if(arr[mid>num]){
            right=mid-1;
        }
    }
}
