#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char* str = "12";
    int num;
    sscanf(str, "%d", &num);

    printf("the num is: %d\n", num);
}