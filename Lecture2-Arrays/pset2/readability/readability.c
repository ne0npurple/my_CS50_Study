#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letters = 0;
int words = 1;
int sentences = 0;

void init_everything(string text);
double get_grade(int letters, int sentences, int words);

int main(void) 
{
    // get user input
    string text = get_string("Text: ");

    // calculate the number of letters, sentences and words
    init_everything(text);

    // calculate grade
    double grade = get_grade(letters, sentences, words);

    // print the output
    if (grade < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    printf("Grade %1.0f\n", round(grade));
}

void init_everything(string text)
{
    for (int i = 0, length=strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
        if (isblank(text[i]))
        {
            words += 1;
        }
        if (ispunct(text[i]))
        {
            if (text[i] == '.' || text[i] == '?' || text[i] == '!')
            {
                sentences += 1;
            }
        }
    }
}

double get_grade(int letters, int sentences, int words)
{
    float L = (float)letters/words * 100;
    float S = (float)sentences/words * 100;
    double grade = ((0.0588 * L) - (0.296 * S)) - (float)15.8;
    printf("%f, %f, %f\n", L, S, grade);
    return grade;
}