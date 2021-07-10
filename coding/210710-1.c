#include <stdio.h>

/*
아래의 두 배열을 merge하여 하나의 정렬된 배열을 만드시오. A = [ 3,42,62,67,72,74,84,88,89,201,333]
B = [4,5,22,42,43,69,73,74,89,90,211,321,324]
두개의3*3 2차원배열을입력받아다음의연산을실행하시오. 1. 두행렬의합
2. 두행렬의차
3. 두행렬의곱
*/
int main(void){
    printf("arrayADT\n");
    int A[12]={3,42,62,67,72,74,84,88,89,201,333};
    int B[14]={4,5,22,42,43,69,73,74,89,90,211,321,324};
    int new[27]={0};
    int i=0,j=0,n=0;
    while(1){
        if((A[i]=='\0')||(B[j]=='\0')) break;
        else if(A[i]=='\0'){
            new[n]=B[j];
            j++;
        }
        else if (B[j]=='\0'){
            new[n]=A[i];
            i++;
        }
        else if(A[i]<B[j]) {
            new[n]=A[i];
            i++;
        }
        else if(A[i>B[j]]) {
            new[n]=B[j];
            j++;
        }
        n++;
    }
    i=0;
    while(new[i]){
        printf("%d ",new[i]);
        i++;
    }
    printf("\n");
    int m;
    int mat1[3][3]={0};
    int mat2[3][3]={0};
    printf("1번행렬 입력 : \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&m);
            mat1[i][j]=m;
        }
    }
    printf("2번행렬 입력 : \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&m);
            mat2[i][j]=m;
        }
    }
    printf("두 행렬의 합 : \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",mat1[i][j]+mat2[i][j]);
        }
        printf("\n");
    }
    printf("두 행렬의 차 : \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",mat1[i][j]-mat2[i][j]);
        }
        printf("\n");
    }
    printf("두 행렬의 곱 : \n");
    int entry=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                entry+=(mat1[i][k]*mat2[k][j]);
            }
            printf("%d ",entry);
            entry=0;
        }
        printf("\n");
    }
    

    return 0;
}