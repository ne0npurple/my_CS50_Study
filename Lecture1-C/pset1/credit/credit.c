#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

char* cardtype;
char str[20];
char strnum[2];
long cardnumber;
int length = 0;
int leftsum = 0;
int rightsum = 0;
int newsum = 0;
int mark = 0;
int newmult = 0;
long get_cardnumber(void);
int get_cardlength(long cardnumber);

int main(void) 
{
    // get user input for credit card number
    long cardnumber = get_cardnumber();

    // check length of card
    int length = get_cardlength(cardnumber);
    
    // convert the int to a string
    sprintf(str, "%ld", cardnumber);

    // Luhn's Algorithms
    // multiply by 2 for each 2 digits from the right
    for (int i = length-1; i >= 0; i-=2)
    {
        int num = str[i] - 48;
        int mult = num * 2;
        while (mult != 0)
        {
            rightsum += mult % 10;
            mult /= 10;
        }
    }

    // get the sum of digits that weren't multiply by 2
    for (int k = length; k >= 0; k-=2)
    {
        int num = str[k] - 48;
        leftsum += num;
    }

    // if mod result is 0 then the card is valid
    int sums = leftsum + rightsum;
    if (sums % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // check length
    if (length <= 10)
    {
        printf("INVALID\n");
        return 0;
    }

    if (str[0] == '3' && (str[1] == '4' || str[1] == '7'))
    {
        cardtype = "AMEX";
    }
    else if (str[0] == '5' && (str[1] == '1' || str[1] == '2' || str[1] == '3' || str[1] == '4' || str[1] == '5'))
    {
        cardtype = "MASTERCARD";
    }
    else if (str[0] == '4')
    {
        cardtype = "VISA";
    }
    else
    {
        cardtype = "INVALID";
    }

    // print the output
    printf("%s\n", cardtype);

}

long get_cardnumber(void)
{
    do 
    {
        cardnumber = get_long("Number: ");
    }
    while (cardnumber < 0);
    return cardnumber;
}

int get_cardlength(long cardnumber)
{
    do 
    {
        cardnumber = cardnumber/10;
        length += 1;
    }
    while (cardnumber >= 10);
    return length;
}