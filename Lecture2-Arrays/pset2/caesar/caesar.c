#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int key = 0;
char ciphertext;

bool onlydigits(string str);
char rotate(int key, char c);

int main(int argc, string argv[])
{
    // check to see if the amount of argument only 2, check if input a positive int
    if (argc == 2 && onlydigits(argv[1]) == true)
    {
        // convert the string to an integer
        key = atoi(argv[1]);
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    // print a placeholder for ciphertext
    printf("ciphertext: ");

    // encrypt the plaintext by rotating each char by the key, print the ciphertext for each char
    for (int i = 0, le = strlen(plaintext); i < le; i++)
    {
        ciphertext = rotate(key, plaintext[i]);
        printf("%c", ciphertext);
    }
    printf("\n");
}

// function to check if the string is an int or not, return false if found any non integer char
bool onlydigits(string str)
{
    for (int i = 0, length = strlen(str); i < length; i++)
    {
        // if char is not a digit, then return false
        if (isdigit(str[i]) == false)
        {
            return false;
        }
    }
    return true;
}

char rotate(int key, char c)
{
    int ch;
    char newch;
    // check if the char is alphabet or not
    if (isalpha(c))
    {
        // get the new chipertext's int by adding the original digits + key
        ch = (int)c;
        int converted = 0;
        // check if the char is lowercase or uppercase
        if (islower(c))
        {
            converted = 97;
        }
        else if (isupper(c))
        {
            converted = 65;
        }
        // this will convert the digits of char to its index within 0 to 255
        ch -= converted;
        // add the inder of char with key to see the shifted position
        ch += key;
        // use mod 26 so the index number will only get within 0 to 255
        ch %= 26;        // swap and turn
        // index + the converted to get the digits of the encrypted char
        ch += converted;
        // convert the plaintext to the ciphertext
        newch = (char)ch;
    }
    // if char is not alphabet, then return its original char
    else
    {
        return c;
    }
    // return the ciphertext
    return newch;
}