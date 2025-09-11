#include <stdio.h>

int main(void) {
    int number = 0;

    while (scanf("%i\n", &number) != EOF) {
        int ones = 1;
        int mod = ones % number;
        int counter = 1;

        while (mod) {
            mod = mod * 10 + 1;
            mod = mod % number;
            counter++;
        }

        printf("%i\n", counter);
    }

    return 0;
}