#include <stdio.h>

int start, end;

int calculate(int start, int end){
    int result = start;
    for (int i=start+1; i<end+1; i++){
        result = result * i;
    }
    return result;
}

int main(){
    printf("Enter the start value:\n");
    scanf("%d", &start);
    printf("Enter the end value:\n");
    scanf("%d", &end);
    printf("The result is %i\n", calculate(start,end));
    return 0;
}