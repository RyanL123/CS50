// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 110;
int totalWords = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int location = hash(word);
    node *n = table[location];
    // Only 1 node in linked list
    if (strcasecmp(word, n->word) == 0) return true;
    while (true){
        if (strcasecmp(word, n->word) == 0){
            return true;
        }
        if (n->next) n = n->next;
        else break;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    if (isalpha(word[0])){
        if (isupper(word[0])){
            return word[0]-65;
        }
        else {
            return word[0]-97;
        }
    }
    return 99;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    node *nextNode[100];
    for (int i = 0; i < 100; i++){
        table[i] = NULL;
    }
     // File exists
    if (dict) {
        char word[50];
        // Scan until EOF
        while (fscanf(dict, "%s", word) != EOF){
            node *n = malloc(sizeof(node));
            if (n != NULL){
                strcpy(n->word, word);
                int location = hash(word);
                n->next = table[location];
                table[location] = n;
                totalWords++;
            }
        }
        fclose(dict);
        return true;
    }
    fclose(dict);
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return totalWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < 100; i++){
        node *n = table[i];
        if (n){
            while (true){
                node *next = n->next;
                free(n);
                if (next) n = next;
                else break;
            }
        }
    }
    return true;
}
