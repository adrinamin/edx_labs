// Implements a dictionary's functionality

#include "dictionary.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node {
  char word[LENGTH + 1];
  struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
// Info: changed it due to warning:
// Variable length array folded to constant array as an extension
// Length is the same as N
node *table[26];

// Returns true if word is in dictionary, else false
bool check(const char *word) {
  // Hash the word to get the bucket index
  unsigned int index = hash(word);

  // Traverse the linked list at the calculated index
  for (node *temp = table[index]; temp != NULL; temp = temp->next) {
    // Compare the word with the dictionary word (case-insensitive)
    if (strcasecmp(temp->word, word) == 0) {
      return true; // Word found
    }
  }

  return false; // Word not found
}

// Hashes word to a number
unsigned int hash(const char *word) {
  // TODO: Improve this hash function
  //   return toupper(word[0]) - 'A';

  // alternative approach:
  unsigned int hash = 0;
  while (*word) {
    // Update the hash value using bitwise left shift and bitwise XOR
    hash = (hash << 2) ^ *word;
    word++;
  }
  // Ensure that the hash value is within the range of available buckets
  return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary) {
  // Open the dictionary file
  FILE *file = fopen(dictionary, "r");
  if (file == NULL) {
    fprintf(stderr, "Could not open %s.\n", dictionary);
    return false;
  }

  // Initialize the table
  for (unsigned int i = 0; i < N; i++) {
    table[i] = NULL;
  }

  // Buffer for reading words
  char word[LENGTH + 1];

  // Read string from file one at a time
  while (fscanf(file, "%s", word) != EOF) {
    node *n = malloc(sizeof(node));
    if (n == NULL) {
      fclose(file);
      fprintf(stderr, "Memory allocation failed.\n");
      return false;
    }

    // Copy the word from the file into the word field
    // of the newly created node
    strcpy(n->word, word);

    // Hash the word to get the bucket index
    unsigned int index = hash(word);

    // Insert the new node at the beginning of the linked list
    n->next = table[index];
    table[index] = n;
  }

  // Close the dictionary file
  fclose(file);

  return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void) {
  unsigned int count = 0;

  // Iterate through each bucket in the hash table
  for (unsigned int i = 0; i < N; i++) {
    // Traverse the linked list at the current bucket
    for (node *temp = table[i]; temp != NULL; temp = temp->next) {
      count++;
    }
  }

  return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void) {
  // Iterate through each bucket in the hash table
  for (unsigned int i = 0; i < N; i++) {
    // Traverse the linked list at the current bucket
    while (table[i] != NULL) {
      // Keep track of the current node
      node *temp = table[i];

      // Move to the next node
      table[i] = table[i]->next;

      // Free the current node
      free(temp);
    }
  }

  return true;
}
