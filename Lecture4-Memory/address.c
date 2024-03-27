#include <stdio.h>

int main(void)
{
    int n = 50;
    // use %p for pointer, and add "&" to display the address of n
    int *p = &n;
    // print the address of n (value of pointer p)
    printf("%p\n", p);
    // print whatever the value which pointed by p
    printf("%i\n", *p);
}