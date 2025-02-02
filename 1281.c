#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[51];
    double preco;
} Produto;

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int M;
        scanf("%d", &M);

        Produto produtos[M];

        for (int i = 0; i < M; i++) {
            scanf("%s %lf", produtos[i].nome, &produtos[i].preco);
        }

        int P;
        scanf("%d", &P);

        double total = 0.0;
        for (int i = 0; i < P; i++) {
            char produtoComprado[51];
            int quantidade;
            scanf("%s %d", produtoComprado, &quantidade);

            for (int j = 0; j < M; j++) {
                if (strcmp(produtoComprado, produtos[j].nome) == 0) {
                    total += produtos[j].preco * quantidade;
                    break;
                }
            }
        }

        printf("R$ %.2lf\n", total);
    }

    return 0;
}
