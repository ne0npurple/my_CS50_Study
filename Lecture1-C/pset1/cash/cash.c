#include <cs50.h>
#include <stdio.h>

int cents;
int quarters = 0;
int dimes = 0;
int nickels = 0;
int pennies = 0;
int coins = 0;
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();
    if (cents == 0)
    {
        coins += 0;
    }
    else
    {
        do 
        {
            // Calculate the number of quarters to give the customer
            if (cents >= 25)
            {
                int quarters = calculate_quarters(cents);
                cents = cents - quarters * 25;
            }
            
            // Calculate the number of dimes to give the customer
            if (cents >= 10)
            {
                int dimes = calculate_dimes(cents);
                cents = cents - dimes * 10;
            }
            
            // Calculate the number of nickels to give the customer
            if (cents >= 5)
            {
                int nickels = calculate_nickels(cents);
                cents = cents - nickels * 5;
            }
            
            // Calculate the number of pennies to give the customer
            if (cents >= 1)
            {
                int pennies = calculate_pennies(cents);
                cents = cents - pennies * 1;
            }
        }
        while (cents != 0);
    }

    // Sum coins
    coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // get number of cents from user
    do 
    {
        cents = get_int("Change owed: ");
    }
    while(cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    // count the number of quarters    
    do
    {
        cents -= 25;
        quarters += 1;
    } 
    while (cents >= 25);
    return quarters;
}

int calculate_dimes(int cents)
{
    // calculate the number of dimes
    do 
    {
        cents -= 10;
        dimes += 1;
    }
    while (cents >= 10);
    return dimes;
}

int calculate_nickels(int cents)
{
    // calc the number of nickels
    do 
    {
        cents -= 5;
        nickels += 1;
    }
    while (cents >= 5);
    return nickels;
}

int calculate_pennies(int cents)
{
    // calc the number of pennies
    do 
    {
        cents -= 1;
        pennies += 1;
    }
    while (cents >= 1);
    return pennies;
}
