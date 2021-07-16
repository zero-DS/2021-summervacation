#include <stdio.h>
#include <string.h>
//#1330 #2557 #2562 #2675 #2739
int main (void){
    /*       #1330
    int a,b;
    scanf("%d %d",&a,&b);
    if(a<b)printf("<");
    else if(a>b)printf(">");
    else printf("==");
    */
    /* #2557
    printf("Hello World!");
    */
   /*     #2562
   int ninenumbers[9]={0};
   int max=0,answerI;
   for(int i=0;i<9;i++)scanf("%d",ninenumbers+i);
   for(int i=0;i<9;i++){
       if(max<ninenumbers[i]){
           max=ninenumbers[i];
           answerI=i;
       }
    }
    printf("%d\n%d",max,answerI+1);
    */
   /* #2675
    int testcase=0;//1<=T<=1000
    int repeat=0;//1<=R<=8
    char string[21]={0};//최소 한 글자 최대 20글자
    int stringI=0;//문자열의 몇번째 글자인지
    scanf("%d",&testcase);
    for(int i=0;i<testcase;i++){
        stringI=0;
        scanf("%d %s",&repeat,string);
        for(int k=0;k<strlen(string);k++){
            for(int j=0;j<repeat;j++){
                printf("%c",string[stringI]);
            }
            stringI++;
        }
        printf("\n");
    }
    */
   //#2739
    int num=0;
    scanf("%d",&num);
    for(int i=1;i<10;i++){
        printf("%d * %d = %d\n",num,i,num*i);
    }



    return 0;
}