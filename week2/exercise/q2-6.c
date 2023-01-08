#include <stdio.h>

int main(){
    for (int i=1; i<6; i++){
        for (int j=1; j<i; j++){
            printf(" ");
        }
        for (int k=1; k<6; k++){
                printf("*");
        }
        printf("\n");
    }
    for (int a=1; a<5; a++){
        for (int b=1; b<5-a; b++){
            printf(" ");
        }
        for (int c=1; c<6; c++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}