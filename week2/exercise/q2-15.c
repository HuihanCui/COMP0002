#include "graphics.h"

int tri(int x, int y,int width, int height){
    drawLine(x,y,x+width,y);
    drawLine(x,y,x+width/2, y-height);
    drawLine(x+width,y,x+width/2, y-height);
}

int main(){
    drawRect(100,50,40,80);
    tri(300,200,60,140);
    return 0;
}