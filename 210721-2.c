#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#1181
char sorted[20001][51]={0};
char* address[20001]={0};
void divide(char**,int,int);
void mergeNsort(char**,int,int,int);
int main(void){
    int i,j;
    int N;
    scanf("%d",&N);
    char** Narr=(char**)malloc(sizeof(char*)*(N+1));
    for(i=0;i<N;i++){
        Narr[i]=(char*)malloc(sizeof(char)*51);
    }
    for(i=0;i<N;i++){
        scanf("%s",Narr[i]);
        getchar();
    }
    divide(Narr,0,N-1);
    for(i=0;i<N;i++){
        if(i>0 && !strcmp(Narr[i],Narr[i-1]))continue;
        printf("%s\n",Narr[i]);
    }

    for(i=0;i<N;i++)free(Narr[i]);
    free(Narr);

    return 0;
}
void divide(char** arr,int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        divide(arr,left,mid);
        divide(arr,mid+1,right);
        mergeNsort(arr,left,mid,right);
    }
}
void mergeNsort(char** arr, int left, int mid, int right){
    int i=left,j=mid+1;
    int s=left;
    int k;
    int c;
    while(1){
        if(i>mid || j>right)break;
        if(strlen(arr[i])<strlen(arr[j])){
            //strcpy(sorted[s],arr[i]);
            address[s]=arr[i];
            s++;
            i++;
        }
        else if (strlen(arr[i])>strlen(arr[j])){
            //strcpy(sorted[s],arr[j]);
            address[s]=arr[j];
            s++;
            j++;
        }
        else {//두단어의 길이가 같을 때
            if(strcmp(arr[i],arr[j])<0){
                //strcpy(sorted[s],arr[i]);
                address[s]=arr[i];
                s++;
                i++;
            }
            else{
                //strcpy(sorted[s],arr[j]);
                address[s]=arr[j];
                s++;
                j++;
            }   
        }    
    }
    //이제 남은 단어들 처리
    if(i>mid){
        for(k=j;k<right+1;k++){
            //strcpy(sorted[s],arr[k]);
            address[s]=arr[k];
            s++;
        }
    }
    else if(j>right){
       for(k=i;k<mid+1;k++){
           //strcpy(sorted[s],arr[k]);
           address[s]=arr[k];
           s++;
       }
    }
    for(k=left;k<right+1;k++){
       arr[k]=address[k];
    }
}