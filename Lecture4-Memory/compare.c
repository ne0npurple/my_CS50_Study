#include <cs50.h>
#include <stdio.h>
#include <strings.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    if (strcasecmp(s, t) == 0)
    {
        printf("Same.\n");
    }
    else
    {
        printf("Different.\n");
    }
    
    // print the address of variable s and t
    printf("s is in %p, t is in %p\n", s, t);
}