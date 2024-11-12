/* https://www.hackerrank.com/challenges/migratory-birds */
/* Difficulty Easy */
#include <stdlib.h>

int migratoryBirds(int arr_count, int *arr) {
  int seen_types[] = {0, 0, 0, 0, 0};

  for (int i = 0; i < arr_count; i += 1) {
    seen_types[arr[i] - 1] += 1;
  }

  int max = -1;
  int most_seen_type = -1;
  for (int i = 0; i < 5; i += 1) {
    if (seen_types[i] > max) {
      max = seen_types[i];
      most_seen_type = i + 1;
    }
  }

  return most_seen_type;
}