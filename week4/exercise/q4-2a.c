#include "graphics.h"
#include <math.h>
#include <stdlib.h>

double pi = 3.142;
int count = 0;

int setting(){
    setWindowSize(400,400);
    background();
    setColour(black);
    for (int i=0; i<11; i++){
        for (int j=0; j<11; j++){
            if ((i%2==0 && j%2==0) || (i%2!=0 && j%2!=0)){
                fillRect(i*40, j*40,40,40);
            }
        }
    }
}

int update(int x, int y){
    clear();
    for (int i = x-15; i<x+16; i++){
        for (int j = y-15; j<y+16; j++){
            if ((i-x)*(i-x) + (j-y)*(j-y) <=225){
                fillRect(i,j,1,1);
            }
        }
    }
}

int move(){
    foreground();
    setColour(red);
    int movex, movey;
    int x = 200;
    int y = 200;
    int angle = rand()%360 - 180;
    while(count<500){
        update(x,y);
        if (y<25){
            angle = rand()%180 - 180;
        }
        if (x<25){
            angle = rand()%180 - 90;
        }
        if (x>375){
            angle = rand()%180 + 90;
        }
        if (y>375){
            angle = rand()%180;
        }
        movex = 10 * cos(angle * pi / 180);
        movey = 10 * sin(angle * pi / 180);
        x = x + movex;
        y = y - movey;
        count++;
        sleep(10);
    }

}

int main(){
    setting();
    move();
}