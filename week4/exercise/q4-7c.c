#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int write(char *string){
    FILE* pWriteFile = fopen( "result.txt", "a" ); 
    fputs( string, pWriteFile );
    fclose(pWriteFile);
}

char* read(int rows, int width){
    int c;
    int size = rows*width;
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

int divide(char *string,int rows, int width){
    int size = rows * width;
    char * start = string;
    char ch;
    int lastcount = 0;
    int count = 0;
    for (int i=0; i<size; i++){
        ch = *start;
        if (ch == ' '){
            lastcount = count;
            count = i;
        }
        if(lastcount <= width && count>width){
            return lastcount+1;
        }
        start++;
    }
    return 0;
}

int cut(int n, char*string, int row, int width){
    char * start = string;
    if (n==0){
        write(start);
    }
    else{
        char* new = calloc(width, sizeof(char));
        char* p = new;
        for (int i=0; i<n; i++){
            *p = *start;
            p++;
            start++;
        }
        write(new);
        char *change = "\n";
        write(change);
        cut(divide(start,row,width), start,row,width);
        free(new);
    }
}

int main(){
    char* original = read(4,30);
    cut(divide(original,4,30), original,4,30);
}