#include <stdio.h>

int strend(char *s, char *t){
    while (*s && *t){
        if (*s != *t){
            s++;
        }
        else{
            s++;
            t++;
        }
    }
    if (!(*t) && !(*s)){
        return 1;
    }
    return 0;
    
}

int main(){
    char *big = "Iloveyou";
    char *small = "eyou";
    printf("%i", strend(big,small));
}