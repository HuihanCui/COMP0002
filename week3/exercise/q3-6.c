#include <math.h>
#include <stdio.h>

long number;

long scan(){
    printf("Enter a number:\n");
    if (scanf("%ld", &number)!=1){
        char ch; 
        while ((ch = getchar()) != '\n' && ch != EOF);
        scan();
    }
    return number;
}

int prime(long n){
    if (n%2==0){
        return 0;
    }
    for (int i=3; i<=sqrt(n); i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    if (prime(scan())==1){
        printf("This number is a prime.");
    }
    else{
        printf("This number is not a prime.");
    }
}