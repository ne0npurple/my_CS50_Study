#include <cs50.h>
#include <stdio.h>

// declare a global variable named N which refer to the length of the array (or how many scores to be calculated)
const int N = 3;
float average(int length, int array[]);

int main(void)
{
    // initialized an array of integers value with the size of 3
    int scores[N];
    
    // define the ints
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Scores: ");
    }

    printf("Average: %f\n", average(N, scores));
}

float average(int length, int array[])
{
    int sum = 0;
    for (int i=0; i<length; i++)
    {
        sum += array[i];
    }
    return sum/(float) length;
}