#include <cs50.h>
#include <stdio.h>

int height;
int get_height(void);
void print_pyramid(int height);

int main(void) 
{
    // get height from user input
    int height = get_height();
    
    // print pyramid based on height inputted by the user
    print_pyramid(height);
}

int get_height(void)
{
    do
    {
        height = get_int("Height: ");    
    } 
    while (height < 1 || height > 8);
    return height;
}

void print_pyramid(int height)
{
    for (int i=1; i<=height; i++)
    {
        // print the space to right-aligned the block
        for (int j=height; j>i; j--)
        {
            putchar(' ');
        }
        // print the block
        for (int k=1; k<=i; k++)
        {
            putchar('#');
        }
        printf("\n");
    }
}