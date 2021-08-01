#include <stdio.h>
#include <stdlib.h>
//#1931
int sorted[100000]={0};
int rightsorted[100000]={0};
void divide(int*,int*,int,int);
void mergeNsort(int*,int*,int,int,int);
int main(void){
    int i,j=0;
    int N;
    int* startT;
    int* endT;
    int ans=0;
    scanf("%d",&N);
    startT=(int*)malloc(sizeof(int)*N);
    endT=(int*)malloc(sizeof(int)*N);
    for(i=0;i<N;i++){
        scanf("%d %d",startT+i,endT+i);
    }
    divide(startT,endT,0,N-1);
    i=0;
    while(i<N){
        ans++;
        for(j=i+1;j<N;j++)if(startT[j]>=endT[i])break;
        i=j;
    }
    printf("%d",ans);

    free(startT);
    free(endT);
    return 0;
}
void divide(int* arr, int* Rarr, int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        divide(arr,Rarr,left,mid);
        divide(arr,Rarr,mid+1,right);
        mergeNsort(arr,Rarr,left,mid,right);
    }
}
void mergeNsort(int* arr, int* Rarr, int left, int mid, int right){//종료시간 기준 정렬
    int i=left,j=mid+1;
    int s=left;
    int k;
    while(10){
        if(i>mid || j>right)break;
        if(Rarr[i]<Rarr[j]){
            sorted[s]=arr[i];
            rightsorted[s]=Rarr[i];
            s++;
            i++;
        }
        else if (Rarr[i]>Rarr[j]){
            sorted[s]=arr[j];
            rightsorted[s]=Rarr[j];
            s++;
            j++;
        }
        else{//종료 시간이 동일하면 시작시간이 빠른 것을 우선으로 삽입
            if(arr[i]<arr[j]){
                sorted[s]=arr[i];
                rightsorted[s]=Rarr[i];
                i++;
            }
            else{
                sorted[s]=arr[j];
                rightsorted[s]=Rarr[j];
                j++;
            }
            s++;
        }
    }
    if(i>mid){
        for(k=j;k<right+1;k++){
            sorted[s]=arr[k];
            rightsorted[s]=Rarr[k];
            s++;
        }
    }
    else if(j>right){
        for(k=i;k<mid+1;k++){
            sorted[s]=arr[k];
            rightsorted[s]=Rarr[k];
            s++;
        }
    }
    for(k=left;k<right+1;k++){
        arr[k]=sorted[k];
        Rarr[k]=rightsorted[k];
    }
}