#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("X is ");
    int y = get_int("Y is ");
    if (x > y)
    {
        printf("X is not less than Y.\n");
    }
    else if (x < y)
    {
        printf("X is less than Y.\n");
    }
    else
    {
        printf("X is equal to Y.\n");
    }
}
