#include <stdio.h>
#include <math.h>

int main()
{
    int n = 1;
    while (n < 6)
    {
        printf("%i * 13 = %i\n", n, n * 13);
        n++;
    }
    return 0;
}