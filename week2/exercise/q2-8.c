#include <stdio.h>

int main(){
    for (int i=1; i<7; i++){
        if (i % 2 !=0){
            for (int j=1; j<4; j++){
                printf("*");
                printf("#");
            }
        }
        else{
            for (int k=1; k<4; k++){
                printf("#");
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}