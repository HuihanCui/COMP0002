#include <math.h>
#include "graphics.h"

int setting(){
  drawLine(50,150,300,150);
  drawLine(150,100,150,200);
  drawLine(300,150,295,145);
  drawLine(300,150,295,155);
  drawLine(150,100,145,105);
  drawLine(150,100,155,105);
  drawString("0",140,165);
  return 0;
}

int calculate(double x){
  double y = sin(x / 10) * 10;
  int ycoordinate = 150 - (int)y;
  return ycoordinate;
}

int drawpositive(){
  double x = 0;
  int result = calculate(0);
  while (x < 150){
    x = x + 1;
    int y = calculate(x);
    drawLine(x + 149, result, x + 150, y);
    result = y;
  }
  return 0;
}

int drawnegative(){
  double x = 0;
  int result = calculate(0);
  while (x > -100){
    x = x - 1;
    int y = calculate(x);
    drawLine(x + 151, result, x + 150,y);
    result = y;
  }
  return 0;
}

int main(){
  setting();
  drawpositive();
  drawnegative();
  return 0;
}