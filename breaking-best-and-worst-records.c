/* https://www.hackerrank.com/challenges/breaking-best-and-worst-records */
/* Difficulty Easy */
#include <stdlib.h>

int *breakingRecords(int scores_count, int *scores, int *result_count) {
  int *result = malloc(sizeof(int) * 2);
  int max = scores[0];
  int min = scores[0];
  int max_pushed_record = 0;
  int min_pulled_record = 0;

  for (int i = 1; i < scores_count; i += 1) {
    if (scores[i] > max) {
      max_pushed_record += 1;
      max = scores[i];
      continue;
    }

    if (scores[i] < min) {
      min_pulled_record += 1;
      min = scores[i];
    }
  }

  result[0] = max_pushed_record;
  result[1] = min_pulled_record;
  *result_count = 2;

  return result;
}