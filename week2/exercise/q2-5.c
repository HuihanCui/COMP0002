#include <stdio.h>

int main()
{
    for (int i=1; i<7; i++){
        for (int j=1; j<i; j++)
        {
            printf(" ");
        }
        int k = 0;
        while (k<7-i)
        {
            printf("*");
            k++;
        }
        printf("\n");
    }
    return 0;
}