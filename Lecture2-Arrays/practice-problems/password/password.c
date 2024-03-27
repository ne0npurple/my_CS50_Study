// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool symbol = false;
    bool lower = false;
    bool upper = false;
    bool num = false;
    for (int i = 0, length= strlen(password); i < length; i++)
    {
        if (password[i] == '!' || password[i] == '$' || password[i] == '#')
        {
            symbol = true;
            printf("s\n");
        }
        else if (islower(password[i]))
        {
            lower = true;
            printf("l\n");
        }
        else if (isupper(password[i]))
        {
            upper = true;
            printf("u\n");
        }
        else if (password[i] == '0' || password[i] == '1' || password[i] == '2' || password[i] == '3' || password[i] == '4' || password[i] == '5' || password[i] == '6' || password[i] == '7' || password[i] == '8' || password[i] == '9')
        {
            num = true;
            printf("n\n");
        }
    }

    if (symbol == true && lower == true && upper == true && num == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
