#include <stdio.h>
#include <math.h>

int factorial(int n){
    int result = 1;
    for (int i=1; i<n+1; i++){
        result = result*i;
    }
    return result;
}

int strong(int n){
    int number = n;
    int result = 0;
    int digit;
    while (n>0){
        digit = n%10; 
        result = result + factorial(digit);
        n = n/10;
    }
    if (result == number){
        return 1;
    }
    return 0;
}

int main(){
    int start, end;
    printf("Enter the start number:\n");
    scanf("%d", &start);
    printf("Enter the end number:\n");
    scanf("%d", &end);
    for (int i=start; i<end+1; i++){
        if (strong(i)==1){
            printf("%d\n", i);
        }
    }
}