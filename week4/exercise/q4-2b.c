#include "graphics.h"
#include <math.h>
#include <stdlib.h>

double pi = 3.142;

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

int update(int x, int y, int r){
    clear();
    for (int i = x-r; i<x+r+1; i++){
        for (int j = y-r; j<y+r+1; j++){
            if ((i-x)*(i-x) + (j-y)*(j-y) <=r*r){
                fillRect(i,j,1,1);
            }
        }
    }
}

colour colours[] = {red, green, yellow, pink, blue};

int move(int x1, int y1, int r1, int c1,int x2, int y2, int r2, int c2,int x3, int y3, int r3, int c3){
    int count = 0;
    foreground();

    int movex1, movey1, movex2, movey2, movex3, movey3;
    int angle1 = rand()%360 - 180;
    int angle2 = rand()%360 - 180;
    int angle3 = rand()%360 - 180;
    int mover1 = r1 / 3;
    int mover2 = r2 / 3;
    int mover3 = r3 / 3;

    while(count<100){
        setColour(colours[c1%5]);
        update(x1,y1,r1);
        setColour(colours[c2%5]);
        update(x2,y2,r2);
        setColour(colours[c3%5]);
        update(x3,y3,r3);

        if (y1<r1+mover1){
            angle1 = rand()%180 - 180;
        }
        if (x1<r1+mover1){
            angle1 = rand()%180 - 90;
        }
        if (x1>400 - r1 - mover1){
            angle1 = rand()%180 + 90;
        }
        if (y1>400 - r1 - mover1){
            angle1 = rand()%180;
        }
        movex1 = mover1 * cos(angle1 * pi / 180);
        movey1 = mover1 * sin(angle1 * pi / 180);
        x1 = x1 + movex1;
        y1 = y1 - movey1;

        if (y2<r2+mover2){
            angle2 = rand()%180 - 180;
        }
        if (x2<r2+mover2){
            angle2 = rand()%180 - 90;
        }
        if (x2>400 - r2 - mover2){
            angle2 = rand()%180 + 90;
        }
        if (y2>400 - r2 - mover2){
            angle2 = rand()%180;
        }
        movex2 = mover2 * cos(angle2 * pi / 180);
        movey2 = mover2 * sin(angle2 * pi / 180);
        x2 = x2 + movex2;
        y2 = y2 - movey2;

        if (y3<r3+mover3){
            angle3 = rand()%180 - 180;
        }
        if (x3<r3+mover3){
            angle3 = rand()%180 - 90;
        }
        if (x3>400 - r3 - mover3){
            angle3 = rand()%180 + 90;
        }
        if (y3>400 - r3 - mover3){
            angle3 = rand()%180;
        }
        movex3 = mover3 * cos(angle3 * pi / 180);
        movey3 = mover3 * sin(angle3 * pi / 180);
        x3 = x3 + movex3;
        y3 = y3 - movey3;

        count++;
        sleep(150);
    }

}

int main(){
    setting();
    move(200,200,15,0,100,300,20,4,300,100,10,2);
}

