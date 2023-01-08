#include "graphics.h"
#include <math.h>
#include <stdio.h>

int drawsnow(int n, int x1, int y1, int x2, int y2){
    if (n == 0){
        drawLine(x1, y1, x2, y2);
    }
    else{
        int xd = x2 - x1;
        int yd = y2 - y1;
        int x3 = x1 + xd / 3;
        int y3 = y1 + yd / 3;
        int x4 = x1 + xd * 2 / 3;
        int y4 = y1 + yd * 2 / 3;
        int x5 = (x1 + x2) / 2 + yd * sqrt(3) / 6;
        int y5 = (y1 + y2) / 2 - xd * sqrt(3) / 6;
        drawsnow(n-1, x1, y1, x3, y3);
        drawsnow(n-1, x3, y3, x5, y5);
        drawsnow(n-1, x5, y5, x4, y4);
        drawsnow(n-1, x4, y4, x2, y2);
    }
    return 0;
}

int main(){
    setWindowSize(700,800);
    drawsnow(5,343,129,586,550);
    drawsnow(5,586,550,100,550);
    drawsnow(5,100,550,343,129);
    return 0;
}