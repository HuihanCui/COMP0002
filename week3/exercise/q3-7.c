#include <math.h>
#include <stdio.h>

int prime(int n){
    if (n==1){
        return 0;
    }
    if (n==2){
        return 1;
    }
    if (n%2==0){
        return 0;
    }
    for (int i=3; i<=sqrt(n); i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}

int twin(int start, int end){
    int last = -2;
    for (int i = start; i<end+1; i++){
        if (prime(i)==1){
            int diff = i - last;
            if (diff<=2){
                printf("%i and %i\n", last, i);
            }
            last = i;
        }
    }
}

int main(){
    int start, end;
    printf("Enter the start number:\n");
    scanf("%d", &start);
    printf("Enter the end number:\n");
    scanf("%d", &end);
    twin(start, end);
    return 0;
}