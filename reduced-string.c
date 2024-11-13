/* https://www.hackerrank.com/challenges/reduced-string */
/* Difficulty Easy */
/* Somehow implemented a very basic stack in C */
#include <stdlib.h>

char *superReducedString(char *s) {
  char *result = malloc(sizeof(char) * 101);
  char stack[100] = {'\0'};
  int pointer = -1;

  for (int i = 0; i < 100; i += 1) {
    if (s[i] == '\0')
      break;

    pointer += 1;
    stack[pointer] = s[i];
    int prev_pointer = pointer - 1;

    if (prev_pointer < 0)
      continue;

    if (stack[pointer] == stack[prev_pointer]) {
      stack[pointer] = '\0';
      stack[prev_pointer] = '\0';
      pointer -= 2;
    }
  }

  int c = 0;
  while (1) {
    if (stack[c] == '\0')
      break;
    result[c] = stack[c];
    c += 1;
  }

  if (!c)
    result = "Empty String\0";
  else
    result[c + 1] = '\0';

  return result;
}