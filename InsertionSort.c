#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM = 500000;

void insertion (int v[]) {
    int a, b, x;
    for (b = 1; /*A*/ b < TAM; b++) {
        x = v[b];
        for (a = b-1; a >= 0 && v[a] > x; a--)
            v[a+1] = v[a];
        v[a+1] = x;
    }
}

/*
void bubbleSort (int v[TAM]) {
    int a, b, aux;
    for (a = TAM - 1; a >= 1; a--) {
        for (b = 0; b < a; b++) {
            if (v[b] > v[b + 1]) {
                aux = v[b];
                v[b] = v[b + 1];
                v[b + 1] = aux;
            }
        }
    }
}
*/
int main() {
    clock_t t;
    int vetor[TAM];

    srand((unsigned)time(NULL));

    for (int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    t = clock();
    insertion(vetor);
    t = clock() - t;

    printf("Tempo de execucao: %.6f segundos\n", ((double)t) / CLOCKS_PER_SEC);

    return 0;
}
