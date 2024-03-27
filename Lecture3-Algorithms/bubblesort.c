#include <cs50.h>
#include <stdio.h>

void bubblesort(int arr[], int length);
void printarray(int arr[], int length);

int main(void)
{
    // array of ints of 8 numbers from 0 to 7
    int arr[] = {7,2,5,4,1,6,0,3};
    int length = sizeof(arr)/sizeof(arr[0]);

    bubblesort(arr, length);
    printarray(arr, length);
}

void bubblesort(int arr[], int length)
{
    bool swapped = false;
    // iterate the 8 numbers
    for (int i = 0; i < length; i++)
    {
        // j < 8-i-1 so that j only check the arr within the i'th position from the front, since we will swap all the highest number to the rightest array
        for (int j = 0; j < length-i-1; j++)
        {
            if (arr[j] < arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        
        // if the arr of integers already sorted, then break
        if (swapped == false)
        {
            break; 
        }
    }
}

void printarray(int arr[], int length)
{
    for (int i =0 ; i < length; i++)
    {
        printf("%i", arr[i]);
    }
    printf("\n");
}