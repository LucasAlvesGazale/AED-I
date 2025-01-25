#include <stdio.h>
#include <stdlib.h>

int compare_asc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compare_desc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N;
    scanf("%d", &N);
    
    int pares[100000], impares[100000];
    int count_pares = 0, count_impares = 0;

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        
        if (num % 2 == 0) {
            pares[count_pares++] = num;
        } else {
            impares[count_impares++] = num;
        }
    }

    qsort(pares, count_pares, sizeof(int), compare_asc);
    qsort(impares, count_impares, sizeof(int), compare_desc);

    for (int i = 0; i < count_pares; i++) {
        printf("%d\n", pares[i]);
    }

    for (int i = 0; i < count_impares; i++) {
        printf("%d\n", impares[i]);
    }

    return 0;
}
