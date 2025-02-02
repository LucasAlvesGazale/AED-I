#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_LENGTH 201

typedef struct {
    char palavra[MAX_LENGTH];
} Palavra;

int comparar(const void *a, const void *b) {
    return strcmp(((Palavra *)a)->palavra, ((Palavra *)b)->palavra);
}

int main() {
    Palavra dicionario[MAX_WORDS];
    int num_palavras = 0;
    char linha[MAX_LENGTH], palavra[MAX_LENGTH];
    int i, j;
    char c;

    while (fgets(linha, MAX_LENGTH, stdin)) {
        i = 0;
        while (linha[i] != '\0') {
            j = 0;
            while (isalpha(linha[i])) {
                palavra[j++] = tolower(linha[i++]);
            }
            palavra[j] = '\0';
            if (j > 0) {
                int encontrada = 0;
                for (int k = 0; k < num_palavras; k++) {
                    if (strcmp(dicionario[k].palavra, palavra) == 0) {
                        encontrada = 1;
                        break;
                    }
                }
                if (!encontrada && num_palavras < MAX_WORDS) {
                    strcpy(dicionario[num_palavras++].palavra, palavra);
                }
            }
            if (linha[i] != '\0') {
                i++;
            }
        }
    }

    qsort(dicionario, num_palavras, sizeof(Palavra), comparar);

    for (int i = 0; i < num_palavras; i++) {
        printf("%s\n", dicionario[i].palavra);
    }

    return 0;
}
