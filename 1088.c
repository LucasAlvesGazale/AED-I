#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int temp[], int left, int mid, int right, int *count) {
    int i, j, k;
    i = left; // índice para a sublista esquerda
    j = mid;  // índice para a sublista direita
    k = left; // índice para a lista temporária

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            *count += (mid - i); // conta o número de inversões
        }
    }

    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int temp[], int left, int right, int *count) {
    int mid;
    if (right > left) {
        mid = (right + left) / 2;

        mergeSort(arr, temp, left, mid, count);
        mergeSort(arr, temp, mid + 1, right, count);

        merge(arr, temp, left, mid + 1, right, count);
    }
}

int main() {
    int N;
    
    while (scanf("%d", &N) && N != 0) {
        int *arr = (int *)malloc(N * sizeof(int));
        int *temp = (int *)malloc(N * sizeof(int));
        int count = 0;

        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        mergeSort(arr, temp, 0, N - 1, &count);

        if (count % 2 == 0) {
            printf("Carlos\n");
        } else {
            printf("Marcelo\n");
        }

        free(arr);
        free(temp);
    }

    return 0;
}
