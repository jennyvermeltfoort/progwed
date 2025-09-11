#include <stdio.h>

#define MAX_STRING_LNGTH
#define MAX_STRING_COUNT

int main(void) {
    int lines = 0;
    scanf("%i", &lines);

    char strings[MAX_STRING_COUNT][MAX_STRING_LNGTH] = {0};
    for (int i = 0; i < lines; i++) {
        scanf("%s\n", strings[i]);
    }

    int max = 0;
    int min = 0;
    int lengths[MAX_STRING_COUNT] = {0};
    for (int i = 0; i < lines; i++) {
        while ((*strings[i])++ != '\0') {
            lengths[i]++;
        }
    }

    return 0;
}