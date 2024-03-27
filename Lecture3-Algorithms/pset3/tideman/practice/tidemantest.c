#include <cs50.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// added by me
int winner_idx;
// int isvisited[MAX];

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool has_loop(void);
bool recursive(int index, int visited[]);

int main(int argc, string argv[])
{
    // candidate_count = 3;
    // int visited[3] = {0};
    // locked[0][1] = true;
    // locked[0][2] = true;
    // locked[1][2] = true;
    // recursive(0, visited);
    // return 0;
    
    if (argc != 3)
    {
        return 1;
    }

    // Determine which test to run
    int setup = atoi(argv[1]);
    int test = atoi(argv[2]);

    // Setup
    switch (setup)
    {
    case 0:
        candidate_count = 3;
        candidates[0] = "Alice";
        candidates[1] = "Bob";
        candidates[2] = "Charlie";
        for (int i = 0; i < candidate_count; i++)
            for (int j = 0; j < candidate_count; j++)
                preferences[i][j] = 0;
        break;

    case 1:
        candidate_count = 3;
        preferences[0][0] = 0;
        preferences[0][1] = 5;
        preferences[0][2] = 6;
        preferences[1][0] = 4;
        preferences[1][1] = 0;
        preferences[1][2] = 4;
        preferences[2][0] = 3;
        preferences[2][1] = 5;
        preferences[2][2] = 0;
        break;

    case 2:
        candidate_count = 3;
        preferences[0][0] = 0;
        preferences[0][1] = 6;
        preferences[0][2] = 8;
        preferences[1][0] = 6;
        preferences[1][1] = 0;
        preferences[1][2] = 3;
        preferences[2][0] = 4;
        preferences[2][1] = 9;
        preferences[2][2] = 0;
        break;

    case 3:
        candidate_count = 3;
        pair_count = 3;
        preferences[0][0] = 0;
        preferences[0][1] = 6;
        preferences[0][2] = 7;
        preferences[1][0] = 3;
        preferences[1][1] = 0;
        preferences[1][2] = 4;
        preferences[2][0] = 2;
        preferences[2][1] = 5;
        preferences[2][2] = 0;
        pairs[0].winner = 0;
        pairs[0].loser = 1;
        pairs[1].winner = 0;
        pairs[1].loser = 2;
        pairs[2].winner = 2;
        pairs[2].loser = 1;
        break;

    case 4:
        candidate_count = 4;
        candidates[0] = "Alice";
        candidates[1] = "Bob";
        candidates[2] = "Charlie";
        candidates[3] = "David";
        break;

    case 5:
        candidate_count = 5;
        candidates[0] = "Alice";
        candidates[1] = "Bob";
        candidates[2] = "Charlie";
        candidates[3] = "David";
        candidates[4] = "Erin";
        break;

    case 6:
        candidate_count = 6;
        candidates[0] = "Alice";
        candidates[1] = "Bob";
        candidates[2] = "Charlie";
        candidates[3] = "David";
        candidates[4] = "Eric";
        candidates[5] = "Frank";
        break;
    }

    // Test
    int ranks3[3];
    int temp;
    switch (test)
    {
    case 0:
        ranks3[0] = ranks3[1] = ranks3[2] = 0;
        printf("%s", vote(0, "Bob", ranks3) ? "true" : "false");
        break;

    case 1:
        ranks3[0] = ranks3[1] = ranks3[2] = 0;
        printf("%s", vote(0, "David", ranks3) ? "true" : "false");
        break;

    case 2:
        ranks3[0] = ranks3[1] = ranks3[2] = 0;
        vote(0, "Bob", ranks3);
        vote(1, "Charlie", ranks3);
        vote(2, "Alice", ranks3);
        printf("%i %i %i", ranks3[0], ranks3[1], ranks3[2]);
        break;

    case 3:
        ranks3[0] = 1;
        ranks3[1] = 2;
        ranks3[2] = 0;
        record_preferences(ranks3);
        for (int i = 0; i < candidate_count; i++)
            for (int j = 0; j < candidate_count; j++)
                printf("%i ", preferences[i][j]);
        break;

    case 4:
        preferences[0][0] = 0;
        preferences[0][1] = 2;
        preferences[0][2] = 1;
        preferences[1][0] = 3;
        preferences[1][1] = 0;
        preferences[1][2] = 4;
        preferences[2][0] = 3;
        preferences[2][1] = 5;
        preferences[2][2] = 0;
        ranks3[0] = 1;
        ranks3[1] = 0;
        ranks3[2] = 2;
        record_preferences(ranks3);
        for (int i = 0; i < candidate_count; i++)
            for (int j = 0; j < candidate_count; j++)
                printf("%i ", preferences[i][j]);
        break;

    case 5:
        add_pairs();
        printf("%i\n", pair_count);
        break;

    case 6:
        add_pairs();
        for (int i = 0; i < 3; i++)
            if (pairs[i].winner == 0 && pairs[i].loser == 1)
                printf("true ");
            else if (pairs[i].winner == 0 && pairs[i].loser == 2)
                printf("true ");
            else if (pairs[i].winner == 2 && pairs[i].loser == 1)
                printf("true ");
        break;

    case 7:
        add_pairs();
        temp = 0;
        for (int i = 0; i < 3; i++)
        {
            if (pairs[i].winner == 1 && pairs[i].loser == 0)
                temp++;
            else if (pairs[i].winner == 2 && pairs[i].loser == 0)
                temp++;
            else if (pairs[i].winner == 1 && pairs[i].loser == 2)
                temp++;
        }
        printf("%i", temp);
        break;

    case 8:
        sort_pairs();
        for (int i = 0; i < 3; i++)
            printf("%i %i ", pairs[i].winner, pairs[i].loser);
        break;

    case 9:
        pair_count = 4;
        pairs[0].winner = 0;
        pairs[0].loser = 1;
        pairs[1].winner = 1;
        pairs[1].loser = 2;
        pairs[2].winner = 2;
        pairs[2].loser = 3;
        pairs[3].winner = 1;
        pairs[3].loser = 3;
        lock_pairs();
        for (int i = 0; i < candidate_count; i++)
            for (int j = 0; j < candidate_count; j++)
                printf("%s ", locked[i][j] ? "true" : "false");
        break;

    case 10:
        pair_count = 4;
        pairs[0].winner = 0;
        pairs[0].loser = 1;
        pairs[1].winner = 1;
        pairs[1].loser = 2;
        pairs[2].winner = 2;
        pairs[2].loser = 3;
        pairs[3].winner = 3;
        pairs[3].loser = 0;
        lock_pairs();
        for (int i = 0; i < candidate_count; i++)
            for (int j = 0; j < candidate_count; j++)
                printf("%s ", locked[i][j] ? "true" : "false");
        break;

    case 11:
        pair_count = 4;
        pairs[0].winner = 0;
        pairs[0].loser = 1;
        pairs[1].winner = 1;
        pairs[1].loser = 2;
        pairs[2].winner = 2;
        pairs[2].loser = 0;
        pairs[3].winner = 2;
        pairs[3].loser = 3;
        lock_pairs();
        for (int i = 0; i < candidate_count; i++)
            for (int j = 0; j < candidate_count; j++)
                printf("%s ", locked[i][j] ? "true" : "false");
        break;

    case 12:
        pair_count = 6;
        locked[0][0] = false;
        locked[0][1] = locked[0][2] = locked[0][3] = true;
        locked[1][0] = locked[1][1] = false;
        locked[1][2] = locked[1][3] = true;
        locked[2][0] = locked[2][1] = locked[2][2] = false;
        locked[2][3] = true;
        locked[3][0] = locked[3][1] = locked[3][2] = locked[3][3] = false;
        printf("is it work\n");
        print_winner();
        break;

    case 13:
        pair_count = 4;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                locked[i][j] = false;
        locked[2][0] = true;
        locked[0][1] = true;
        locked[0][3] = true;
        locked[1][3] = true;
        print_winner();
        break;

    case 14: // lock final pair test
        pair_count = 7;
        pairs[0].winner = 0;
        pairs[0].loser = 1;
        pairs[1].winner = 1;
        pairs[1].loser = 4;
        pairs[2].winner = 4;
        pairs[2].loser = 2;
        pairs[3].winner = 4;
        pairs[3].loser = 3;
        pairs[4].winner = 3;
        pairs[4].loser = 5;
        pairs[5].winner = 5;
        pairs[5].loser = 1;
        pairs[6].winner = 2;
        pairs[6].loser = 1;

        lock_pairs();
        for (int i = 0; i < candidate_count; i++)
            for (int j = 0; j < candidate_count; j++)
                printf("%s ", locked[i][j] ? "true" : "false");
        break;

    case 15: // lock middle pair test
        pair_count = 5;
        pairs[0].winner = 2;
        pairs[0].loser = 0;
        pairs[1].winner = 4;
        pairs[1].loser = 1;
        pairs[2].winner = 1;
        pairs[2].loser = 3;
        pairs[3].winner = 3;
        pairs[3].loser = 4;
        pairs[4].winner = 4;
        pairs[4].loser = 2;

        lock_pairs();
        for (int i = 0; i < candidate_count; i++)
            for (int j = 0; j < candidate_count; j++)
                printf("%s ", locked[i][j] ? "true" : "false");
        break;

    case 16: // lock all pairs if no cycles
        pair_count = 4;
        pairs[0].winner = 4;
        pairs[0].loser = 2;
        pairs[1].winner = 0;
        pairs[1].loser = 3;
        pairs[2].winner = 1;
        pairs[2].loser = 0;
        pairs[3].winner = 3;
        pairs[3].loser = 4;

        lock_pairs();
        for (int i = 0; i < candidate_count; i++)
            for (int j = 0; j < candidate_count; j++)
                printf("%s ", locked[i][j] ? "true" : "false");
        break;
    }
}

