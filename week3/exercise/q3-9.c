#include <stdio.h>

int hour, minute;

int time(int h, int m){
    int mode = 0;
    if (h>12){
        mode = 1;
        h = h-12;
    }
    printf("%d.",h);
    if (m<10){
        printf("%i",0);
    }
    printf("%d",m);
    if (mode == 1){
        printf("pm");
    }
    else{
        printf("am");
    }
}

int main(){
    printf("Enter a time with the frame xx:xx in 24 hour format:\n");
    scanf("%d:%d", &hour, &minute);
    time(hour, minute);
    return 0;
}