#include <stdio.h>

int main() {
    int a, b, c, maior;

    scanf("%d %d %d", &a, &b, &c);

    maior = (a > b) ? a : b;
    maior = (maior > c) ? maior : c;

    printf("%d eh o maior\n", maior);

    return 0;
}
