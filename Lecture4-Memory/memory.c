#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // use function sizeof to get the size of int, which is 4.
    int *x = malloc(3 * sizeof(int));
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;
    // free the memory after use
    free(x);
}