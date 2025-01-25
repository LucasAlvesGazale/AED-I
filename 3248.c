#include <stdio.h>

#define MAX 100005

long long fenwick[MAX];

// Função para somar valores até o índice idx na árvore Fenwick
long long sum(long long idx) {
    long long result = 0;
    while (idx > 0) {
        result += fenwick[idx];
        idx -= idx & -idx;  // Move para o pai na árvore
    }
    return result;
}

// Função para adicionar valor ao índice idx na árvore Fenwick
void add(long long idx, long long value) {
    while (idx < MAX) {
        fenwick[idx] += value;
        idx += idx & -idx;  // Move para o próximo nó
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n+1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    long long count = 0;
    long long leftCount[MAX] = {0};
    long long rightCount[MAX] = {0};
    
    // Primeira passagem: contar números maiores à esquerda
    for (int j = 1; j <= n; j++) {
        // Contar quantos números maiores que arr[j] já apareceram
        if (arr[j] < MAX) {
            leftCount[j] = sum(MAX - 1) - sum(arr[j]);
        }
        
        // Atualizar a Fenwick Tree com arr[j]
        add(arr[j], 1);
    }
    
    // Resetando a árvore Fenwick para a segunda passagem
    for (int i = 0; i < MAX; i++) {
        fenwick[i] = 0;
    }
    
    // Segunda passagem: contar números menores à direita
    for (int j = n; j >= 1; j--) {
        // Contar quantos números menores que arr[j] apareceram
        if (arr[j] > 1) {
            rightCount[j] = sum(arr[j] - 1);
        }
        
        // Atualizar a Fenwick Tree com arr[j]
        add(arr[j], 1);
    }
    
    // Contar o número total de triplas invertidas
    for (int j = 1; j <= n; j++) {
        count += leftCount[j] * rightCount[j];
    }

    printf("%lld\n", count);
    
    return 0;
}