// int main1(int argc, string argv[])
// {
//     // Check for invalid usage
//     if (argc < 2)
//     {
//         printf("Usage: tideman [candidate ...]\n");
//         return 1;
//     }

//     // Populate array of candidates
//     candidate_count = argc - 1;
//     if (candidate_count > MAX)
//     {
//         printf("Maximum number of candidates is %i\n", MAX);
//         return 2;
//     }
//     for (int i = 0; i < candidate_count; i++)
//     {
//         candidates[i] = argv[i + 1];
//     }

//     // Clear graph of locked in pairs
//     for (int i = 0; i < candidate_count; i++)
//     {
//         for (int j = 0; j < candidate_count; j++)
//         {
//             locked[i][j] = false;
//         }
//     }

//     pair_count = 0;
//     int voter_count = get_int("Number of voters: ");

//     // Query for votes
//     for (int i = 0; i < voter_count; i++)
//     {
//         // ranks[i] is voter's ith preference
//         int ranks[candidate_count];

//         // Query for each rank
//         for (int j = 0; j < candidate_count; j++)
//         {
//             string name = get_string("Rank %i: ", j + 1);

//             if (!vote(j, name, ranks))
//             {
//                 printf("Invalid vote.\n");
//                 return 3;
//             }
//         }

//         record_preferences(ranks);

