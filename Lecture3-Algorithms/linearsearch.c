#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // array of integers with the size of 7
    int dollars[] = {20, 100, 10, 5, 50, 500, 1}; 

    int num = get_int("Search: ");

    for (int i=0; i < 7; i++)
    {
        if (dollars[i] == num)
        {
            printf("Found.\n");
            return 0;
        }
    }
    printf("Not found.\n");
    return 1;
}