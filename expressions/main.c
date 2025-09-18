

#include <stdio.h>
#include <string.h>

int main(void) {
    int n = 0;
    int d = 0;
    int B[151][151] = {0};

    while (scanf("%i %i\n", &n, &d) > 0) {
        memset(B, 0, 151 * 151 * sizeof(int));

        for (int t = 0; t < d + 1; t++) {
            B[0][t] = 1;
        }

        for (int m = 1; m < n; m++) {
            for (int t = 1; t < d; t++) {
                for (int k = 0; k < m - 1; k++) {
                    B[m][t] = B[k][t - 1] * B[m - 1 - k][t];
                }
            }
        }

        for (int m = 0; m < 151; m++) {
            for (int t = 0; t < d; t++) {
                printf("%i ", B[m][t]);
            }
            printf("\n");
        }

        printf("%i\n", B[n][d] - B[n][d - 1]);
    }
}