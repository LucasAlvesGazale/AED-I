#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 300

int precedencia(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int ehOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixaParaPosfixa(char *infixa, char *posfixa) {
    char pilha[MAX];
    int topo = -1;
    int k = 0;

    for (int i = 0; infixa[i] != '\0'; i++) {
        char c = infixa[i];

        if (isalnum(c)) {
            posfixa[k++] = c;
        }
        else if (c == '(') {
            pilha[++topo] = c;
        }
        else if (c == ')') {
            while (topo >= 0 && pilha[topo] != '(') {
                posfixa[k++] = pilha[topo--];
            }
            topo--;
        }
        else if (ehOperador(c)) {
            while (topo >= 0 && precedencia(pilha[topo]) >= precedencia(c)) {
                posfixa[k++] = pilha[topo--];
            }
            pilha[++topo] = c;
        }
    }

    while (topo >= 0) {
        posfixa[k++] = pilha[topo--];
    }

    posfixa[k] = '\0';
}

int main() {
    int N;
    scanf("%d", &N);
    
    while (N--) {
        char infixa[MAX], posfixa[MAX];
        scanf("%s", infixa);
        infixaParaPosfixa(infixa, posfixa);
        printf("%s\n", posfixa);
    }

    return 0;
}
