#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return abs(a);
}

void simplificar(int *numerador, int *denominador) {
    int divisor = mdc(*numerador, *denominador);
    *numerador /= divisor;
    *denominador /= divisor;
    if (*denominador < 0) {
        *numerador = -*numerador;
        *denominador = -*denominador;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int n1, d1, n2, d2, numerador, denominador;
        char operador;

        scanf("%d / %d %c %d / %d", &n1, &d1, &operador, &n2, &d2);

        switch (operador) {
            case '+':
                numerador = (n1 * d2) + (n2 * d1);
                denominador = d1 * d2;
                break;
            case '-':
                numerador = (n1 * d2) - (n2 * d1);
                denominador = d1 * d2;
                break;
            case '*':
                numerador = n1 * n2;
                denominador = d1 * d2;
                break;
            case '/':
                numerador = n1 * d2;
                denominador = n2 * d1;
                break;
        }

        printf("%d/%d = ", numerador, denominador);

        simplificar(&numerador, &denominador);

        printf("%d/%d\n", numerador, denominador);
    }

    return 0;
}
