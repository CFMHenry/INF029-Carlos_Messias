#include <stdio.h>

#define TAM 3

void IniciarTabuleiro(char tabuleiro[TAM][TAM]);
void MostrarTabuleiro(char tabuleiro[TAM][TAM]);

int ConverterLinha(char letra);
int ConverterColuna(char numero);

int JogadaValida(char tabuleiro[TAM][TAM], int linha, int coluna);

void FazerJogada(char tabuleiro[TAM][TAM], int jogador);

int VerificarLinhas(char tabuleiro[TAM][TAM]);
int VerificarColunas(char tabuleiro[TAM][TAM]);
int VerificarDiagonais(char tabuleiro[TAM][TAM]);

int VerificarVencedor(char tabuleiro[TAM][TAM]);

int TabuleiroCheio(char tabuleiro[TAM][TAM]);

int main()
{
    char tabuleiro[TAM][TAM];

    int jogador = 1;
    int vencedor = 0;

    IniciarTabuleiro(tabuleiro);

    while(vencedor == 0 && !TabuleiroCheio(tabuleiro)){

        MostrarTabuleiro(tabuleiro);

        FazerJogada(tabuleiro, jogador);

        vencedor = VerificarVencedor(tabuleiro);

        if(jogador == 1){
            jogador = 2;
        }
        else{
            jogador = 1;
        }
    }

    MostrarTabuleiro(tabuleiro);

    if(vencedor == 1){
        printf("Jogador 1 venceu!\n");
    }
    else if(vencedor == 2){
        printf("Jogador 2 venceu!\n");
    }
    else{
        printf("Empate!\n");
    }

    return 0;
}

void IniciarTabuleiro(char tabuleiro[TAM][TAM])
{
    int iCont, jCont;

    for(iCont = 0; iCont < TAM; iCont++){
        for(jCont = 0; jCont < TAM; jCont++){

            tabuleiro[iCont][jCont] = ' ';
        }
    }
}

void MostrarTabuleiro(char tabuleiro[TAM][TAM])
{
    int iCont, jCont;

    printf("\n   1   2   3\n");

    for(iCont = 0; iCont < TAM; iCont++){

        printf(" %c ", 'A' + iCont);

        for(jCont = 0; jCont < TAM; jCont++){

            printf(" %c ", tabuleiro[iCont][jCont]);

            if(jCont < TAM - 1){
                printf("|");
            }
        }

        printf("\n");

        if(iCont < TAM - 1){
            printf("   ---|---|---\n");
        }
    }

    printf("\n");
}

int ConverterLinha(char letra)
{
    if(letra == 'A' || letra == 'a'){
        return 0;
    }

    if(letra == 'B' || letra == 'b'){
        return 1;
    }

    if(letra == 'C' || letra == 'c'){
        return 2;
    }

    return -1;
}

int ConverterColuna(char numero)
{
    if(numero >= '1' && numero <= '3'){
        return numero - '1';
    }

    return -1;
}

int JogadaValida(char tabuleiro[TAM][TAM], int linha, int coluna)
{
    if(linha < 0 || linha >= TAM){
        return 0;
    }

    if(coluna < 0 || coluna >= TAM){
        return 0;
    }

    if(tabuleiro[linha][coluna] != ' '){
        return 0;
    }

    return 1;
}

void FazerJogada(char tabuleiro[TAM][TAM], int jogador)
{
    char jogada[3];

    int linha;
    int coluna;

    char simbolo;

    if(jogador == 1){
        simbolo = 'X';
    }
    else{
        simbolo = 'O';
    }

    do{

        printf("Jogador %d, informe sua jogada: ", jogador);

        scanf("%s", jogada);

        linha = ConverterLinha(jogada[0]);

        coluna = ConverterColuna(jogada[1]);

        if(!JogadaValida(tabuleiro, linha, coluna)){
            printf("Jogada invalida!\n");
        }

    }while(!JogadaValida(tabuleiro, linha, coluna));

    tabuleiro[linha][coluna] = simbolo;
}

int VerificarLinhas(char tabuleiro[TAM][TAM])
{
    int iCont;

    for(iCont = 0; iCont < TAM; iCont++){

        if(tabuleiro[iCont][0] != ' ' &&
           tabuleiro[iCont][0] == tabuleiro[iCont][1] &&
           tabuleiro[iCont][1] == tabuleiro[iCont][2]){

            if(tabuleiro[iCont][0] == 'X'){
                return 1;
            }
            else{
                return 2;
            }
        }
    }

    return 0;
}

int VerificarColunas(char tabuleiro[TAM][TAM])
{
    int iCont;

    for(iCont = 0; iCont < TAM; iCont++){

        if(tabuleiro[0][iCont] != ' ' &&
           tabuleiro[0][iCont] == tabuleiro[1][iCont] &&
           tabuleiro[1][iCont] == tabuleiro[2][iCont]){

            if(tabuleiro[0][iCont] == 'X'){
                return 1;
            }
            else{
                return 2;
            }
        }
    }

    return 0;
}

int VerificarDiagonais(char tabuleiro[TAM][TAM])
{
    if(tabuleiro[0][0] != ' ' &&
       tabuleiro[0][0] == tabuleiro[1][1] &&
       tabuleiro[1][1] == tabuleiro[2][2]){

        if(tabuleiro[0][0] == 'X'){
            return 1;
        }
        else{
            return 2;
        }
    }

    if(tabuleiro[0][2] != ' ' &&
       tabuleiro[0][2] == tabuleiro[1][1] &&
       tabuleiro[1][1] == tabuleiro[2][0]){

        if(tabuleiro[0][2] == 'X'){
            return 1;
        }
        else{
            return 2;
        }
    }

    return 0;
}

int VerificarVencedor(char tabuleiro[TAM][TAM])
{
    int vencedor;

    vencedor = VerificarLinhas(tabuleiro);

    if(vencedor != 0){
        return vencedor;
    }

    vencedor = VerificarColunas(tabuleiro);

    if(vencedor != 0){
        return vencedor;
    }

    vencedor = VerificarDiagonais(tabuleiro);

    return vencedor;
}

int TabuleiroCheio(char tabuleiro[TAM][TAM])
{
    int iCont, jCont;

    for(iCont = 0; iCont < TAM; iCont++){
        for(jCont = 0; jCont < TAM; jCont++){

            if(tabuleiro[iCont][jCont] == ' '){
                return 0;
            }
        }
    }

    return 1;
}