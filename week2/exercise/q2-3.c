#include <stdio.h>
#include <math.h>

int main()
{
    int i = 1;
    do
    {
        printf("%i * 13 = %i\n", i, i*13);
        i++;
    } while (i < 6);
    return 0;
}