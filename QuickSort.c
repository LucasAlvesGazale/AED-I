#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM = 500000;

int Separa(int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r];
    j = p;
    for (k = p; k < r; k++) {
        if (v[k] <= c) {
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
    }
    v[r] = v[j];
    v[j] = c;
    return j;
}

void Quicksort(int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = Separa(p, r, v);
        Quicksort(p, j - 1, v);
        Quicksort(j + 1, r, v);
    }
}

int main() {
    clock_t t;
    int vetor[TAM];
    srand((unsigned)time(NULL));

    for (int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    t = clock();
    Quicksort(0, TAM - 1, vetor);
    t = clock() - t;

    printf("Tempo de execução: %.6f segundos\n", ((double)t) / CLOCKS_PER_SEC);
    return 0;
}