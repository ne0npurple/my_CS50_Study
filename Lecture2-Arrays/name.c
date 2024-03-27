#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name? ");
    int n = strlen(name);

    printf("Length is %i\n", n);
}