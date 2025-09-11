#include <stdio.h>

int find_lands(int n, int depth) {
    int added = 0;

    if (depth < 2) {
        return 1;
    }

    if (n < 2) {
        added = 1;
    }
    if (n == 2) {
        added = 2;
    }

    for (int i = 0; i < (n - 2); i++) {
        added += 1 + i * (n - i - 2);
    }

    if (n >= depth) {
        return added;
    }

    return added + find_lands(++n, depth);
}

int main(void) {
    int cases;
    scanf("%i", &cases);

    for (int i = 0; i < cases; i++) {
        scanf("\n");
        int n = 0;
        scanf("%i", &n);
        printf("%i\n", find_lands(0, n));
    }
}
