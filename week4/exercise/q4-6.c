#include <stdio.h>
#include <stdlib.h>

int lengths[5] = {3,4,1,2,5};
int *length = lengths;

int v2d(int **array, int n, int *length){
    for (int i=0; i<n; i++){
        for (int j=0; j<*length; j++){
            printf("%i ", array[i][j]);
        }
        printf("\n");
        length++;
    }
}

int ** ragged(int n, int *length){
    int ** twod = calloc(n, sizeof(int *));
    int **p = twod;
    for (int i=0; i<n; i++){
        *p = calloc(*length, sizeof(int));
        length++;
        p++;
    }
    length -= n;
    v2d(twod, n, length);

    p -= n;
    for (int i=0; i<n; i++){
        free(*p);
        p++;
    }
    free(twod);

    return twod;
}



int main(){
    ragged(5,length);
}
