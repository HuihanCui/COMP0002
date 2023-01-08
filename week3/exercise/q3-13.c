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

int dayname(int d, int m, int y){
    if (m==1 || m==2){
        m = m+12;
        y--;
    }
    int dayname = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+1)%7;
    if (dayname==1){
        printf("This day is Monday.\n");
    }
    if (dayname==2){
        printf("This day is Tuesday.\n");
    }
    if (dayname==3){
        printf("This day is Wednesday.\n");
    }
    if (dayname==4){
        printf("This day is Thursday.\n");
    }
    if (dayname==5){
        printf("This day is Friday.\n");
    }
    if (dayname==6){
        printf("This day is Saturday.\n");
    }
    if (dayname==0){
        printf("This day is Sunday.\n");
    }
}

int main(){
    if (input()==1){
        printf("The date is valid.\n");
        if ((year%4 ==0 && year%100 !=0) || year%400==0){
            printf("This year is a leap year.\n");
        }
        else{
            printf("This year is not a leap year.\n");
        }
        dayname(day,month,year);
    }
    else{
        printf("The date is not valid.\n");
    }
    return 0;
}