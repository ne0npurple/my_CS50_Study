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
        char c = message[i];
        for (int index = BITS_IN_BYTE-1; index >= 0; index--)
        {
            char mask = (1 << index);
            bool isOne = (int)(c & mask) != 0;
            print_bulb((int)isOne);
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