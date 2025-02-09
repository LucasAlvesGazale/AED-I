#include <stdio.h>
#include <string.h>

int main() {
    int T;
    char sheldon[10], raj[10];

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%s %s", sheldon, raj);

        if (strcmp(sheldon, raj) == 0) {
            printf("Caso #%d: De novo!\n", t);
        } else if (
            (strcmp(sheldon, "tesoura") == 0 && (strcmp(raj, "papel") == 0 || strcmp(raj, "lagarto") == 0)) ||
            (strcmp(sheldon, "papel") == 0 && (strcmp(raj, "pedra") == 0 || strcmp(raj, "Spock") == 0)) ||
            (strcmp(sheldon, "pedra") == 0 && (strcmp(raj, "lagarto") == 0 || strcmp(raj, "tesoura") == 0)) ||
            (strcmp(sheldon, "lagarto") == 0 && (strcmp(raj, "Spock") == 0 || strcmp(raj, "papel") == 0)) ||
            (strcmp(sheldon, "Spock") == 0 && (strcmp(raj, "tesoura") == 0 || strcmp(raj, "pedra") == 0))
        ) {
            printf("Caso #%d: Bazinga!\n", t);
        } else {
            printf("Caso #%d: Raj trapaceou!\n", t);
        }
    }

    return 0;
}
