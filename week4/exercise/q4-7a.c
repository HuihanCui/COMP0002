#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read(int size){
    int c;
    char* original = calloc(size, sizeof(char));
    char *p = original;
    FILE *file;
    file = fopen("test.txt", "r");
    if (file) {
        while ((c = getc(file)) != EOF){
            *p = c;
            p++;
        }
    fclose(file);
    }
    return original;
    free(original);
}

int divide(char *string){
    char * start = string;
    char ch;
    int lastcount = 0;
    int count = 0;
    for (int i=0; i<160; i++){
        ch = *start;
        if (ch == ' '){
            lastcount = count;
            count = i;
        }
        if(lastcount <= 40 && count>40){
            return lastcount+1;
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
            start++;
            printf("%c", ch);
        }
        printf("\n");
        cut(divide(start), start);
    }
}

int main(){
    char* original = read(160);
    cut(divide(original), original);
}