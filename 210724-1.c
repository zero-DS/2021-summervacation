#include <stdio.h>
#include <string.h>

//#10866
/*
push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
int deque[10000]={0};
int frontN=-1,backN=-1;
void push_front(int);
void push_back(int);
int pop_front();
int pop_back();
int size();
int empty();
int front();
int back();

int main(void){
    int N;
    int i;
    char command[11]={0};
    int cmdNum;
    scanf("%d",&N);
    getchar();
    for(i=0;i<N;i++){
        scanf("%s",command);
        if(strcmp(command,"pop_front")==0)printf("%d\n",pop_front());
        else if (strcmp(command,"pop_back")==0)printf("%d\n",pop_back());
        else if (strcmp(command,"size")==0)printf("%d\n",size());
        else if (strcmp(command,"empty")==0)printf("%d\n",empty());
        else if (strcmp(command,"front")==0)printf("%d\n",front());
        else if (strcmp(command,"back")==0)printf("%d\n",back());
        else{
            if(strcmp(command,"push_front")==0){
                scanf("%d",&cmdNum);
                getchar();
                push_front(cmdNum);
            }
            else if(strcmp(command,"push_back")==0){
                scanf("%d",&cmdNum);
                getchar();
                push_back(cmdNum);
            }
        }
    }



    return 0;
}
void push_front(int n){
    int i;
    if(frontN==-1){
        frontN++;
        backN++;
        deque[frontN]=n;
    }
    else if (frontN==0){
        for(i=backN;i>=frontN;i--){
            deque[i+1]=deque[i];
        }
        backN++;
        deque[frontN]=n;
    }
    else {
        frontN--;
        deque[frontN]=n;
    }
}
void push_back(int n){
    if(frontN==-1)frontN++;
    backN++;
    deque[backN]=n;
}
int pop_front(){
    int temp;
    if(frontN==-1)return -1;
    temp=deque[frontN];
    deque[frontN]=0;
    if(frontN==backN){
        frontN=-1;
        backN=-1;
    }
    else frontN++;
    return temp;
}
int pop_back(){
    int temp;
    if(frontN==-1)return -1;
    temp=deque[backN];
    deque[backN]=0;
    if(frontN==backN){
        frontN=-1;
        backN=-1;
    }
    else backN--;
    return temp;
}
int size(){
    int size;
    if(frontN==-1)size=0;
    else size=backN-frontN+1;
    return size;
}
int empty(){
    if (frontN==-1)return 1;
    else return 0;
}
int front(){
    if(frontN==-1)return -1;
    else return deque[frontN];
}
int back(){
    if(backN==-1)return -1;
    else return deque[backN];
}