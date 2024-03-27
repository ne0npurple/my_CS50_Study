// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    } 
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    for (int j=0; j < n; j++)
    {
        printf("%i\n", arr[j]);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int max_idx = 0;
    for (int i=0; i < n-1; i++)
    {
        if (array[max_idx] < array[i+1])
        {
            max_idx = i+1;
            printf("maxidx is %i\n", max_idx);
        }
    }
    return array[max_idx];
}
