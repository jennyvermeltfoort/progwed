#include <stdbool.h>
#include <stdio.h>

int main(void) {
  char c;

  do {
    int wc[2][0xFF] = {0};

    c = getchar();
    for (int i = 0; i < 2; i++) {
      do {
        wc[i][(int)c]++;
        c = getchar();
      } while (c >= 'a' && c <= 'z');
    }

    for (char i = 'a'; i <= 'z'; i++) {
      if (wc[0][(int)i] && wc[1][(int)i]) {
        int min =
            (wc[0][(int)i] < wc[1][(int)i]) ? wc[0][(int)i] : wc[1][(int)i];
        while (min--) {
          printf("%c", i);
        }
      }
    }

    printf("\n");

    if (c < 0) {
      return 0;
    }

  } while (true);
}