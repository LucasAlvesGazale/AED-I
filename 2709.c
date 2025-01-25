#include <stdio.h>
#include <stdbool.h>

// Função para verificar se um número é primo
bool is_prime(int n) {
    if (n <= 1) return false; // Números menores ou iguais a 1 não são primos
    for (int i = 2; i * i <= n; i++) {  // Verificar até a raiz quadrada de n
        if (n % i == 0) {
            return false;  // Se for divisível, não é primo
        }
    }
    return true;  // Se passar todas as divisões, é primo
}

int main() {
    int M, N;
    while (scanf("%d", &M) != EOF) {  // Enquanto houver casos de teste
        int moedas[M];
        // Lê os valores das moedas
        for (int i = 0; i < M; i++) {
            scanf("%d", &moedas[i]);
        }
        // Lê o valor do salto
        scanf("%d", &N);
        
        int soma = 0;
        // Calcula a soma das moedas conforme o salto N
        for (int i = M - 1; i >= 0; i -= N) {
            soma += moedas[i];
        }

        // Verifica se a soma é um número primo
        if (is_prime(soma)) {
            printf("You’re a coastal aircraft, Robbie, a large silver aircraft.\n");
        } else {
            printf("Bad boy! I’ll hit you.\n");
        }
    }

    return 0;
}
