#include <stdio.h>
#include <stdlib.h>
/*
I. 아래의 두 다항식을 단순 연결리스트로 관리하여 f+g 와 f-g를 계산하시오. f = 5x12 – 3x9 + 2x7 – 10x5 + 5x4 – 8x3 + 6x2 – 4x + 10
g = 13x11 + 7x10 + 5x9 + 3x8 – 4x7 + x6 – 12x5 + 9x4 - 5x3 + x2 + 7x - 23

*/
typedef struct hang{
    int coef;
    int jegob;
    struct Hang* next;
}Hang;
Hang* head;
Hang* head2;
Hang* makeHang(int,int,Hang*);
Hang* makeHead(Hang*);

int main(void){
    int co,je;
    Hang* head = makeHead(head);
    Hang* current = head;
    printf("다항식을 입력 받습니다.\n");
    printf("계수와 차수를 순서대로 입력해주세요 : \n");
    printf("그만 입력 하고 싶다면 0 0를 입력해주세요. \n");
    do{
        scanf("%d %d",&co,&je);
        if(co==0&&je==0) break;
        current=makeHang(co,je,current);
    }while(1);
    current=(head->next);
    printf("다항식 f : ");
    while(1){
        printf("%dx^%d",current->coef,current->jegob);
        if(current->next==NULL) {
            printf("\n");
            break;
            }
        else {
            current=current->next;
            printf(" + ");
        }
    }
    
    Hang* head2 = makeHead(head2);
    Hang* current2 = head2;
    printf("다항식을 입력 받습니다.\n");
    printf("계수와 차수를 순서대로 입력해주세요 : \n");
    printf("그만 입력 하고 싶다면 0 0를 입력해주세요. \n");
    do{
        scanf("%d %d",&co,&je);
        if(co==0&&je==0) break;
        current2=makeHang(co,je,current2);
    }while(1);
    current2=(head2->next);
    printf("다항식 g : ");
    while(1){
        printf("%dx^%d",current2->coef,current2->jegob);
        if(current2->next==NULL) {
            printf("\n");
            break;
            }
        else {
            current2=current2->next;
            printf(" + ");
        }
    }
    current=head->next;
    current2=head2->next;
    printf("f + g : ");
    while(1){
        
        if(current->jegob>current2->jegob){
            printf("%dx^%d",current2->coef,current2->jegob);
            current2=current2->next;
        }
        else if(current->jegob<current2->jegob){
            printf("%dx^%d",current->coef,current->jegob);
            current=current->next;
        }
        else {
            printf("%dx^%d",current->coef+current2->coef,current->jegob);
            current=current->next;
            current2=current2->next;
        }
        printf(" + ");
        if(current==NULL){
            while(1) {
                printf("%dx^%d",current2->coef,current2->jegob);
                current2=current2->next;
                if(current2==NULL)break;
                printf(" + ");
            }
            break;
        }
        else if(current2==NULL){
            while(1) {
                printf("%dx^%d",current->coef,current->jegob);
                current=current->next;
                if(current==NULL)break;
                printf(" + ");
            }
            break;
        }
        
    }
    

    return 0;
}

Hang* makeHang(int coEf, int jeGob,Hang* cur){
    Hang* newHang=malloc(sizeof(Hang));
    newHang->coef=coEf;
    newHang->jegob=jeGob;
    newHang->next=NULL;
    cur->next=newHang;
    return newHang;
}
Hang* makeHead(Hang* newHead){
    newHead=malloc(sizeof(Hang));
    newHead->coef=0;
    newHead->jegob=0;
    newHead->next=NULL;
    return newHead;
}