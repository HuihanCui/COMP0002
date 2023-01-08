#include <stdio.h>

int a, power;

int main(){
    printf("Enter an integer.\n");
    scanf("%d", &a);
    printf("Enter the positive integer power.\n");
    scanf("%d", &power);
    int result = a;
    for (int i=0; i<power-1; i++){
        result = result * a;
    }
    printf("The result is %d\n", result);
    return 0;
}