#include <stdio.h>
#include <math.h>

int prime(int n){
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
    int result = prime(119);
    if (result == 1){
        printf("This is a prime number.");
    }
    else{
        printf("This is not a prime number.");
    }  
}