#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * stringCopy(char * s){
    int length = strlen(s);
    char *copy =calloc(length+1,sizeof(char));
    char* p = copy;
    while (*s){
        *p = *s;
        p++;
        s++;
    }
    *p = '\0';
    return copy;
    free(copy);
}

int main(){
    char *string = "Idon'tloveyou\0";
    printf("%s", stringCopy(string));
    return 0;
}