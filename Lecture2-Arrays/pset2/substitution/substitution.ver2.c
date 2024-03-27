#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char ALPHABETH[26] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};

string key;
char ciphertext;

bool checkkey(string str);
char encrypt(char ch, string key);

int main(int argc, string argv[])
{
    // check if user input a correct string of key
    if (argc == 2 && checkkey(argv[1]) == true)
    {
        key = argv[1];
        printf("key is %s\n", key);
    }
    else if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (isupper(key[i]))
        {
            key[i] -= 'A';
        }
        else
        {
            key[i] -= 'a';
        }
    }

    // get plaintext from user
    string plaintext = get_string("plaintext: ");

    // placeholder
    printf("ciphertext: ");

    // encrypt the plaintext based on the key
    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        ciphertext = encrypt(plaintext[i], key);
        printf("%c", ciphertext);
    }
    printf("\n");
}

// function to check if key contains 26 letters
bool checkkey(string str)
{
    int length = strlen(str);

    // if length is less than 26, then return false
    if (length < 26)
    {
        return false;
    }
    // check if string consist of all 26 alphabeth characters
    for (int i = 0; i < length; i++)
    {
        int num;
        // if the char is not an alphabeth, return false
        if (!isalpha(str[i]))
        {
            return false;
        }
        // check if the plaintext[i] is lowercase and get the index by digit - 97
        if (islower(str[i]))
        {
            num = (int)str[i] - 97;
        }
        // check if the plaintext[i] is uppercase and get the index by digit - 65
        else
        {
            num = (int)str[i] - 65;
        }
        // check if the letter of the key exist or not, if not exist then put bool to true.
        if (ALPHABETH[num] != true)
        {
            ALPHABETH[num] = true;
        }
        // if found duplicate, then return false
        else
        {
            return false;
        }
    }
    return true;
}

// encrypt each char from the plaintext based on the key
char encrypt(char c, string key)
{
    int index;
    // only encrypt the alphabeths
    if (isalpha(c))
    {
        // check if the char of plaintext a lowercase or not, get the index of that alphabeths by subtract the digit - 97
        if (islower(c))
        {
            index = (int)c - 97;
            return key[index] + 97;
        }
        index = (int)c - 65;
        return key[index] + 65;
    }
    // return its original characters if the char is non alphabeths
    else
    {
        return c;
    }
}