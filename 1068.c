#include <stdio.h>

int verificar_parenteses_balanceados(const char* expressao) {
    int contador = 0;
    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            contador++;
        } else if (expressao[i] == ')') {
            contador--;
            if (contador < 0) {
                return 0;
            }
        }
    }
    return contador == 0;
}

int main() {
    char expressao[1001];
    
    while (fgets(expressao, 1001, stdin)) {
        if (verificar_parenteses_balanceados(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
