#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int arr[], int n) {
    int i, j, temp, swaps = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
    return swaps;
}

int main() {
    int M, L;
    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        scanf("%d", &L);
        int wagons[L];
        for (int j = 0; j < L; j++) {
            scanf("%d", &wagons[j]);
        }
        int swapCount = bubbleSort(wagons, L);
        printf("Optimal train swapping takes %d swaps.\n", swapCount);
    }

    return 0;
}
