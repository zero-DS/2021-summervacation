#include <stdio.h>
#include <stdlib.h>
//#11650
int sorted[100000]={0};
int tempY[100000]={0};
void divide(int*,int*,int,int);
void mergeNsort(int*,int*,int,int,int);
int main(void){
    int N;//1<=N<=100000
    int *NarrX, *NarrY;
    scanf("%d",&N);
    NarrX=(int*)malloc(sizeof(int)*N);
    NarrY=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++){
        scanf("%d %d",NarrX+i,NarrY+i);
        getchar();
    }
    divide(NarrX,NarrY,0,N-1);
    for(int i=0;i<N;i++){
        printf("%d %d\n",NarrX[i],NarrY[i]);
    }


    free(NarrX);
    free(NarrY);
    return 0;
}
void divide(int* arr, int* arrY, int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        divide(arr,arrY,left,mid);
        divide(arr,arrY,mid+1,right);
        mergeNsort(arr,arrY,left,mid,right);
    }
}
void mergeNsort(int* arr, int* arrY, int left, int mid, int right){
    int s=left;
    int i=left,j=mid+1;
    while(1){
        if(i>mid || j>right)break;
        if(arr[i]<arr[j]){
            sorted[s]=arr[i];
            tempY[s]=arrY[i];
            s++;
            i++;
        }
        else if (arr[i]>arr[j]){
            sorted[s]=arr[j];
            tempY[s]=arrY[j];
            s++;
            j++;
        }
        else{
            if(arrY[i]<arrY[j]){
                sorted[s]=arr[i];
                tempY[s]=arrY[i];
                s++;
                i++;
            }
            else {
                sorted[s]=arr[j];
                tempY[s]=arrY[j];
                s++;
                j++;
            }
        }
    }
    if(i==mid+1){
        while(j<right+1){
            sorted[s]=arr[j];
            tempY[s]=arrY[j];
            s++;
            j++;
        }
    }
    else if(j==right+1){
        while(i<mid+1){
            sorted[s]=arr[i];
            tempY[s]=arrY[i];
            s++;
            i++;
        }
    }
    for(i=left;i<right+1;i++){
        arr[i]=sorted[i];
        arrY[i]=tempY[i];
    }
}