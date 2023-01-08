#include "graphics.h"

int main(){
    setWindowSize(200,350);
    setRGBColour(41,36,33);
    fillRect(98,50,4,10);
    fillRect(85,60,30,10);
    setRGBColour(192,192,192);
    fillRect(78,70,44,10);
    fillRect(76,80,48,10);
    fillRect(78,90,44,10);
    fillRect(80,100,40,5);
    setRGBColour(220,220,220);
    fillRect(80,105,40,45);
    setRGBColour(46,139,87);
    fillRect(80,150,40,90);
    setRGBColour(235,235,235);
    fillRect(80,240,40,8);
    setRGBColour(0,0,0);
    drawString("BT", 85,80);
    return 0;
}