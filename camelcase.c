int camelcase(char *s) {

  int count_words = 1;
  int idx = 0;

  while (1) {
    if (s[idx] == '\0')
      break;

    if (s[idx] >= 65 && s[idx] <= 90)
      count_words += 1;

    idx += 1;
  }

  return count_words;
}