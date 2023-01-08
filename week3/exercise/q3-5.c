#include <stdio.h>

int number;

int standard(int n){
    if (n==0){
        printf("zero ");
    }
    if (n==1){
        printf("one ");
    }
    if (n==2){
        printf("two ");
    }
    if (n==3){
        printf("three ");
    }
    if (n==4){
        printf("four ");
    }
    if (n==5){
        printf("five ");
    }
    if (n==6){
        printf("six ");
    }
    if (n==7){
        printf("seven ");
    }
    if (n==8){
        printf("eight ");
    }
    if (n==9){
        printf("nine ");
    }
    if (n==10){
        printf("ten ");
    }
    if (n==11){
        printf("eleven ");
    }
    if (n==12){
        printf("twelve ");
    }
    if (n==13){
        printf("thirteen ");
    }
    if (n==14){
        printf("fourteen ");
    }
    if (n==15){
        printf("fifteen ");
    }
    if (n==16){
        printf("sixteen ");
    }
    if (n==17){
        printf("seventeen ");
    }
    if (n==18){
        printf("eighteen ");
    }
    if (n==19){
        printf("nineteen ");
    }
    if (n==20){
        printf("twenty ");
    }
    if (n==30){
        printf("thirty ");
    }
    if (n==40){
        printf("fourty ");
    }
    if (n==50){
        printf("fifty ");
    }
    if (n==60){
        printf("sixty ");
    }
    if (n==70){
        printf("seventy ");
    }
    if (n==80){
        printf("eighty ");
    }
    if (n==90){
        printf("ninety ");
    }
    if (n==100){
        printf("hundred ");
    }
}

int read(int n){
    int i;
    if (n<20){
        standard(n);
    }
    if (n<100 && n>19){
        i = n%10;
        standard(n-i);
        if (i!=0){
            standard(i);
        }
    }
    if (n>=100){
        i = n%100;
        n = (n-i)/100;
        standard(n);
        standard(100);
        if (i!=0){
            printf("and ");
            read(i);
        }
    }
}

int main(){
    printf("Enter a number between 0 and 999:\n");
    scanf("%d", &number);
    read(number);
    return 0; 
}