//         printf("\n");
//     }

//     add_pairs();
//     sort_pairs();
//     lock_pairs();
//     print_winner();
//     return 0;
// }

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int idx = 0; idx < candidate_count; idx++)
    {
        if (strcasecmp(candidates[idx], name) == 0)
        {
            ranks[rank] = idx;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] == preferences[j][i])
            {
                continue;
            }
            int wnr = j;
            int lsr = i;
            if (preferences[i][j] > preferences[j][i])
            {
                wnr = i;
                lsr = j;
            }
            pair_count += 1;
            pairs[pair_count - 1].winner = wnr;
            pairs[pair_count - 1].loser = lsr;
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    // Use Bubble sort
    bool swapped = false;
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count; j++)
        {
            int left = preferences[pairs[j].winner][pairs[j].loser];
            int right = preferences[pairs[j + 1].winner][pairs[j + 1].loser];
            if (left < right)
            {
                int tmppwin = pairs[j].winner;
                int tmpplos = pairs[j].loser;
                pairs[j].winner = pairs[j + 1].winner;
                pairs[j].loser = pairs[j + 1].loser;
                pairs[j + 1].winner = tmppwin;
                pairs[j + 1].loser = tmpplos;
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // // locked the graph, set to true for all pairs
    for (int l = 0; l < pair_count; l++)
    {
        printf("pairs[%d]. winner: %d, loser: %d\n", l, pairs[l].winner, pairs[l].loser);
        locked[pairs[l].winner][pairs[l].loser] = true;
        if (has_loop())
        {
            locked[pairs[l].winner][pairs[l].loser] = false;
            continue;
        } 
        winner_idx = pairs[l].winner;
        printf("winner idx is %i\n", winner_idx);
    }

    // if (pair_count != 0)
    // {
    //     for (int l = 0; l < pair_count; l++)
    //     {
    //         // printf("pairs[%d]. winner: %d, loser: %d\n", l, pairs[l].winner, pairs[l].loser);
    //         locked[pairs[l].winner][pairs[l].loser] = true;
    //         if (has_loop())
    //         {
    //             locked[pairs[l].winner][pairs[l].loser] = false;
    //             continue;
    //         }
    //         // if there is no loop, set the winner to the winner from the last locked pair
    //         // winner_idx = pairs[l].winner; 
    //     }
    // }
    // else
    // {
    //     winner_idx = -1;
    //     return;
    // }

    // // TEST to print the locked graph
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%d ", locked[i][j]);
        }
        printf("\n");
    }
}

