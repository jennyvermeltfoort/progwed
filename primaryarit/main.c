#include <stdio.h>

int main(void) {
    int ops = 0;

    if (ops == 0) {
        printf("No carry operations.");
    } else if (ops == 1) {
        printf("1 carry operation.");
    } else {
        printf("%i carry operations.", ops);
    }

    return 0;
}