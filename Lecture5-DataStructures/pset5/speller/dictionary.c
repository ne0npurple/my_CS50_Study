// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

size_t table_size;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO, ok
    unsigned int hash_value = hash(word);

    for (node *cursor = table[hash_value]; cursor != NULL; cursor = cursor->next)
    {
        size_t index = 0;
        for(index = 0; ; ++index) {
            if (cursor->word[index] == '\0' || word[index] == '\0') {
                break;
            }
            if (cursor->word[index] != tolower(word[index])) {
                break;
            }
        }
        if (cursor->word[index] == tolower(word[index])) {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash_value = 0;
    // TODO: Improve this hash function, ok
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash_value ^= tolower(word[i]);
    }
    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("File unable to load.");
        return false;
    }
    char *line;
    size_t nread;
    size_t len;
    while ((nread = getline(&line, &len, file)) != -1)
    {
        line[nread-1] = '\0';
        unsigned int hash_value = hash(line);
        if (check(line))
        {
            continue;
        }
        node *new_node = malloc(sizeof(node));
        for(size_t i = 0; i < nread-1; i++) {
            new_node->word[i] = line[i];
        }
        new_node->next = table[hash_value];
        table[hash_value] = new_node;
        ++table_size;
    }
    free(line);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO, ok
    return table_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO, ok
    for (int i = 0; i < N; i++)
    {
        for (node *cursor = table[i]; cursor != NULL;)
        {
            node *tmp = cursor->next;
            free(cursor);
            cursor = tmp;
        }
    }
    return true;
}
