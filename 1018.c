#include <stdio.h>

int main() {
    int N;
    
    // Leitura do valor inteiro
    scanf("%d", &N);
    
    // Exibindo o valor inicial
    printf("%d\n", N);
    
    // Definindo os valores das notas
    int notas[] = {100, 50, 20, 10, 5, 2, 1};
    
    // Para cada tipo de nota, calculamos a quantidade de notas
    for (int i = 0; i < 7; i++) {
        int quantidade = N / notas[i];  // Calcula a quantidade de notas de valor notas[i]
        N %= notas[i];  // Atualiza N para o restante após a divisão
        
        // Exibe o resultado no formato solicitado
        printf("%d nota(s) de R$ %d,00\n", quantidade, notas[i]);
    }
    
    return 0;
}
