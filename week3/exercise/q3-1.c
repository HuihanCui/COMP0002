#include <stdio.h>
#include <math.h>

double a, b, c;

double judge(){
    printf("Enter the lengths of sides of a triangle.\n");
    printf("Enter values for a, b, c:");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (!(a+b>c) && (a+c>b) && (b+c>a)){
        printf("They can't form a triangle, please input the values again.\n");
        judge();
    }
}

double parameter(double a, double b, double c){
    return a+b+c;
}

double area(double a, double b, double c){
    double s = parameter(a,b,c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main(){
    judge();
    printf("the parameter is %lf\n", parameter(a,b,c));
    printf("the area is %lf\n", area(a,b,c));
    return 0;
}