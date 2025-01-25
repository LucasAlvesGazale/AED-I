#include <stdio.h>

int main() {
    double valor;
    scanf("%lf", &valor);

    // Convertemos o valor para centavos, para evitar problemas com ponto flutuante
    int valor_int = (int)(valor * 100 + 0.5); // Multiplicamos por 100 e arredondamos

    // Notas e moedas em centavos
    int notas[6] = {10000, 5000, 2000, 1000, 500, 200};
    double moedas[6] = {100, 50, 25, 10, 5, 1}; // Moedas em centavos, pois já estamos usando centavos

    printf("NOTAS:\n");
    // Decompor o valor em notas (convertido para centavos)
    for (int i = 0; i < 6; i++) {
        int quantidade = valor_int / notas[i];
        valor_int %= notas[i]; // Atualiza o valor restante após retirar as notas
        printf("%d nota(s) de R$ %.2f\n", quantidade, notas[i] / 100.0);
    }

    printf("MOEDAS:\n");
    // Decompor o valor em moedas
    for (int i = 0; i < 6; i++) {
        int quantidade = valor_int / (int)(moedas[i]);
        valor_int %= (int)(moedas[i]); // Atualiza o valor restante após retirar as moedas
        printf("%d moeda(s) de R$ %.2f\n", quantidade, moedas[i] / 100.0);
    }

    return 0;
}
