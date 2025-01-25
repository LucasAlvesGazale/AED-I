#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);  // Lê o número de segundos
    
    int horas = N / 3600;  // Divide por 3600 para obter as horas
    int minutos = (N % 3600) / 60;  // O resto da divisão por 3600, depois divide por 60 para os minutos
    int segundos = N % 60;  // O resto da divisão por 60 são os segundos restantes
    
    // Imprime no formato horas:minutos:segundos
    printf("%d:%d:%d\n", horas, minutos, segundos);
    
    return 0;
}
