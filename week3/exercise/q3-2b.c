#include <stdio.h>

int a, power, result;

int calculate(int result, int a, int power){
    if (power == 0){
        return result;
    }
    result = result * a;
    calculate(result, a, power-1);
}

int main(){
    printf("Enter an integer.\n");
    scanf("%d", &a);
    printf("Enter the positive integer power.\n");
    scanf("%d", &power);
    printf("The result is %d\n",calculate(a,a,power-1));
    return 0;
}