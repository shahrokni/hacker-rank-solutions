/* https://www.hackerrank.com/challenges/divisible-sum-pairs */
/* Difficulty Easy*/
#include <stdlib.h>

int divisibleSumPairs(int n, int k, int ar_count, int *ar) {
  int result = 0;

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j += 1) {
      if ((ar[i] + ar[j]) % k == 0)
        result += 1;
    }
  }

  return result;
}