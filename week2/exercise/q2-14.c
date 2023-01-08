#include <stdio.h>

int draw(int row, int column, char * k){
    for (int a=0; a<row; a++){
        for (int b=0; b<column; b++){
            printf(k);
        }
        printf("\n");
    }
    return 0;
}

int main(){
    draw(5,6,"8");
    return 0;
}