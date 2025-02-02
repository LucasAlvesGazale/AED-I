#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int N, M;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &M);
        
        int notas[M];
        int notasOrdenadas[M];
        int cont = 0;

        for (int j = 0; j < M; j++) {
            scanf("%d", &notas[j]);
            notasOrdenadas[j] = notas[j];
        }

        qsort(notasOrdenadas, M, sizeof(int), compare);

        for (int j = 0; j < M; j++) {
            if (notas[j] == notasOrdenadas[j]) {
                cont++;
            }
        }

        printf("%d\n", cont);
    }

    return 0;
}
