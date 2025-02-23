#include <stdio.h>
#include <math.h>

int main() {
    double A, B, C, aux;

    scanf("%lf %lf %lf", &A, &B, &C);

    if (A < B) { aux = A; A = B; B = aux; }
    if (A < C) { aux = A; A = C; C = aux; }
    if (B < C) { aux = B; B = C; C = aux; }

    if (A >= B + C) {
        printf("NAO FORMA TRIANGULO\n");
    } else {
        if (A * A == B * B + C * C) {
            printf("TRIANGULO RETANGULO\n");
        }
        if (A * A > B * B + C * C) {
            printf("TRIANGULO OBTUSANGULO\n");
        }
        if (A * A < B * B + C * C) {
            printf("TRIANGULO ACUTANGULO\n");
        }
        if (A == B && B == C) {
            printf("TRIANGULO EQUILATERO\n");
        }
        if ((A == B && B != C) || (A == C && C != B) || (B == C && C != A)) {
            printf("TRIANGULO ISOSCELES\n");
        }
    }

    return 0;
}
