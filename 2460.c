#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int N, M;
    scanf("%d", &N);

    int *fila = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }

    scanf("%d", &M);

    int *saida = (int *)malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) {
        scanf("%d", &saida[i]);
    }

    int *saiu = (int *)calloc(MAX + 1, sizeof(int));

    for (int i = 0; i < M; i++) {
        saiu[saida[i]] = 1;
    }

    int primeiro = 1;
    for (int i = 0; i < N; i++) {
        if (!saiu[fila[i]]) {
            if (!primeiro) {
                printf(" ");
            }
            printf("%d", fila[i]);
            primeiro = 0;
        }
    }

    printf("\n");

    free(fila);
    free(saida);
    free(saiu);

    return 0;
}
