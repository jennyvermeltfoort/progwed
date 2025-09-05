#include <stdbool.h>
#include <stdio.h>

int main(void) {
  char c = '!';

  do {
    int wc[2][0xFF] = {0};

    if (c != '!') {
      printf("\n");
    }

    for (int i = 0; i < 2; i++) {
      do {
        wc[i][(int)c]++;
        do {
          c = getchar();
        } while (c == ' ');
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
  } while (c >= 0);
}