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
    printf("%i\n", array[n][0]);
    for(int i=0; i<n; i++){
        printf("%i ", array[n+1][i]);
    }
    printf("\n");
}

int setvalues(int **array, int value, int row, int column){
    array[row][column] = value;
}

int getvalues(int **array, int row, int column){
    printf("%i", array[row][column]);
}

int ** ragged(int n, int *length){
    int ** twod = calloc(n+2, sizeof(int *));
    int **p = twod;
    for (int i=0; i<n; i++){
        *p = calloc(*length, sizeof(int));
        length++;
        p++;
    }
    *p = &n;
    p++;
    length -= n;
    *p = length;

    
    setvalues(twod, 2, 4, 2);
    setvalues(twod, 3,2,0);
    v2d(twod, n, length);
    getvalues(twod, 4,2);

    p = p - (n+1);
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