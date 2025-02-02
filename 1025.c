#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, Q, caseNo = 1;

    while (scanf("%d %d", &N, &Q) && (N != 0 && Q != 0)) {
        int marbles[N];
        int queries[Q];

        for (int i = 0; i < N; i++) {
            scanf("%d", &marbles[i]);
        }

        for (int i = 0; i < Q; i++) {
            scanf("%d", &queries[i]);
        }

        qsort(marbles, N, sizeof(int), compare);

        printf("CASE# %d:\n", caseNo++);
        for (int i = 0; i < Q; i++) {
            int query = queries[i];
            int found = 0;

            for (int j = 0; j < N; j++) {
                if (marbles[j] == query) {
                    printf("%d found at %d\n", query, j + 1);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("%d not found\n", query);
            }
        }
    }

    return 0;
}
