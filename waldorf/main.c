#include <stdbool.h>
#include <stdio.h>

#define ARR_SIZE_MAX_X 50
#define ARR_SIZE_MAX_Y 50
#define WORD_MAX_LENGTH 50
#define WORDS_MAX_AMOUNT 20

bool has_word_inc(char arr[ARR_SIZE_MAX_Y + 2][ARR_SIZE_MAX_X + 2], int py,
                  int px, char *word, int incy, int incx) {
  while (true) {
    if (arr[py][px] != ((*word) | 0x20)) {
      return false;
    };
    word++;
    if (*word == '\0') {
      return true;
    };
    px += incx;
    py += incy;
  }
}

bool has_word(char arr[ARR_SIZE_MAX_Y + 2][ARR_SIZE_MAX_X + 2], int py, int px,
              char *word) {
  if (has_word_inc(arr, py, px, word, 1, 0))
    return true;
  if (has_word_inc(arr, py, px, word, -1, 0))
    return true;
  if (has_word_inc(arr, py, px, word, 0, 1))
    return true;
  if (has_word_inc(arr, py, px, word, 0, -1))
    return true;
  if (has_word_inc(arr, py, px, word, 1, 1))
    return true;
  if (has_word_inc(arr, py, px, word, 1, -1))
    return true;
  if (has_word_inc(arr, py, px, word, -1, -1))
    return true;
  if (has_word_inc(arr, py, px, word, -1, 1))
    return true;
  return false;
}

int main(void) {
  int cases = 0;
  scanf("%i", &cases);
  char buf[10];

  while (cases--) {
    fgets(buf, 10, stdin);

    int m = 0;
    int n = 0;
    char c = 0;

    scanf("%i", &m);
    scanf("%i", &n);
    scanf("%c", &c);

    char arr[ARR_SIZE_MAX_Y + 2][ARR_SIZE_MAX_X + 2] = {0};
    for (int y = 1; y < (m + 1); y++) {
      for (int x = 1; x < (n + 1); x++) {
        scanf("%c", &c);
        arr[y][x] = c | 0x20;
      }
      scanf("%c", &c);
    }

    int k = 0;
    scanf("%i", &k);
    scanf("%c", &c);

    char words[WORDS_MAX_AMOUNT][WORD_MAX_LENGTH] = {0};
    for (int i = 0; i < k; i++) {
      scanf("%50s", words[i]);
    }

    int res[WORDS_MAX_AMOUNT][2] = {0};

    for (int i = 0; i < k; i++) {
      for (int y = 1; y < (m + 1); y++) {
        for (int x = 1; x < (n + 1); x++) {
          if (has_word(arr, y, x, words[i])) {
            res[i][0] = y;
            res[i][1] = x;
          }
          if (res[i][0])
            break;
        }
        if (res[i][0])
          break;
      }
    }

    for (int i = 0; i < k; i++) {
      printf("%i %i\n", res[i][0], res[i][1]);
    }

    if (cases) {

      printf("\n");
    }
  }
}
