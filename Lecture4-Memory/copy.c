#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char *s = get_string("s: ");
    // check if variable has no address, then just return 1
    if (s == NULL)
    {
        return 1;
    }

    // manually allocate the memory 
    char *t = malloc(strlen(s) + 1);
    // check if variable has no address, then just return 1
    if (t == NULL)
    {
        return 1;
    }

    // copy the string of s to t
    strcpy(t, s);

    // capitalized the first char
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // print the s and t
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // free the allocated memory
    free(t);
    return 0;
}