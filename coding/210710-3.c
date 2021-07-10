#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*
II. 스케줄 관리를 위한 프로그램을 연결리스트로 구현하시오.
1. 스케줄 삽입 (무작위로 생성되며, 일정에 맞게 삽입)
2. 스케줄 수정
3. 스케줄 삭제
4. 스케줄 확인
*/
typedef struct schnode{
    int month,day;
    int time[24];
    char schName[20];
    struct schNode* prev;
    struct schNode* next;
}schNode;
schNode* head;
schNode* tail;

schNode* newsch(schNode*);
schNode* modsch(schNode*);
schNode* delsch(schNode*);
void checksch(schNode*);
void init();

int main (void){
    init();
    printf("%d",head->day);


    return 0;
}

void init (){
   
    head= (schNode*)malloc(sizeof(schNode));
    tail= (schNode*)malloc(sizeof(schNode));
    head->day=0,head->month=0,tail->day=0,tail->month=0;
    memset(head->time,0,sizeof(head->time));
    memset(head->schName,0,sizeof(head->schName));
    memset(tail->time,0,sizeof(head->time));
    memset(tail->schName,0,sizeof(head->schName));
    head->prev=NULL;
    head->next=tail;
    tail->prev=head;
    tail->next=NULL;
}