#include <stdio.h>
#include <math.h>

int prime(int n){
    if (n==2){
        return 1;
    }
    if (n % 2 == 0){
        return 0;
    }
    int i;
    for (i = 3; i <= sqrt(n); i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    for (int i=2; i<101; i++){
        if (prime(i)==1){
            printf("%i\n", i);
        }
    }
    return 0;
}