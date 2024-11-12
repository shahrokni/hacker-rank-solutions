/* https://www.hackerrank.com/challenges/the-birthday-bar */
/* Difficulty Easy */

#include <stdlib.h>

int birthday(int s_count, int *s, int d, int m) {
  int result = 0;
  int pointer = 0;
  while (pointer + m <= s_count) {
    int total_days = 0;
    for (int i = pointer; i < pointer + m; i += 1) {
      total_days += s[i];
    }
    if (total_days == d)
      result += 1;
    pointer += 1;
  }

  return result;
}