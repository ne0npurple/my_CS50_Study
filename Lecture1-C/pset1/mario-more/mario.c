#include <cs50.h>
#include <stdio.h>


int h;
int get_height(void);
void print_pyramid(int height);

int main(void) 
{
    // get user input
    int height = get_height();

    // print the pyramid
    print_pyramid(height);
}

int get_height(void)
{
    do 
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    return h;
}

void print_pyramid(int height)
{
    for (int i=1; i <= height; i++)
    {
        // right aligned the pyramid by adding space before the hash
        for (int k = height; k > i; k--)
        {
            putchar(' ');
        }
        for (int j=1; j <= i; j++)
        {
            putchar('#');
        }
        
        // print two space to separate each brick of hashes
        printf("  ");
        
        // print the left aligned pyramid
        for (int l=1; l <= i; l++)
        {
            putchar('#');
        }
        printf("\n");
    }
}