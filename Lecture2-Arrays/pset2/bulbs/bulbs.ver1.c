#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

char *strrev(char *str);
void print_bulb(int bit);
void get_convertedval(char ch);

int main(void)
{
    // Get string input from user
    string message = get_string("Message: ");

    // Convert each char from the string to binary
    for (int i=0, le=strlen(message); i < le; i++)
    {
        char ch = message[i];
        // get the converted value and print the bulbs
        get_convertedval(ch);
    }
}

void get_convertedval(char ch)
{  
    char converted[20] = "";
    string reversed = "";
    int chr = (int) ch;
    do 
    {
        // printf("chr is %i\n", chr);
        if (chr % 2 == 0)
        {
            strcat(converted, "0");
        }
        else
        {
            strcat(converted, "1");
        }
        chr /= 2;
    }
    while (chr > 0);
    
    // add zeros to make length == 8
    int addzeros = BITS_IN_BYTE - strlen(converted);
    for (int i=0; i < addzeros; i++)
    {
        strcat(converted, "0");
    }

    // reverse the value of the converted
    reversed = strrev(converted);

    // print each zeros and ones in the string 
    for (int j = 0; j < 8; j++)
    {
        if (reversed[j] == '0')
        {
            print_bulb(0);
        }
        else
        {
            print_bulb(1);
        }
    }
    printf("\n");
    
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

// Used an existing function called strrev() to reverse the value of a string
char *strrev(char *str)
{
    char *p1, *p2;

    if (! str || ! *str)
    {
        return str;
    }
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}