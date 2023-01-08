#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int write(char *string){
    FILE* pWriteFile = fopen( "result.txt", "a" ); 
    fputs( string, pWriteFile );
    fclose(pWriteFile);
}

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
    for (int i=0; i<120; i++){
        ch = *start;
        if (ch == ' '){
            lastcount = count;
            count = i;
        }
        if(lastcount <= 40 && count>40){
            return lastcount +1;
        }
        start++;
    }
    return 0;
}

int cut(int n, char*string){
    char * start = string;
    if (n==0){
        write(start);
    }
    else{
        char* new = calloc(40, sizeof(char));
        char* p = new;
        for (int i=0; i<n; i++){
            *p = *start;
            p++;
            start++;
        }
        write(new);
        char *change = "\n";
        write(change);
        cut(divide(start), start);
        free(new);
    }
}

int main(){
    char* original = read(120);
    cut(divide(original), original);
}