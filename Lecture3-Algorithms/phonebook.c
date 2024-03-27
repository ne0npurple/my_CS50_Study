#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Jason", "Lin", "Carter", "David"};
    string phone[] = {"+658988865", "+6282282171770", "+6253749287", "+0938462536"};

    string name = get_string("Name: ");

    for (int i=0; i < 4; i++)
    {
        if (strcasecmp(names[i], name) == 0)
        {
            printf("Found %s\n", phone[i]);
            return 0;
        }
    }
    printf("Not found.\n");
    return 1;
}