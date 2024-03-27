#include <cs50.h>
#include <stdio.h>
#include <string.h>

// define a data structure with a name "person" which consist of two fields, name and number
typedef struct
{
    string name;
    string number;
}
person;


int main(void)
{
    // define a person (consist of name and number) data type with a name people
    person people[2];

    people[0].name = "David";
    people[0].number = "+92837492093";

    people[1].name = "Carter";
    people[1].number = "+93272173462";

    string name = get_string("Name: ");

    for (int i=0; i < 2; i++)
    {
        if (strcasecmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found.\n");
    return 1;
}