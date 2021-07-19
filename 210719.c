#include <stdio.h>
#include <stdlib.h>
//#10250
int roomChoose(int,int,int);
int main(void){
    int i,j,k;
    int T;//testcase
    int *H,*W;//height width (1 ≤ H, W ≤ 99, 1 ≤ N ≤ H × W)
    int* N;//테스트케이스에서 구하는 N번쨰 손님들을 저장하는 배열
    scanf("%d",&T);
    getchar();
    
    N=(int*)malloc(sizeof(int)*T);
    H=(int*)malloc(sizeof(int)*T);
    W=(int*)malloc(sizeof(int)*T);
    for(i=0;i<T;i++){
        scanf("%d %d %d",&H[i],&W[i],&N[i]);
        getchar();
        
    }
    for(i=0;i<T;i++){
        printf("%d\n",roomChoose(N[i],H[i],W[i]));
    }
    
    free(N);
    free(H);
    free(W);
    return 0;
}
int roomChoose(int N, int height, int width){
    int i=1,j;
    int roomNumber;
    int floor=1,hosu=1;
    
    for(i=1;i<=N;i++){//i가 1부터 N까지 증가
        if(i==N)break;//만약 i가 N인데 종료 안시키면 호수나 층수를 한번 더 더함
        if(floor==height){//만약 i가 현재 꼭대기 층이면 호수++, 1층으로
            hosu++;
            floor=1;
            continue;
        }
        floor++;//아니면 층수++
    }
    
    roomNumber=100*floor+hosu;
    return roomNumber;

}