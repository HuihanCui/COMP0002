#include <stdio.h>
#include <math.h>
#include "graphics.h"

double pi = 3.142;

int spiral(){
    double r = 1;
    for (int i=1; i<3610; i++){
        int x = r * cos((i%360)*pi/180) + 500;
        int y = 400 - r * sin((i%360)*pi/180);
        drawRect(x,y,1,1);
        r = r + 0.1;
    }
}

int main(){
    setWindowSize(1000,1000);
    spiral();  
    return 0;  
}