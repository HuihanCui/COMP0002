#include <math.h>
#include "graphics.h"

int setting(){
  drawLine(25,150,300,150);
  drawLine(150,50,150,250);
  drawLine(300,150,295,145);
  drawLine(300,150,295,155);
  drawLine(150,50,145,55);
  drawLine(150,50,155,55);
  drawString("0",140,165);
  drawLine(145,130,150,130);
  drawLine(145,110,150,110);
  drawString("0.5",125,135);
  drawString("1.0",125,115);
  drawLine(145,70,150,70);
  drawLine(145,90,150,90);
  drawString("2.0",125,75);
  drawString("1.5",125,95);
  drawLine(145,210,150,210);
  drawLine(145,230,150,230);
  drawString("-2.0",120,235);
  drawString("-1.5",120,215);
  drawLine(145,170,150,170);
  drawLine(145,190,150,190);
  drawString("-0.5",120,175);
  drawString("-1.0",120,195);
  drawString("(rad)",310,155);
  drawLine(190,150,190,155);
  drawLine(230,150,230,155);
  drawLine(270,150,270,155);
  drawString("2",187,170);
  drawString("4",227,170);
  drawString("6",267,170);
  drawLine(110,150,110,155);
  drawLine(70,150,70,155);
  drawLine(30,150,30,155);
  drawString("-2",105,170);
  drawString("-4",65,170);
  drawString("-6",25,170);
  setColour(red);
  drawString("(sin)",310,115);
  setColour(blue);
  drawString("(cos)",310,140);
  setColour(green);
  drawString("(tan)",310,35);
  return 0;
}

int calculate(double x, int i){
  double y;
  if (i==1){
    y = sin(x / 20) * 40;
  }
  if (i==2){
    y = cos(x / 20) * 40;
  }
  if (i==3){
    y = tan(x / 20) * 40;
  }
  int ycoordinate = 150 - (int)y;
  return ycoordinate;
}

int drawpositive(int i){
  double x = 0;
  int result;
  int y;
  if (i==1){
    result = calculate(0,1);
  }
  if (i==2){
    result = calculate(0,2);
  }
  while (x < 150){
    x = x + 1;
    if (i==1){
      y = calculate(x,1);
    }
    if (i==2){
      y = calculate(x,2);
    }
    drawLine(x + 149, result, x + 150, y);
    result = y;
  }
  return 0;
}

int drawpostan1(){
  double x = 0;
  while (x<150){
    int y = calculate(x,3);
    drawRect(x + 150, y,1,1);
    x = x + 1;
  }
  return 0;
}

int drawnegative(int i){
  double x = 0;
  int result, y;
  if (i==1){
    result = calculate(0,1);
  }
  if (i==2){
    result = calculate(0,2);
  }
  while (x > -120){
    x = x - 1;
    if (i==1){
      y = calculate(x,1);
    }
    if (i==2){
      y = calculate(x,2);
    }
    drawLine(x + 151, result, x + 150,y);
    result = y;
  }
  return 0;
}

int drawnegtan1(){
  double x = 0;
  while (x>-120){
    int y = calculate(x,3);
    drawRect(x + 150, y,1,1);
    x = x - 1;
  }
  return 0;
}

int drawSin(){
  setColour(red);
  drawpositive(1);
  drawnegative(1);
  return 0;
}

int drawCos(){
  setColour(blue);
  drawpositive(2);
  drawnegative(2);
  return 0;
}


int drawTan(){
  setColour(green);
  drawpostan1();
  drawnegtan1();
  return 0;
}

int main(){
  setting();
  drawSin();
  drawCos();
  drawTan();
  return 0;
}