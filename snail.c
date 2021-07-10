#include <stdio.h>
#include <stdlib.h>

#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UP 4
#define ARRAY_SIZE 5

int main (void){
   int i=0,j=0; 
   int dir=RIGHT; 
   int arraynum=1;
   int array [ARRAY_SIZE][ARRAY_SIZE]={0};
   while(1){
       array[i][j]=arraynum;
       printf("%d\n",array[i][j]);
       switch(dir){
            case RIGHT:
                if(j==ARRAY_SIZE-1||array[i][j+1]){
                    i++;
                    dir=DOWN;
                    printf("아래로\n");
                }else j++;
                break;
            case DOWN:
                if(i==ARRAY_SIZE-1||array[i+1][j]){
                    j--;
                    dir=LEFT;
                    printf("왼쪽으로\n");
                }else i++;
                break;
            case LEFT:
                if(j==0||array[i][j-1]){
                    i--;
                    dir=UP;
                    printf("위로\n");
                }else j--;
                break;
            case UP:
                if(i==0||array[i-1][j]){
                    j++;
                    dir=RIGHT;
                    printf("오른쪽으로\n");
                }else i--;
                break;
            default:
                printf("오류 발생\n");
                exit(0);
       }//switch
       arraynum++;
       if(arraynum>ARRAY_SIZE*ARRAY_SIZE) break;
   }
   for(i=0;i<ARRAY_SIZE;i++){
       for(j=0;j<ARRAY_SIZE;j++) printf("%2d",array[i][j]);
       printf("\n");
   }


    return 0;
}