#include <stdio.h>
#include <stdlib.h>

int main()
{
    int instancia;
    int V;
    int cont;
    int vetor[9];
    scanf("%d", &instancia);
    int matriz[instancia][9][9];
    for (int k = 0; k<instancia; k++){
        for (int i = 0; i<9; i++){
            for (int j = 0; j<9; j++){
                scanf("%d", &matriz[k][i][j]);
            }
        }
    }
    for (int k = 0; k<instancia; k++){
        V=0;
        //verificação de linhas e colunas
        for (int i = 0; i<9; i++){
            for (int j = 0; j<8; j++){
                for (int q = j+1; q<9; q++){
                    //Verifica se há repetição na linha
                    if (matriz[k][i][j]==matriz[k][i][q]){
                        V=V+1;
                        break;
                    }
                    //verifica se há repetição nas colunas
                    if (matriz[k][j][i]==matriz[k][q][i]){
                        V=V+1;
                        break;
                    }
                }
                if (V!=0){
                break;
                }
            }
            if (V!=0){
                break;
            }
        }

        //Verificação dos blocos de 9 numeros
        //divisão da matriz 9x9 em 9 matrizes 3x3
        for (int x = 0; x<3; x++){
            for (int y = 0; y<3; y++){
                cont=0;
                for (int i=3*x; i<3*(x+1); i++){
                    //Transforma a matriz de um bloco 3x3 em um vetor afim de facilitar a comparação
                    for (int j=3*y; j<3*(y+1); j++){
                        vetor[cont]=matriz[k][i][j];
                        cont=cont+1;
                    }
                }
             //Verficação de repetição no vetor
                for (int q=0; q<8; q++){
                    for (int r=q+1; r<9; r++){
                        if (vetor[q]==vetor[r]){
                            V=V+1;
                            break;
                        }
                    }
                }
            }
        }//final da verificação por blocos 3x3

         printf("Instancia %d\n", k + 1);
         if (V==0){
            printf("SIM\n\n");
         }
         else {
            printf("NAO\n\n");
         }

    }
    return 0;
}
