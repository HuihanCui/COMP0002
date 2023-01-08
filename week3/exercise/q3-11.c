#include "graphics.h"

int pattern[20] = {0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,1,1,0,1};

int setting(){
    setWindowSize(400,400);
    return 0;
}

int main(){
    int ref;
    setting();
    for (int x=0; x<20; x++){
        for (int y = 0; y<20; y++){
            ref = (x + y * 3) % 20;
            if (pattern[ref]==0){
                setColour(blue);
            }
            else{
                setColour(yellow);
            }
            fillRect(x*20, y*20, 20, 20);
        }
    }
    return 0;
}