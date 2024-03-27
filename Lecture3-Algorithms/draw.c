// IMPLEMENT DRAW BLOCK FUNCTION USING THE RECURSION

#include <cs50.h>
#include <stdio.h>

void draw(int h);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}

void draw(int h)
{
    if (h <= 0)
    {
        // printf("ret\n");
        return;
    }

    draw(h-1);

    // printf("i am here at h is %i", h);
    for (int i = 0; i < h; i++)
    {
        printf("#");
    }
    printf("\n");
}