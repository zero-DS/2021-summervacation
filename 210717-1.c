#include <stdio.h>
#include <stdlib.h>
//#1920
/*
10
3 30 6 27 9 12 24 15 21 18
15
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 
*/
void quickSort(int*,int,int);
int pivotDivide(int*,int,int);
int divideTwoSearch(int*,int,int,int,int,int);
int divideSearch(int*,int,int,int);
int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

int main (void){
    int N,M;
    int i,j;
    int* Narr;//N개 숫자 저장 배열, 정렬해야될 배렬
    int* Marr;//M개 숫자 저장 배열

    scanf("%d",&N);
    getchar();
    Narr=(int*)malloc(sizeof(int)*N);
    for(i=0;i<N;i++)scanf("%d",Narr+i);
    getchar();
    qsort(Narr, N, sizeof(int), compare);
    

    scanf("%d",&M);
    getchar();
    Marr=(int*)malloc(sizeof(int)*M);
    for(i=0;i<M;i++)scanf("%d",Marr+i);
    getchar();
    for(i=0;i<M;i++){
        printf("%d\n",divideSearch(Narr,0,N-1,Marr[i]));
    }
    
    free(Narr);
    free(Marr);
    return 0;
}
void quickSort(int* unsorted,int left,int right){
    if(left<right){
        int pivot=pivotDivide(unsorted,left,right);
        quickSort(unsorted,left,pivot-1);
        quickSort(unsorted,pivot+1,right);
    }
}
int pivotDivide(int* undivided,int left,int right){
    int temp;
    int pivot=undivided[left];//pivot을 임의로 맨 왼쪽 숫자로 정함
    int low,high;
    low=left+1;
    high=right;
    while(low<high){
        while(low<right && pivot>=undivided[low])low++;
        while(high>left && pivot<=undivided[high])high--;
        if(low<high){
            temp=undivided[low];
            undivided[low]=undivided[high];
            undivided[high]=temp;
        }
    }
    temp=undivided[left];
    undivided[left]=undivided[high];
    undivided[high]=temp;
    return high;

}
int divideTwoSearch(int* arr, int N, int startNum, int endNum, int key, int findFlag){
    int dividePivot;
    dividePivot=((endNum-startNum)/2)+startNum;
    if(key==arr[dividePivot])findFlag=1;
    else if(key>arr[dividePivot]){
        if(dividePivot==N-1)return findFlag;
        findFlag=divideTwoSearch(arr,N,dividePivot+1,endNum,key,findFlag);
    }
    else if(key<arr[dividePivot]){
        if(dividePivot==0)return findFlag;
        findFlag=divideTwoSearch(arr,N,startNum,dividePivot-1,key,findFlag);
    }
    
    return findFlag;
}
int divideSearch(int* arr, int low, int high,int key){
    int mid;
    while(low<=high){
    mid=(low+high)/2;
    if(arr[mid]==key)return 1;
    else if(arr[mid]<key)low=mid+1;
    else high=mid-1;
    }
    return 0;
}