bool has_loop(void)
{
    // initialized visited array to zeros
    int visited[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        visited[i] = 0;
    }

    // mark the index of the visited candidates to 1
    for (int i = 0; i < candidate_count; i++)
    {
        //
        if (recursive(i, visited))
        {
            return true;
        }
    }
    return false;
}

// Create recursive function to check if there is a loop in the graph, if there is a loop, return false.
bool recursive(int index, int visited[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!locked[index][i])
        {
            continue;
        }
        if (visited[i])
        {
            return true;
        }
        visited[i] = 1;
        if (recursive(i, visited))
        {
            return true;
        }
        visited[i] = 0;
    }
    return false;
}

// // Print the winner of the election
// void print_winner(void)
// {
//     // TODO
//     // track isvisited array to determine the winner
//     int isvisited[candidate_count];

//     for (int i =0 ; i < candidate_count; i++)
//     {
//         for (int j=0; j < candidate_count; j++)
//         {
//             if (locked[i][j] == true)
//             {
//                 isvisited[j] = 1;
//             }
//         }
//     }

//     // print is visited array
//     for (int i=0; i < candidate_count; i++)
//     {
//         if (isvisited[i] == 0)
//         {
//             winner_idx = i;
//         }
//     }

//     if (winner_idx >= 0)
//     {
//         printf("%s\n", candidates[winner_idx]);
//     }
// }


// Print the winner of the election
void print_winner(void)
{
    // TODO
    // track isvisited array to determine the winner
    if (pair_count != 0)
    {
        // initialized visited array based on locked graph
        int isvisited[candidate_count];
        for (int i = 0; i < candidate_count; i++)
        {
            isvisited[i] = 0;
        }

        // marked the visited 
        for (int i =0 ; i < candidate_count; i++)
        {
            for (int j=0; j < candidate_count; j++)
            {
                if (locked[i][j] == true)
                {
                    printf("i is %i, j is %i \n", i, j);
                    isvisited[j] = 1;  
                    printf("isvisited val is %i\n", isvisited[j]);
                }
            }
        }

        for (int i=0; i < candidate_count; i++)
        {
            printf("isvivisted idx is %i, val is %i\n", i, isvisited[i]);
            if (isvisited[i] == 0)
            {
                winner_idx = i;
                printf("%s\n", candidates[winner_idx]);
            }
        }
    }
    else
    {
        winner_idx = -1;
    }

    // PRINT LOCKED PAIRS
    printf("check\n");
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%d ", locked[i][j]);
        }
        printf("\n");
    }

    if (winner_idx >= 0)
    {
        printf("%s\n", candidates[winner_idx]);
    }
}