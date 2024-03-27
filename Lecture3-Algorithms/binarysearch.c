#include <cs50.h>
#include <stdio.h>


// NOT YET FINISHED

int main(void)
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int targetnum = 5;
    int length = sizeof(arr)/sizeof(arr[0]);

    // binary search
    bool result = binarysearch(arr, length, targetnum);

    printarray(result);
}

bool binarysearch(int arr[], int length, int targetnum)
{
    int middle_idx = round(length/2);
    if (arr[middle_idx] > targetnum)
    {
        return binarysearch(arr, middle_idx, targetnum);

    }
}

void printarray(bool result)
{
    if (result != true)
    {
        printf("Not found.\n");
    }
    printf("Found.\n");
}