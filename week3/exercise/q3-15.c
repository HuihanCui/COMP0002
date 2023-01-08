#include <stdio.h>

int move(int t1, int t2, int n){
    printf("Move plate %i from tower %i to %i\n", n, t1, t2);
}

//move from 1 to 3, using 2
int hanoi(int t1, int t3, int t2, int n){
    if (n==1){
        move(t1, t3, n);
    }
    else{
        hanoi(t1, t2, t3, n-1);
        move(t1, t3, n);
        hanoi(t2, t3, t1, n-1);
    }
    return 0;
}

int main(){
    hanoi(1,3,2,4);
    return 0;
}

