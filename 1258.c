#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[61];
    char cor[10];
    char tamanho;
} Camiseta;

int compare(const void *a, const void *b) {
    Camiseta *c1 = (Camiseta *)a;
    Camiseta *c2 = (Camiseta *)b;

    int corCmp = strcmp(c1->cor, c2->cor);
    if (corCmp == 0) {
        if (c1->tamanho == c2->tamanho) {
            return strcmp(c1->nome, c2->nome);
        }
        return c2->tamanho - c1->tamanho;
    }
    return corCmp;
}

int main() {
    int N;
    int first_case = 1;

    while (scanf("%d", &N) && N != 0) {
        if (!first_case) {
            printf("\n");
        }
        first_case = 0;

        Camiseta camisetas[N];
        for (int i = 0; i < N; i++) {
            scanf(" %[^\n]s", camisetas[i].nome); 
            scanf("%s %c", camisetas[i].cor, &camisetas[i].tamanho); 
        }

        qsort(camisetas, N, sizeof(Camiseta), compare);

        for (int i = 0; i < N; i++) {
            printf("%s %c %s\n", camisetas[i].cor, camisetas[i].tamanho, camisetas[i].nome);
        }
    }

    return 0;
}
