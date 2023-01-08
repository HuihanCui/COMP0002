#include <stdio.h>
#include <stdlib.h>

int size = 6;
int array[6] = {6,3,2,4,1,5};



int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int * sort(int *n, int size){
    int *newarray = calloc(size, sizeof(int));
    int *s = newarray;
    
    int *origin;
    int *min;
    origin = n;
    for (int i=0; i<size; i++){ 
        min = n + i;
        
        for (int j= i+1; j<size; j++){
            n = origin + j;
            if (*n < *min){
                min = n;
            }
        }
        *s = *min;
        s++;
        n = origin + i;
        swap(min,n);
        n = origin;
    }
    return newarray;
    free(newarray);
}

int main(){
    int *p = sort(array,size);
    for (int i=0; i<size; i++){
        printf("%i", *p);
        p++;
    }
}