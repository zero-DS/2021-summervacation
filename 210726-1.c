#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>//N개 입력할 때 문자열과 숫자를 구분하기 위한 함수 헤더파일
//#1620
char* address[100000]={0};
int tempNum[100000]={0};

void divide(char**,int*,int,int);
void mergeNsort(char**,int*,int,int,int);
void pokeBinarySearch(char**,int*,char*,int,int);
int main (void){
    int M,N;
    char** pokemon;
    char** PokemonByNumber;
    int* storeNum;

    int i,j;
    int temp;
    char searchKey[21]={0};//N개 입력받을 때 저장하는 변수
    scanf("%d %d",&M,&N);
    getchar();
    pokemon=(char**)malloc(sizeof(char*)*(M+1));
    PokemonByNumber=(char**)malloc(sizeof(char*)*(M+1));
    storeNum=(int*)malloc(sizeof(int)*M);
    for(i=0;i<M;i++){
        pokemon[i]=(char*)malloc(sizeof(char)*21);//포켓몬 이름 20자이내
        PokemonByNumber[i]=(char*)malloc(sizeof(char)*21);
    }
    
    for(i=0;i<M;i++){
        scanf("%s",pokemon[i]);
        PokemonByNumber[i]=pokemon[i];
        storeNum[i]=i+1;
        getchar();
    }

    divide(pokemon,storeNum,0,M-1);
    for(i=0;i<N;i++){
        scanf("%s",searchKey);
        getchar();
        if(isalpha(searchKey[0])){//입력한것이 포켓몬 이름인 경우
            pokeBinarySearch(pokemon,storeNum,searchKey,0,M-1);
        }
        else if(isdigit(searchKey[0])){//입력한것이 포켓몬 번호인 경우
            if(strlen(searchKey)==1)temp=(int)(searchKey[0])-48;
            else if(strlen(searchKey)==2)temp=((int)(searchKey[1])-48)+((int)(searchKey[0])-48)*10;
            else if(strlen(searchKey)==3)temp=((int)(searchKey[2])-48)+((int)(searchKey[1])-48)*10+((int)(searchKey[0])-48)*100;
            else if(strlen(searchKey)==4){
                temp=((int)(searchKey[3])-48)+((int)(searchKey[2])-48)*10+((int)(searchKey[1])-48)*100+((int)(searchKey[0])-48)*1000;
            }
            else if(strlen(searchKey)==5){
                temp=((int)(searchKey[4])-48)+((int)(searchKey[3])-48)*10+((int)(searchKey[2])-48)*100+((int)(searchKey[1])-48)*1000+((int)(searchKey[0])-48)*10000;
            }
            else temp=100000;
            printf("%s\n",PokemonByNumber[temp-1]);
        }
    }
    
    for(i=0;i<M;i++){
        free(pokemon[i]);
        //free(PokemonByNumber[i]);
    }
    free(pokemon);
    free(PokemonByNumber);
    free(storeNum);
    

    return 0;
}

void divide(char** arr, int* numarr,int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        divide(arr,numarr,left,mid);
        divide(arr,numarr,mid+1,right);
        mergeNsort(arr,numarr,left,mid,right);
    }
}
void mergeNsort(char** arr, int* numarr,int left, int mid, int right){
    int i=left,j=mid+1;
    int s=left;
    int k;
    while(1){
        if(i>mid || j>right)break;
        if(strcmp(arr[i],arr[j])<0){
            address[s]=arr[i];
            tempNum[s]=numarr[i];
            s++;
            i++;
        }
        else{
            address[s]=arr[j];
            tempNum[s]=numarr[j];
            s++;
            j++;
        }
    }
    if(i>mid){
        for(k=j;k<right+1;k++){
            address[s]=arr[k];
            tempNum[s]=numarr[k];
            s++;
        }
    }
    else if(j>right){
        for(k=i;k<mid+1;k++){
            address[s]=arr[k];
            tempNum[s]=numarr[k];
            s++;
        }
    }
    for(k=left;k<right+1;k++){
        arr[k]=address[k];
        numarr[k]=tempNum[k];
    }
}
void pokeBinarySearch(char** arr, int* numarr,char* key, int left, int right){
    if(left<=right){
        int mid=(left+right)/2;
        if(strcmp(arr[mid],key)<0)pokeBinarySearch(arr,numarr,key,mid+1,right);
        else if(strcmp(arr[mid],key)>0)pokeBinarySearch(arr,numarr,key,left,mid-1);
        else printf("%d\n",numarr[mid]);
    }
}