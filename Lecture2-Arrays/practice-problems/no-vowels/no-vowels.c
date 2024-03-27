// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string word = argv[1];
        for (int i = 0, length=strlen(word); i < length; i++)
        {
            if (word[i] == 'a')
            {
                word[i] = '6';
            }
            else if (word[i] == 'i')
            {
                word[i] = '1';
            }
            else if (word[i] == 'e')
            {
                word[i] = '3';
            }
            else if (word[i] == 'o')
            {
                word[i] = '0';
            }
        }
        printf("%s\n", word);
    }
    else
    {
        printf("Usage: %s word\n", argv[0]);
    }
}
