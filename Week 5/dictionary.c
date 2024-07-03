#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int index = hash(word);

    node *current = table[index];
    while (current != NULL)
    {
        if (strcmp(current->word, word) == 0)
        {
            return true;
        }
        current = current->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        char lowercase_char = tolower(word[i]);
        hash = (hash << 2) ^ lowercase_char;
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    char temp[LENGTH + 1];
    while (fscanf(source, "%s", temp) != EOF)
    {
        node *w = malloc(sizeof(node));
        if (w == NULL)
        {
            fclose(source);
            return false;
        }
        strcpy(w->word, temp);
        w->next = NULL;

        unsigned int index = hash(temp);
        if (table[index] == NULL)
        {
            table[index] = w;
        }
        else
        {
            node *current = table[index];
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = w;
        }
    }

    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        node *current = table[i];
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *current = table[i];
        while (current != NULL)
        {
            node *temp = current;
            current = current->next;
            free(temp);
        }
        table[i] = NULL;
    }
    return true;
}