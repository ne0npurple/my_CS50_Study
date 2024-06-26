#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// each of our text files contains 1000 words
#define LISTSIZE 1000

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)
#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters
#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"

// user-defined function prototypes
bool check_wordsize(string str);
string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);

int main(int argc, string argv[])
{
    int le;
    // ensure proper usage
    // TODO #1
    // check if user input command-line argument "wordsize" and if users enters numbers
    if (argc == 2 && check_wordsize(argv[1]) == true)
    {
        le = strlen(argv[1]);
    }
    else
    {
        printf("Usage: %s wordsize\n", argv[0]);
        return 1;
    }
    if (le < 1) {

        printf("Usage: %s wordsize\n", argv[0]);
        return 1;
    }

    int wordsize = 0;
    // ensure argv[1] is either 5, 6, 7, or 8 and store that value in wordsize instead
    // TODO #2
    // check if users input correct wordsize (int of 5/6/7/8)
    wordsize = (int) argv[1][0] - 48;
    if (!(wordsize == 5 || wordsize == 6 || wordsize == 7 || wordsize == 8) || le > 1)
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8\n");
        return 1;
    }

    // open correct file, each file has exactly LISTSIZE words
    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    // load word file into an array of size LISTSIZE
    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    // pseudorandomly select a word for this game
    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];


    // allow one more guess than the length of the word
    int guesses = wordsize + 1;
    bool won = false;

    // print greeting, using ANSI color codes to demonstrate
    printf(GREEN"This is WORDLE50"RESET"\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    // main game loop, one iteration for each guess
    for (int i = 0; i < guesses; i++)
    {
        // obtain user's guess
        string guess = get_guess(wordsize);

        // array to hold guess status, initially set to zero
        int status[wordsize];

        // set all elements of status array initially to 0, aka WRONG
        // TODO #4
        // initialized the array of integers status[wordsize] to zeros, ex: wordsize=5 --> int status[5] = {0, 0, 0, 0, 0};
        for (int j = 0; j < wordsize; j++)
        {
            status[j] = 0;
        }

        // Calculate score for the guess
        int score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);
        
        // Print the guess
        print_word(guess, wordsize, status);

        // if they guessed it exactly right, set terminate loop
        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }
    }

    // Print the game's result
    // TODO #7
    if (won == true)
    {
        printf("You won!\n");
        return 0;
    }
    else
    {
        printf("Target word was: %s\n", choice);
        return 1;
    }
}

// function to check if the string wordsize consist of only numbers, return false if consist non-numbers
bool check_wordsize(string str)
{
    for (int i=0, length=strlen(str); i < length; i++)
    {
        if (isdigit(str[i]) == false)
        {
            return false;
        }
    }
    return true;
}

string get_guess(int wordsize)
{
    string guess = "";

    // ensure users actually provide a guess that is the correct length
    // TODO #3
    while (strlen(guess) != wordsize)
    {
        guess = get_string("Input a %i-letter word: ", wordsize);
    }
    return guess;
}

int check_word(string guess, int wordsize, int status[], string choice)
{
    int score = 0;
    // compare guess to choice and score points as appropriate, storing points in status
    // TODO #5
    // index i to iterate the string guess[wordsize]
    for (int i=0; i < wordsize; i++)
    {
        // index j to iterate the string choice[wordsize]
        for (int j=0; j < wordsize; j++)
        {
            // check if the index are the same AND the char in that index is the same, then set score to EXACT 2 and break so the char will not be checked anymore.
            if ((i == j) && (guess[i] == choice[j]))
            {
                // set the value of EXACT to status
                status[i] = EXACT;
                break;
            }
            else if (guess[i] == choice[j])
            {
                status[i] = CLOSE;
            }
        }
        // add all the score from the found chars
        score += status[i];
    }
    return score;
}

void print_word(string guess, int wordsize, int status[])
{
    // print word character-for-character with correct color coding, then reset terminal font to normal
    // TODO #6
    for (int i = 0; i < wordsize; i++)
    {
        if (status[i] == EXACT)
        {
            printf(GREEN"%c"RESET"", guess[i]);
        }
        else if (status[i] == CLOSE)
        {
            printf(YELLOW"%c"RESET"", guess[i]);
        }
        else
        {
            printf(RED"%c"RESET"", guess[i]);
        }
    }
    printf("\n");
    return;
}
