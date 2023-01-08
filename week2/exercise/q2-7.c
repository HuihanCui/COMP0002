#include <stdio.h>

int main(){
    for (int i=1; i<8; i++){
        if (i==1 || i==7){
            for (int j=1; j<9; j++){
                printf("*");
            }
        }
        if (i==2 || i==6){
            printf("*");
            for (int k=1; k<7; k++){
                printf(" ");
            }
            printf("*");
        }
        if (i==3 || i==5){
            printf("*");
            printf(" ");
            for (int a=1; a<5; a++){
                printf("#");
            }
            printf(" ");
            printf("*");
        }
        if (i==4){
            printf("*");
            printf(" ");
            printf("#");
            printf(" ");
            printf(" ");
            printf("#");
            printf(" ");
            printf("*");
        }
        printf("\n");
    }
    return 0;
}