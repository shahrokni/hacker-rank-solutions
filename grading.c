/* https://www.hackerrank.com/challenges/grading */
/* Difficulty Easy */
/* Next multiple of any number? */
#include <stdlib.h>

int *gradingStudents(int grades_count, int *grades, int *result_count) {

  int *result = malloc(sizeof(int) * grades_count);

  for (int i = 0; i < grades_count; i += 1) {
    if (grades[i] < 38)
      result[i] = grades[i];
    else {
      int next_mul_five = grades[i] + abs(5 - (grades[i] % 5));
      if (next_mul_five - grades[i] < 3)
        result[i] = next_mul_five;
      else
        result[i] = grades[i];
    }
  }

  *result_count = grades_count;

  return result;
}