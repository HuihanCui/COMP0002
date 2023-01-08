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
    char * start = string;
    int length = strlen(string);
    if (length<width){  
        return 0;
    }
    char ch;
    start = start + width-1;
    ch = *start;
    if (ch == ' '){
        return 1;
    }
    else{
        start++;
        ch = *start;
        if (ch == ' '){
            return 3;
        }
        return 2;
    }
    
}

int cut(int n, char*string, int row, int width){
    char * start = string;
    if (n==0){
        write(start);
    }
    else{
        char* new = calloc(width+1, sizeof(char));
        char* p = new;
        for (int i=0; i<width; i++){
            *p = *start;
            p++;
            start++;
        }
        if (n==3){
            *p = *start;
            start++;
        }
        write(new);
        if (n==2){
            char *connect = "-";
            write(connect);
        }
        char *change = "\n";
        write(change);
        cut(divide(start,row,width), start,row,width);
        
        free(new);
    }
}

int main(){
    char* original = read(6,20);
    cut(divide(original,6,20), original,6,20);
}