#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // Get string input from user
    string message = get_string("Message: ");

    // Convert each char from the string to binary
    for (int i = 0, le = strlen(message); i < le; i++)
    {
        int bulbs[BITS_IN_BYTE] = {0};
        int index = 0;
        for (char c = message[i]; c != 0; c /= 2)
        {
            bulbs[index] = (int)(c % 2);
            index++;
        }
        for (int index = BITS_IN_BYTE - 1; index >= 0; index--)
        {
            print_bulb(bulbs[index]);
        }
        printf("\n");
    }
    return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}