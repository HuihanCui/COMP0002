#include <math.h>
#include <stdio.h>
#include <string.h>

long number;

long scan(){
    printf("Enter a number:\n");
    if (scanf("%ld", &number)!=1){
        char ch; 
        while ((ch = getchar()) != '\n' && ch != EOF);
        scan();
    }
    return number;
}

int prime(long n){
    if (n%2==0){
        return 0;
    }
    for (int i=3; i<=sqrt(n); i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int test(){
    char str[4];
    printf("If you want to stop, enter stop. If you don't, enter no.\n");
	scanf("%s", &str);
    if (str[0] == 's' && str[1] == 't' && str[2] == 'o' && str[3] == 'p'){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    while (test()!=0){
        if (prime(scan())==1){
            printf("This number is a prime.\n");
        }
        else{
            printf("This number is not a prime.\n");
        }
    }
}
