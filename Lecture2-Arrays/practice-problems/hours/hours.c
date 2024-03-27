#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{   
    // return the total hours
    if (output == 'T')
    {
        int sum = 0;
        for (int i = 0; i < weeks; i++)
        {
            sum += hours[i];
        }
        return sum;
        return 0;
    }
    // return the average hours
    else if (output == 'A')
    {
        int sum = 0;
        for (int i = 0; i < weeks; i++)
        {
            sum += hours[i];
        }
        return sum/(float) weeks;
        return 0;
    }
    else
    {
        printf("Please input output as 'T' or 'A'\n");
        return 1;
    }
}