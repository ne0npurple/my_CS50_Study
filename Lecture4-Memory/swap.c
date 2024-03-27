#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);

    // use & to denote that we want to go to the address of x and y
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

// use * to take the value in that pointer
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}