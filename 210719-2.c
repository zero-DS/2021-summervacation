#include <stdio.h>
#include <stdlib.h>
//#4153
int main(void){
    int a,b,c;
    while(1){
    scanf("%d %d %d",&a,&b,&c);
    if(a==0 && b==0 && c==0)break;
    if((a*a+b*b)==c*c)printf("right\n");
    else if(a*a==(b*b+c*c))printf("right\n");
    else if(b*b==(a*a+c*c))printf("right\n");
    else printf("wrong\n");
    }



    return 0;
}