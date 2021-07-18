#include <stdio.h>
#include <stdlib.h>
/* testcase
9
5 3 8 4 9 1 6 2 7
*/
void sort(int*,int,int);
int pivotDivide(int*,int,int);
int main (void){
    int N;//입력받을 정렬할 원소들의 개수
    int i;
    scanf("%d",&N);
    int* arr=(int*)malloc(sizeof(int)*N);
    for(i=0;i<N;i++){
        scanf("%d",arr+i);
    }
    sort(arr,0,N-1);//arr의 0번쨰 원소부터 N-1번까지 N개 원소를 정렬
    for(i=0;i<N;i++){
        printf("%d ",arr[i]);
    }



    return 0;
}
void sort(int* unsorted,int left,int right){
    if(left<right){//정렬할 원소의 개수가 2개부터 정렬하는게 의미가 있음
        int pivot=pivotDivide(unsorted,left,right);//비균등 분할,피벗 반환
        sort(unsorted,left,pivot-1);//맨 앞부터 피벗 바로 전까지 정렬
        sort(unsorted,pivot+1,right);//피벗 바로 뒤부터 맨 뒤까지 정렬
    }
}
int pivotDivide(int* undivided,int left,int right){
    int pivot=undivided[left];//일단 맨 앞의원소를 피벗으로 지정
    int low,high;
    int temp;//low와 high를 맞바꿀때 임시저장
    low=left+1;//left는 피벗이기 때문에 +1한 값부터 시작
    high=right;
    //printf("작업전 left:%d right:%d\n",left,right);
    while(low<high){//아직 로우와 하이가 만나지 않았을 때까지 반복
        while(low<right && pivot>=undivided[low])low++;//피벗이 로우보다 작기 전까지 로우를 증가시킴
        while(high>left && pivot<=undivided[high])high--;//피벗이 하이보다 크기 전까지 하이를 감소시킴
        if(low<high){
        temp=undivided[low];
        undivided[low]=undivided[high];
        undivided[high]=temp;//로우와 하이를 뒤바꿈
        }
    }//while문 끝났을 때는 하이가 로우보다 작거나 같음
    temp=undivided[left];
    undivided[left]=undivided[high];
    undivided[high]=temp;//high와 left를 맞바꿈
    return high;
}