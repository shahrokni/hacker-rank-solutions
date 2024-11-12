/* https://www.hackerrank.com/challenges/bon-appetit */
/* Difficulty Easy */
#include <stdio.h>
#include <stdlib.h>

void bonAppetit(int bill_count, int *bill, int k, int b) {
  int total = 0;
  for (int i = 0; i < bill_count; i += 1) {
    total += bill[i];
  }

  int correct = abs(total - bill[k]) / 2;

  if (correct == b)
    printf("Bon Appetit");
  else
    printf("%d", abs(b - correct));
}