#include <stdio.h>

void selectionsort(int arr[], int length);
void printsortedarray(int arr[], int length);

int main(void)
{
    // array of int,length of 8
    int arr[] = {7,2,5,4,1,6,0,3};
    //  length OF array of integers can be found by this 
    int length = sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr, length);
    printsortedarray(arr, length);    
}

void selectionsort(int arr[], int length)
{
    int smallestidx;
    for (int i = 0; i < length; i++)
    {
        smallestidx = i;
        for (int j = i+1; j < length; j++)
        {
            // find the smallest index
            if (arr[smallestidx] < arr[j])
            {
                smallestidx = j;
            }
        }
        // swap the smallest index val value to the most left part of the array
        int temp = arr[i];
        arr[i] = arr[smallestidx];
        arr[smallestidx] = temp;
    }
}

void printsortedarray(int arr[], int length)
{
    for (int i = 0 ; i < length; i++)
    {
        printf("%i", arr[i]);
    }
    printf("\n");
}
