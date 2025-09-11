#include <stdio.h>

#define MAX_STRING_LNGTH 256 * 8
#define MAX_STRING_COUNT 144

int main(void) {
    int cases = 0;
    scanf("%i", &cases);

    while (cases--) {
        char strings[MAX_STRING_COUNT][MAX_STRING_LNGTH] = {0};

        int lines = 0;
        int flag = 1;
        while (flag > 0) {
            flag = scanf("%s\n", strings[lines++]);
            printf("%i\n", flag);
        }

        int max = MAX_STRING_LNGTH;
        int min = -1;
        int lengths[MAX_STRING_COUNT] = {0};
        for (int i = 0; i < lines; i++) {
            char* p = strings[i];
            do {
                printf("%c", *p);
                lengths[i]++;
                min = (lengths[i] < min) ? lengths[i] : min;
                max = (lengths[i] > max) ? lengths[i] : max;
            } while ((*p)++ != '\0');
            printf("\n");
        }
    }

    return 0;
}