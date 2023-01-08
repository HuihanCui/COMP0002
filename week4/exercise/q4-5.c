#include <stdio.h>

int array[6] = {3,2,4,1,6,5};
int sortedarray[6];
int *s = sortedarray;

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int * sort(int *n){
    int *origin;
    int *min;
    origin = n;
    for (int i=0; i<6; i++){ 
        min = n + i;
        
        for (int j= i+1; j<6; j++){
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
    return s;
}

int main(){
    sort(array);
    for (int i=0; i<6; i++){
        printf("%i", sortedarray[i]);
    }
}