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
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

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
    // locked the graph, set to true for all pairs
    for (int l = 0; l < pair_count; l++)
    {
        locked[pairs[l].winner][pairs[l].loser] = true;
        if (has_loop())
        {
            locked[pairs[l].winner][pairs[l].loser] = false;
            continue;
        } 
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

// Create recursive function to check if there is a loop in the graph, if there is a loop, return false so that the locked pair which caused cycle will be marked as false
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

// Print the winner of the election
void print_winner(void)
{
    // TODO
    if (pair_count != 0)
    {
        // initialized visited array based on locked graph
        int isvisited[candidate_count];
        for (int i = 0; i < candidate_count; i++)
        {
            isvisited[i] = 0;
        }

        // marked the visited candidates to determine the winner
        for (int i =0 ; i < candidate_count; i++)
        {
            for (int j=0; j < candidate_count; j++)
            {
                if (locked[i][j] == true)
                {
                    isvisited[j] = 1;  
                }
            }
        }

        // if the candidates visited == 0, then this candidate is the winner
        for (int i=0; i < candidate_count; i++)
        {
            if (isvisited[i] == 0)
            {
                winner_idx = i;
            }
        }
    }
    else
    {
        // if the votes are ties, there wouldn't be any pair added
        winner_idx = -1;
    }

    // Print the winner
    if (winner_idx >= 0)
    {
        printf("%s\n", candidates[winner_idx]);
    }
}