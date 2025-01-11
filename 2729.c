/*
Exercício 2729
Autor: Lucas Alves Gazale
RA: 176565
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_LEN 21
#define MAX_ITEMS 1000

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N;
    char itens[MAX_ITEMS][MAX_ITEM_LEN];
    char linha[MAX_ITEMS * MAX_ITEM_LEN];

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = '\0';

        char *itens_unicos[MAX_ITEMS];
        int num_itens = 0;

        char *item = strtok(linha, " ");
        while (item != NULL) {
            int duplicado = 0;
            for (int j = 0; j < num_itens; j++) {
                if (strcmp(itens_unicos[j], item) == 0) {
                    duplicado = 1;
                    break;
                }
            }
            if (!duplicado) {
                itens_unicos[num_itens++] = item;
            }
            item = strtok(NULL, " ");
        }

        qsort(itens_unicos, num_itens, sizeof(char *), compare);

        for (int j = 0; j < num_itens; j++) {
            printf("%s", itens_unicos[j]);
            if (j < num_itens - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_LEN 21
#define MAX_ITEMS 1000

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N;
    char itens[MAX_ITEMS][MAX_ITEM_LEN];
    char linha[MAX_ITEMS * MAX_ITEM_LEN];

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = '\0';

        char *itens_unicos[MAX_ITEMS];
        int num_itens = 0;

        char *item = strtok(linha, " ");
        while (item != NULL) {
            int duplicado = 0;
            for (int j = 0; j < num_itens; j++) {
                if (strcmp(itens_unicos[j], item) == 0) {
                    duplicado = 1;
                    break;
                }
            }
            if (!duplicado) {
                itens_unicos[num_itens++] = item;
            }
            item = strtok(NULL, " ");
        }

        qsort(itens_unicos, num_itens, sizeof(char *), compare);

        for (int j = 0; j < num_itens; j++) {
            printf("%s", itens_unicos[j]);
            if (j < num_itens - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
