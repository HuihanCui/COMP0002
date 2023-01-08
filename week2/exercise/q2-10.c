#include <stdio.h>

int main(){
    for (int i=1; i<9; i++){
        if (i==1){
            for (int j=1; j<8; j++){
                printf("*");
            }
        }
        if (i==8){
            for (int k=1; k<8; k++){
                printf("#");
            }
        }
        if (i==2){
            printf("#");
            printf("*");
            for (int m=1; m<5; m++){
                printf(" ");
            }
            printf("*");
        }
        if (i==7){
            printf("#");
            for (int n=1; n<5; n++){
                printf(" ");
            }   
            printf("#");
            printf("*");
        }
        if (i>2 && i<7){
            printf("#");
            for (int a=1; a<i-2; a++){
                printf(" ");
            }
            printf("#");
            printf("*");
            for (int b=1; b<7-i; b++){
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    return 0;
}