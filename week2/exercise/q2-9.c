#include <stdio.h>

int main(){
    for (int i=1; i<6; i++){
        if (i==1){
            printf("*");
        }
        else{
            printf("*");
            for (int j=1; j<i-1; j++){
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    for (int i=1; i<5; i++){
        if (i==4){
            printf("*");
        }
        else{
            printf("*");
            for (int j=1; j<4-i; j++){
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    return 0;
}