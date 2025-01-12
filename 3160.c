#include <stdio.h>
#include <string.h>

#define MAX_FRIENDS 100

int main() {
    char L[MAX_FRIENDS * 20], N[MAX_FRIENDS * 20], S[20];
    char friendsList[100][20];
    char newFriends[100][20];
    int lenL = 0, lenN = 0;

    fgets(L, sizeof(L), stdin);
    L[strcspn(L, "\n")] = 0;
    char *token = strtok(L, " ");
    while (token != NULL) {
        strcpy(friendsList[lenL], token);
        lenL++;
        token = strtok(NULL, " ");
    }

    fgets(N, sizeof(N), stdin);
    N[strcspn(N, "\n")] = 0;
    token = strtok(N, " ");
    while (token != NULL) {
        strcpy(newFriends[lenN], token);
        lenN++;
        token = strtok(NULL, " ");
    }

    fgets(S, sizeof(S), stdin);
    S[strcspn(S, "\n")] = 0;

    int found = 0;
    if (strcmp(S, "nao") == 0) {
        for (int i = 0; i < lenL; i++) {
            printf("%s", friendsList[i]);
            if (i < lenL - 1) {
                printf(" ");
            }
        }
        for (int i = 0; i < lenN; i++) {
            printf(" %s", newFriends[i]);
        }
    } else {
        for (int i = 0; i < lenL; i++) {
            if (strcmp(friendsList[i], S) == 0) {
                found = 1;
                for (int j = 0; j < lenN; j++) {
                    printf("%s", newFriends[j]);
                    if (j < lenN - 1) {
                        printf(" ");
                    }
                }
            }
            printf(" %s", friendsList[i]);
        }
        if (!found) {
            for (int i = 0; i < lenN; i++) {
                printf(" %s", newFriends[i]);
            }
            for (int i = 0; i < lenL; i++) {
                printf(" %s", friendsList[i]);
            }
        }
    }
    printf("\n");
    return 0;
}
