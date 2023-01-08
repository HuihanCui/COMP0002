#include <stdio.h>

int day, month, year;

int input(){
    int leap = 0;
    printf("Enter a date in the format dd-mm-yyyy:\n");
    scanf("%d-%d-%d", &day, &month, &year);
    if ((year%4 ==0 && year%100 !=0) || year%400==0 ){
        leap = 1;
    }
    if (year >0 && month>0 && month<13 && day>0){
        if (month ==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
            if (day<32){
                return 1;
            }
            else{
                return 0;
            }
        }
        if (month==4 || month==6 || month==9 || month==11){
            if (day<31){
                return 1;
            }
            else{
                return 0;
            }
        }
        if (month==2){
            if (leap==1 && day<30){
                return 1;
            }
            if (leap==0 && day<29){
                return 1;
            }
            return 0;
        }
    }
    else{
        return 0;
    }
}

int daynormal[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dayabnormal[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dayn(int d, int m, int y){
    int day=0;
    for (int i=1; i<y+1; i++){
        if ((i%4 ==0 && i%100 !=0) || i%400==0){
            
            day = day + 366;
        }
        else{
            day = day + 365;
        }
    }
    for (int j=1; j<m; j++){
        if ((y%4 ==0 && y%100 !=0) || y%400==0){
            day = day + dayabnormal[j];
        }
        else{
            day = day + daynormal[j];
        }
    }
    return day+d;
}

int main(){
    int date = input();
    if (date==1){
        int day1 = dayn(day, month, year);
        int date2 = input();
        if (date2==1){
            printf("Both dates are valid.\n");
            int day2 = dayn(day, month, year);
            int diff = day2 - day1;
            if (diff<0){
                diff = 0 - diff;
            }
            diff--;
            printf("The number of days between the two dates is %i\n", diff);
        }
        else{
            printf("This date is not valid.\n");
        }
    }
    else{
        printf("This date is not valid.\n");
    }
}