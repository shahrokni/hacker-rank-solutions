/* https://www.hackerrank.com/challenges/sock-merchant/ */
/* Difficulty Easy */
int sockMerchant(int n, int ar_count, int *ar) {
  int result = 0;
  int colors_count[101] = {0};

  for (int i = 0; i < n; i += 1) {
    colors_count[ar[i]] += 1;
  }

  for (int i = 0; i < 101; i += 1) {
    int pair = colors_count[i] / 2;
    result += pair;
  }

  return result;
}