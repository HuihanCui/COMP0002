#include "graphics.h"
#include <stdio.h>
#include <complex.h>


int width = 800;
int height = 600;
float orig_x = 800 * 2/3;
float orig_y = 600 * 1/2;

colour colours [] = {gray, black,white, blue, green, red, yellow, pink};

int calculation(int x, int y){
    int i;
    complex c = ((x - orig_x) / (width / 3)) + ((orig_y - y) / (height / 2)) * I;
    complex z = 0;
    for (i = 0; i < 256; i++){
        z = z * z + c;    
    }
    if (crealf(z) > 2 || cimagf(z) > 2){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    setWindowSize(width, height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            
            setColour(colours[calculation(i,j)]);
            drawLine(i,j,i+1,j+1);
            
        }
    }
    return 0;
}