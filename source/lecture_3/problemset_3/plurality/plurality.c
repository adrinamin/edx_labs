#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct {
  char *name;
  int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(char *name);
void print_winner(void);

int main(int argc, char *argv[]) {
  // Check for invalid usage
  if (argc < 2) {
    printf("Usage: plurality [candidate ...]\n");
    return 1;
  }

  // Populate array of candidates
  candidate_count = argc - 1;
  if (candidate_count > MAX) {
    printf("Maximum number of candidates is %i\n", MAX);
    return 2;
  }

  for (int i = 0; i < candidate_count; i++) {
    candidates[i].name = argv[i + 1];
    candidates[i].votes = 0;

    // printf("DEBUG: canditate: %s\n", candidates[i].name);
  }

  printf("Number of votes: ");
  int voter_count;
  scanf("%d", &voter_count);

  // Loop over all voters
  for (int i = 0; i < voter_count; i++) {
    printf("Vote: ");
    char name[25];
    scanf("%s24[^\n]", name);

    // Check for invalid vote
    if (!vote(name)) {
      printf("Invalid vote.\n");
    }
  }

  // Display winner of election
  print_winner();
}

// Update vote totals given a new vote
bool vote(char *name) {
  //   printf("DEBUG: vote for %s\n", name);
  //   printf("DEBUG: candidate count: %i\n", candidate_count);
  for (int i = 0; i < candidate_count; i++) {
    if (strcmp(candidates[i].name, name) == 0) {
      candidates[i].votes += 1;
      //   printf("DEBUG: equal: %s <-> %s\n", candidates[i].name, name);
      return true;
    }
  }
  return false;
}

// Print the winner (or winners) of the election
void print_winner(void) {
//   for (int i = 0; i < candidate_count; i++) {
//     printf("DEBUG: %i\n", candidates[i].votes);
//   }

//   printf("\n");
  for (int i = 0; i < candidate_count; i++) {
    if (candidates[i].votes < candidates[i + 1].votes) {
      candidate tmp = candidates[i];
      candidates[i] = candidates[i + 1];
      candidates[i + 1] = tmp;
    }
  }

//   for (int i = 0; i < candidate_count; i++) {
//     printf("DEBUG: %s\n", candidates[i].name);
//   }

  int max_votes = candidates[0].votes;

  for (int i = 0; i < candidate_count; i++) {
    if (candidates[i].votes == max_votes) {
      printf("Winner: %s\n", candidates[i].name);
    }
  }

  return;
}