#include <cs50.h>
#include <stdio.h>

int start;
int end;
int counter = 0;
int get_startsize(void);
int get_endsize(void);
int calc_year(void);
void print_years(int counter);

int main(void)
{
    // TODO: Prompt for start size
    int start = get_startsize();

    // TODO: Prompt for end size
    int end = get_endsize();

    // TODO: Calculate number of years until we reach threshold
    // if start and end size equal, it will directly print the number of years
    if (start != end)
    {
        int counter = calc_year();
    }
    
    // TODO: Print number of years
    print_years(counter);
}

// function to get start size
int get_startsize(void)
{
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    return start;
}

// function to get end size
int get_endsize(void)
{
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);
    return end;
}

// function to calculate number of years
int calc_year(void)
{
    int year = start;
    do
    {
        int born = year/3;
        int die = year/4;
        year = year + born - die;
        counter += 1;
        // printf("year= %i, start= %i, counter= %i\n", year, start, counter);
    } 
    while (year < end);
    return counter;
}

// print function
void print_years(int counter)
{
    printf("Years: %i\n", counter);
}