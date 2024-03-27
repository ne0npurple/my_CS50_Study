#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // open a file, in "a" or append mode
    FILE *file = fopen("phonebook.csv", "a");

    // get input from user
    string name = get_string("name: ");
    string number = get_string("number: ");

    // insert the file to our phonebook
    fprintf(file, "%s, %s\n", name, number);
    
    // close the file
    fclose(file);
}