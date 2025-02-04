#include <stdio.h>

int main() {
    int h1, m1, h2, m2;
    
    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    
    if (h1 == h2 && m1 == m2) {
        printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
    } else {
        int duracao_minutos = (h2 * 60 + m2) - (h1 * 60 + m1);
        
        if (duracao_minutos < 0) {
            duracao_minutos += 24 * 60;  
        }
        
        int duracao_horas = duracao_minutos / 60;
        int duracao_restante_minutos = duracao_minutos % 60;
        
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracao_horas, duracao_restante_minutos);
    }
    
    return 0;
}
