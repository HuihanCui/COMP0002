#include <stdio.h>

int write(int n){
    if (n==1){
        for (int i=1; i<6; i++){
            printf(" ");
        }
        printf("*");
        printf(" ");
    }
    if (n==2){
        printf("*");
        for (int i=1; i<6; i++){
            printf(" ");
        }
        printf(" ");
    }
    if (n==3){
        for (int i=1; i<7; i++){
            printf("*");
        }
        printf(" ");
    }
    if (n==4){
        printf("*");
        for (int i=1; i<5; i++){
            printf(" ");
        }
        printf("*");
        printf(" ");
    }
    if (n==5){
        printf("** ");
    }
    if (n==0){
        printf("   ");
    }
}

int one[5] = {1,1,1,1,1};
int two[5] = {3,1,3,2,3};
int three[5] = {3,1,3,1,3};
int four[5] = {4,4,3,1,1};
int five[5] = {3,2,3,1,3};
int six[5] = {3,2,3,4,3};
int seven[5] = {3,1,1,1,1};
int eight[5] = {3,4,3,4,3};
int nine[5] = {3,4,3,1,3};
int zero[5] = {3,4,4,4,3};
int minus[5] = {0,0,5,0,0};

//print big digits for 0-9, the row parameter means to print which row of the big digit.(maximum row 5)
//if row==0, then print the whole digit.
int big(int n, int row){
    row--;
    if (row==-1){
        for (int i=1; i<6; i++){
            big(n,i);
        }
    }
    if (n==1){
        write(one[row]);
    }
    if (n==2){
        write(two[row]);
    }
    if (n==3){
        write(three[row]);
    }
    if (n==4){
        write(four[row]);
    }
    if (n==5){
        write(five[row]);
    }
    if (n==6){
        write(six[row]);
    }
    if (n==7){
        write(seven[row]);
    }
    if (n==8){
        write(eight[row]);
    }
    if (n==9){
        write(nine[row]);
    }
    if (n==0){
        write(zero[row]);
    }
    printf("\n");
}

int big2(int n, int row){
    row--;
    if (row==-1){
        for (int i=1; i<6; i++){
            big2(n,i);
            printf("\n");
        }
    }
    if (n==1){
        write(one[row]);
    }
    if (n==2){
        write(two[row]);
    }
    if (n==3){
        write(three[row]);
    }
    if (n==4){
        write(four[row]);
    }
    if (n==5){
        write(five[row]);
    }
    if (n==6){
        write(six[row]);
    }
    if (n==7){
        write(seven[row]);
    }
    if (n==8){
        write(eight[row]);
    }
    if (n==9){
        write(nine[row]);
    }
    if (n==0){
        write(zero[row]);
    }
}

//print negative digits for 0-9
int neg(int n, int row){
    row--;
    int pos = 0-n;
    if (row == -1){
        for (int i=1; i<6; i++){
            write(minus[i-1]);
            big(pos,i);
        }
    }
    else{
        write(minus[row]);
        big(pos,row+1);
    }
    
}

int neg2(int n, int row){
    row--;
    int pos = 0-n;
    if (row == -1){
        for (int i=1; i<6; i++){
            write(minus[i-1]);
            big2(pos,i);
        }
    }
    else{
        write(minus[row]);
        big2(pos,row+1);
    }
    
}

//print more digits, including minus.
int more(int n, int row){
    if (row!=0){
        more2(n, row);
    }
    else{
        for (int i=1; i<6; i++){
            more2(n,i);
        }
    }
}

int more2(int n, int row){
    if (n%10!=0){
        int trans = 0;
        while(n!=0){
            trans = trans*10;
            trans = trans+n%10;
            n = n/10;
        }
        if (trans>0){
            while(trans>0){
                big2(trans%10,row);
                trans = trans/10;
            }
        }
        else{
            neg2(trans%10,row);
            trans = trans/10;
            while(trans!=0){
                big2(0-trans%10,row);
                trans = trans/10;
            }
        }
        printf("\n");
    }
    else{
        int trans = 0;
        while(n!=0){
            trans = trans*10;
            trans = trans+n%10;
            n = n/10;
        }
        if (trans>0){
            while(trans>0){
                big2(trans%10,row);
                trans = trans/10;
            }
            big2(0,row);
        }
        else{
            neg2(trans%10,row);
            trans = trans/10;
            while(trans!=0){
                big2(0-trans%10,row);
                trans = trans/10;
            }
            big2(0,row);
        }
        printf("\n");
    }
}

int main(){
    more(-1897,0);
}
