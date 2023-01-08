#include <stdio.h>

int main()
{
    for (int i=1; i<5; i++)
    {
        if (i==1 || i==4){
            for (int j = 1; j<6; j++)
            {
                printf("*");
            }
        }
        else
        {
            printf("*");
            for (int k = 1; k<4; k++)
            {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    return 0;
}