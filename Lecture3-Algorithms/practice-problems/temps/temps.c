// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    // Add your code here
    bool swapped = false;
    for (int i = 0; i < NUM_CITIES; i++)
    {   
        // shift all the smallest number to the right position
        for (int j = 0; j < NUM_CITIES-i-1; j++)
        {
            if (temps[j].temp < temps[j+1].temp)
            {
                // make a temp placeholder
                int tmp = temps[j].temp;
                string tmpcty = temps[j].city;
                // swap the value of city and temp
                temps[j].temp = temps[j+1].temp;
                temps[j].city = temps[j+1].city;
                temps[j+1].temp = tmp;
                temps[j+1].city = tmpcty;
                swapped = true;
            }
        }
        // if in the first inner loop there are no swapping, then break the outer loop meaning the array is already sorted
        if (swapped == false)
        {
            break;
        }
        
    }
}
