#include <stdio.h>
#include <math.h>

int main(){
    for (int i=1; i<101; i++){
        if (i%2 ==0){
            printf("%i\n", i*i);
        }
    }
    return 0;
}