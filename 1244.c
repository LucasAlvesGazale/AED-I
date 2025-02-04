#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    return strlen(*(char**)a) - strlen(*(char**)b);
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();  

    for (int i = 0; i < N; i++) {
        char* words[50];
        int count = 0;
        char line[1000];

        fgets(line, sizeof(line), stdin);

        char* token = strtok(line, " \n");
        while (token != NULL) {
            words[count] = malloc(strlen(token) + 1);
            strcpy(words[count], token);
            count++;
            token = strtok(NULL, " \n");
        }

        qsort(words, count, sizeof(char*), compare);

        for (int j = 0; j < count; j++) {
            if (j > 0) printf(" ");
            printf("%s", words[j]);
            free(words[j]);
        }
        printf("\n");
    }

    return 0;
}
