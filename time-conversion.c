/* https://www.hackerrank.com/challenges/time-conversion/problem */
/* Difficulty Easy */
#include <stdio.h>
#include <stdlib.h>

char *timeConversion(char *s) {
  char *formatted = malloc(sizeof(char) * 9);
  if (formatted == NULL)
    return NULL;

  char hour_str[3] = {s[0], s[1], '\0'};
  int hour = atoi(hour_str);
  char minute_str[3] = {s[3], s[4], '\0'};
  char second_str[3] = {s[6], s[7], '\0'};
  char slot = s[8];

  if (slot == 'P' && hour != 12) {
    hour += 12;
  } else if (slot == 'A' && hour == 12) {
    hour = 0;
  }

  sprintf(formatted, "%02d:%s:%s", hour, minute_str, second_str);

  return formatted;
}