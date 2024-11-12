/* https://www.hackerrank.com/challenges/mini-max-sum */
/* Difficulty Easy */

int compare(const void *a, const void *b) {
  int a_value = *(int *)a;
  int b_value = *(int *)b;
  return a_value - b_value;
}

void miniMaxSum(int arr_count, int *arr) {
  long min = 0;
  long max = 0;
  qsort(arr, arr_count, sizeof(int), compare);

  for (int i = 0; i < arr_count - 1; i += 1) {
    min += arr[i];
  }

  for (int i = 1; i < arr_count; i += 1) {
    max += arr[i];
  }

  printf("%ld %ld", min, max);
}