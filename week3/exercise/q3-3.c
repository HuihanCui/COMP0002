#include <stdio.h>
#include <math.h>

long number = 0;

int reverse(long n){
    long result = 0;
    while (n>0){
        result = result*10;
        result = result + n%10;
        n = n/10;
    }
    return result;
}

int main(){
    printf("Enter a long integer:\n");
    scanf("%ld", &number);
    long result = reverse(number);
    if (result == number){
        printf("The number is a palindrome.");
    }
    else{
        printf("The number is not a palindrome.");
    }
    return 0;
}
