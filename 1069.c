#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    while (N--) {
        char linha[1001];
        scanf("%s", linha);
        
        int diamantes = 0;
        int abertos = 0;
        
        for (int i = 0; linha[i] != '\0'; i++) {
            if (linha[i] == '<') {
                abertos++;  
            } else if (linha[i] == '>') {
                if (abertos > 0) {
                    diamantes++;  
                    abertos--;  
                }
            }
        }
        
        printf("%d\n", diamantes);  
    }
    
    return 0;
}
