#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* getinput(int size){
    printf("Enter the text.\n");
    char* original = calloc(size, sizeof(char));
    fgets(original, size, stdin);
    return original;
    free(original);
}

int divide(char *string){
    char * start = string;
    char ch;
    int lastcount = 0;
    int count = 0;
    for (int i=0; i<120; i++){
        ch = *start;
        if (ch == ' '){
            lastcount = count;
            count = i;
        }
        if(lastcount <= 40 && count>40){
            return lastcount;
        }
        start++;
    }
    return 0;
}

int cut(int n, char*string){
    char * start = string;
    if (n==0){
        printf("%s", start);
    }
    else{
        char ch;
        for (int i=0; i<n; i++){
            ch = *start;
            printf("%c", ch);
            start++;
        }
        printf("\n");
        cut(divide(start), start);
    }
}

int main(){
    char* original = getinput(120);
    cut(divide(original), original);
}