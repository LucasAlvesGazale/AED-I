#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    return strlen(*(char**)a) - strlen(*(char**)b);
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();  // Para capturar o '\n' após o número de casos

    for (int i = 0; i < N; i++) {
        char* words[50];
        int count = 0;
        char line[1000];

        // Lê a linha completa
        fgets(line, sizeof(line), stdin);

        // Divide a linha em palavras
        char* token = strtok(line, " \n");
        while (token != NULL) {
            words[count] = malloc(strlen(token) + 1);
            strcpy(words[count], token);
            count++;
            token = strtok(NULL, " \n");
        }

        // Ordena as palavras com base no comprimento, de forma crescente
        qsort(words, count, sizeof(char*), compare);

        // Imprime as palavras ordenadas
        for (int j = 0; j < count; j++) {
            if (j > 0) printf(" ");
            printf("%s", words[j]);
            free(words[j]);
        }
        printf("\n");
    }

    return 0;
}
