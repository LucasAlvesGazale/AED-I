/*
Exercício 1000
Autor: Lucas Alves Gazale
RA: 176565
Data: 13/10/2024
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int NumDias; //Quantidade de dias
    scanf("%d", &NumDias);
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", NumDias/365, (NumDias%365)/30, (NumDias%365)%30);
}
