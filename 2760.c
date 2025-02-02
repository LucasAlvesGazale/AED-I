#include <stdio.h>
#include <string.h>

int main() {
    char A[101], B[101], C[101];

    // Lê as três frases
    fgets(A, 101, stdin);
    fgets(B, 101, stdin);
    fgets(C, 101, stdin);

    // Remove o '\n' do final de cada string
    A[strcspn(A, "\n")] = '\0';
    B[strcspn(B, "\n")] = '\0';
    C[strcspn(C, "\n")] = '\0';

    // Imprime as frases na ordem original
    printf("%s%s%s\n", A, B, C);

    // Imprime as frases na ordem B, C, A
    printf("%s%s%s\n", B, C, A);

    // Imprime as frases na ordem C, A, B
    printf("%s%s%s\n", C, A, B);

    // Imprime os primeiros 10 caracteres de cada frase na ordem original
    printf("%.10s%.10s%.10s\n", A, B, C);

    return 0;
}
