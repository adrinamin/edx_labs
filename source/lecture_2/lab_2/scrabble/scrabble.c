#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ENTRIES 100
#define MAX_WORD_LENGTH 25
#define POINTS_LENGTH 26

void addToDictionary(struct key_value_pair dictionary[], char key, int value, int *count);
bool is_upper(char c);
void make_lower(char *c);

struct key_value_pair
{
    char key;
    int value;
};

struct key_value_pair dictionary[POINTS_LENGTH];

// Points assigned to each letter of the alphabet
int POINTS[POINTS_LENGTH] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char *word);

int main(void)
{

    int count = 0;
    for (int i = 0; i < POINTS_LENGTH; i++)
    {
        char key = 'a' + i;
        int value = POINTS[i];
        addToDictionary(dictionary, key, value, &count);
    }

    // Get input words from both players
    char word1[25];
    char word2[25];

    printf("Player 1: ");
    scanf("%24s*c", word1);

    printf("Player 2: ");
    scanf("%24s*c", word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

void addToDictionary(struct key_value_pair dictionary[], char key, int value, int *count)
{
    if (*count >= POINTS_LENGTH)
    {
        printf("Dictionary is full. Cannot add more entries.\n");
        return;
    }

    dictionary[*count].key = key;
    dictionary[*count].value = value;
    (*count)++;
}

bool is_upper(char c)
{
    return c >= 'A' && c <= 'Z';
}

void make_lower(char *c)
{
    if (is_upper(*c))
    {
        *c += 32;
    }
}

int compute_score(char *word)
{
    int score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (is_upper(word[i]))
        {
            make_lower(&word[i]);
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        for (int j = 0; j < POINTS_LENGTH; j++)
        {
            if (word[i] == dictionary[j].key)
            {
                score += dictionary[j].value;
            }
        }
    }
    return score;
}
