

/*
wie is er winnend voor een bepaalde n?
Gebruik deze winnende n  om te kijken over de volgende n winnend is.
bijvoorbeeld bij n = 1000
kijk of n = 500 winnend is, want 500 * 2 is winnend.
als 400 winnend is voor degene die aan de beurt is

kijk in hoeveel getallen je 1000 kan delen bijvoorbeeld 2^n * 3^n ...
wanneer het aantal getallen even of oneven is? werkt niet werkt alleen voor een
bepaalde n.

n = 2 stan wint
... n = 9 stan (9) --> zet 1
n = 10 ollie wint
... n = 18 ollie wint (9 * 2) --> zet 2, de twee de minimale gooi van stan
n = 19 stan wint
... n = 36 -> wanneer stan begint met een 2
... n = 54 -> wanneer stan begint met een 3 -> bij 28, stan begint, 3x9 = 18 max
                dus 3x2x5 -> stan wint
... n = 82
... n = 162 stan wint, (9 * 2 * 9) --> zet 3, de twee id de minimal gooi van
ollie n = 163 ollie wint
... n = 324 ollie wint (9 * 2 * 9 * 2) --> zet 4
...


*/

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    unsigned int n = 0;

    while (scanf("%i\n", &n) > 0) {
        bool toggle = false;
        unsigned int p = 1;

        while (p < n) {
            p *= 9.0f * !toggle + 2.0f * toggle;
            toggle = !toggle;
        }

        if (toggle || n == 1) {
            printf("Stan wins.\n");
        } else {
            printf("Ollie wins.\n");
        }
    }

    return 0;
}
