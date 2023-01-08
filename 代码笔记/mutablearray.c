#include <stdio.h>
#include <stdlib.h>


int main(){
    int *myarray = (int *)calloc(2,sizeof(int));
    int *new = (int *)realloc(myarray, 4*sizeof(int));
    int *p = new;
    *p = 10;
    *(p+3)= 20;
    printf("%d", new[3]);
    free(new);
    return 0;
}