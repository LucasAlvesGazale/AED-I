#include <stdio.h>

int main() {
    double valor;
    scanf("%lf", &valor);
    int valor_int = (int)(valor * 100 + 0.5); 
    int notas[6] = {10000, 5000, 2000, 1000, 500, 200};
    double moedas[6] = {100, 50, 25, 10, 5, 1}; 
    printf("NOTAS:\n");
    for (int i = 0; i < 6; i++) {
        int quantidade = valor_int / notas[i];
        valor_int %= notas[i]; 
        printf("%d nota(s) de R$ %.2f\n", quantidade, notas[i] / 100.0);
    }

    printf("MOEDAS:\n");
    for (int i = 0; i < 6; i++) {
        int quantidade = valor_int / (int)(moedas[i]);
        valor_int %= (int)(moedas[i]); 
        printf("%d moeda(s) de R$ %.2f\n", quantidade, moedas[i] / 100.0);
    }

    return 0;
}
