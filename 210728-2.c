#include <stdio.h>
#include <stdlib.h>
//#11399
int sorted[1000]={0};
void divide(int*,int,int);
void mergeNsort(int*,int,int,int);
int main(void){
    int i;
    int N;
    int* Parr;
    int* DP;
    int ans=0;
    scanf("%d",&N);
    Parr=(int*)malloc(sizeof(int)*N);
    DP=(int*)malloc(sizeof(int)*N);
    for(i=0;i<N;i++){
        scanf("%d",Parr+i);
    }
    divide(Parr,0,N-1);
    DP[0]=Parr[0];
    ans+=DP[0];
    for(i=1;i<N;i++){
        DP[i]=DP[i-1]+Parr[i];
        ans+=DP[i];
    }
    printf("%d",ans);
    free(Parr);
    free(DP);

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
        else{
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
    for(k=left;k<right+1;k++)arr[k]=sorted[k];
}