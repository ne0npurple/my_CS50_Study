#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get name by user input
    string name = get_string("What is your name? ");
    printf("Hello, %s\n", name);
}