#include <stdio.h>

int main(void)
{
    char s[4];
    printf("s: ");
    // string doesn't need & because it is already point to an address
    scanf("%s", s);
    printf("s is %s\n", s);
}