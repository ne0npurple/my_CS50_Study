#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name? ");
    string live = get_string("Where do you live? ");
    printf("Hello, %s, from %s! \n", name, live);
}