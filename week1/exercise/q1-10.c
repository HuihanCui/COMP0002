#include "graphics.h"

int main(){
    drawLine(50,50,50,250);
    drawLine(50,250,300,250);
    drawLine(45,250,50,250);
    drawLine(45,200,50,200);
    drawLine(45,150,50,150);
    drawLine(45,100,50,100);
    drawString("0",23,255);
    drawString("50",23,205);
    drawString("100",23,155);
    drawString("150",23,105);
    setColour(blue);
    fillRect(50,190,50,60);
    setColour(green);
    fillRect(100,110,50,140);
    setColour(red);
    fillRect(150,130,50,120);
    setColour(yellow);
    fillRect(200,160,50,90);
    setColour(magenta);
    fillRect(250,110,50,140);
    setColour(black);
    drawString("CDs",60,270);
    drawString("DVDs",110,270);
    drawString("Books",157,270);
    drawString("Clothes",203,270);
    drawString("Shoes",260,270);
    return 0;
}