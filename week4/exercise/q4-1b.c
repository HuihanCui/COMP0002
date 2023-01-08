#include "graphics.h"
#include <math.h>

int movedistance = 20;
int count = 0;
int xcenter = 200;
int ycenter = 200;
int radius = 100;
double pi = 3.142;

int setting(){
    background();
    setColour(green);
    int distance;
    for (int i=0; i<401; i++){
        for (int j=0; j<401; j++){
            distance = (i-200)*(i-200) + (j-200)*(j-200);
            if (distance>10000 && distance<14400){
                drawRect(i,j,1,1);
            }
        }
    }
}

int update(int x, int y){
    clear();
    fillRect(x,y,40,40);
}

int move(){
    sleep(1000);
    foreground();
    setColour(blue);
    int angle = 0;
    int actualangle = 0;
    int x,y;
    while(count<50){
        x = radius * cos(actualangle * pi / 180) + xcenter;
        y = ycenter - radius * sin(actualangle * pi / 180); 
        update(x-10,y-20);
        angle = angle + 30;
        actualangle = angle % 360;
        sleep(500);
        count++;
    }
}

int main(){
    setWindowSize(400,400);
    setting();
    move();
    return 0; 
}