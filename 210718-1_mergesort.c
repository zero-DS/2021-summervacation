#include <stdio.h>
#include <stdlib.h>
//#2751
int sorted[1000000];//정렬된 배열 저장용 함수, 전역 변수 선언, 문제조건 따라 크기는 백만
void divide(int*, int, int);
void mergeNsort(int*, int, int, int);
int main (void){
    int N;
    int* arr;
    scanf("%d",&N);
    arr=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)scanf("%d",arr+i);
    divide(arr,0,N-1);
    for(int i=0;i<N;i++)printf("%d\n",arr[i]);




    return 0;
}
void divide(int* arr, int left, int right){
    if(left<right){//정렬할 원소들의 개수가 2개이상일 때
        int mid=(left+right)/2;//입력받은 범위인 left와 right간의 중간지점
        divide(arr,left,mid);//입력받은 맨 앞인 left부터 중간지점까지 다시 나누기
        divide(arr,mid+1,right);//중간지점부터 입력받은 맨 뒤인 right까지 다시 나누기
        mergeNsort(arr,left,mid,right);//윗줄과 윗윗줄에서 왼쪽 오른쪽으로 나눈 부분정렬들을 정렬하면서 병합
    }
}
void mergeNsort(int* arr, int left, int mid, int right){
    int i=left;
    int j=mid+1;
    int k=left;//k가 sorted의 index
    //왼쪽 정렬과 오른쪽 정렬을 서로 비교하면서 작은 것부터 sorted에 저장
    while(i<=mid && j<=right){//왼쪽 정렬 맨 왼쪽부터 mid까지, 오른쪽 정렬 mid+1부터 맨 오른쪽까지 비교
        if(arr[i]<=arr[j]){//왼쪽 정렬의 현재 숫자가 작으면 sorted에 저장
            sorted[k]=arr[i];
            i++;
        }
        else {
            sorted[k]=arr[j];
            j++;
        }
        k++;//한번 저장 할때마다 sorted의 index 증가
    }//while문이 끝나면 왼쪽과 오른쪽 정렬 중 하나는 맨 끝에 도달한것
    if(j>right){//남은 것들 sorted에 넣어주기
        for(int l=i;l<=mid;l++){
            sorted[k++]=arr[l];
        }
    }
    else{
        for(int l=j;l<=right;l++){
            sorted[k++]=arr[l];
        }
    }

    for(int l=left;l<=right;l++){
        arr[l]=sorted[l];
    }//원래 배열인 arr에 sorted를 복사
}