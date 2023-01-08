#include "graphics.h"

int movedistance = 20;
int count = 0;

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
    int x = 80;
    int y = 100;
    while(count<80){
        update(x,y);
        if(y==100 && x<261){
            x = x + movedistance;
        }
        else{
            if (x==280 && y<241){
                y = y + movedistance;
            }
            else{
                if (y==260 && x>99){
                    x =x - movedistance;
                }
                else{
                    if (x==80 && y>119){
                        y = y - movedistance;
                    }
                }
            }
        }
        sleep(250);
        count++;
    }
}

int main(){
    setWindowSize(400,400);
    setting();
    move();
    return 0; 
}