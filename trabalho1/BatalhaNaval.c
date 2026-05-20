//Questão 9 - Batalha Naval
//Estudante: Carlos Henrique Ferreira Messias / matricula: 20252160036
#include <stdio.h>

#define TAM 10
#define QTD_BARCOS 5

void IniciarTabuleiro(char tabuleiro[TAM][TAM]);

void MostrarTabuleiro(char tabuleiro[TAM][TAM], int mostrarNavio);

int ConverterLinha(char letra);

int ConverterColuna(char posicao[]);

int PosicaoValida(int linha, int coluna);

int PodePosicionarBarco(char tabuleiro[TAM][TAM], int linha, int coluna, int tamanhoBarco, char direcao);

void PosicionarBarco(char tabuleiro[TAM][TAM], int tamanhoBarco);

void PosicionarFrota(char tabuleiro[TAM][TAM]);

void FazerJogada(char tabuleiro[TAM][TAM]);

int ContarNavios(char tabuleiro[TAM][TAM]);


int main()
{
    char tabuleiroJogador1[TAM][TAM];
    char tabuleiroJogador2[TAM][TAM];

    int jogadorAtual = 1;

    IniciarTabuleiro(tabuleiroJogador1);

    IniciarTabuleiro(tabuleiroJogador2);

    printf("=== Jogador 1 ===\n");

    PosicionarFrota(tabuleiroJogador1);

    printf("\n=== Jogador 2 ===\n");

    PosicionarFrota(tabuleiroJogador2);

    while(ContarNavios(tabuleiroJogador1) > 0 &&
          ContarNavios(tabuleiroJogador2) > 0){

        if(jogadorAtual == 1){

            printf("\nTurno Jogador 1\n");

            MostrarTabuleiro(tabuleiroJogador2, 0);

            FazerJogada(tabuleiroJogador2);

            jogadorAtual = 2;
        }
        else{

            printf("\nTurno Jogador 2\n");

            MostrarTabuleiro(tabuleiroJogador1, 0);

            FazerJogada(tabuleiroJogador1);

            jogadorAtual = 1;
        }
    }

    if(ContarNavios(tabuleiroJogador1) == 0){
        printf("\nJogador 2 venceu!\n");
    }
    else{
        printf("\nJogador 1 venceu!\n");
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

void MostrarTabuleiro(char tabuleiro[TAM][TAM], int mostrarNavio)
{
    int iCont, jCont;

    printf("\n    1  2  3  4  5  6  7  8  9 10\n");

    for(iCont = 0; iCont < TAM; iCont++){

        printf("%c ", 'A' + iCont);

        for(jCont = 0; jCont < TAM; jCont++){

            if(tabuleiro[iCont][jCont] == 'N' && !mostrarNavio){
                printf("[ ]");
            }
            else{
                printf("[%c]", tabuleiro[iCont][jCont]);
            }
        }

        printf("\n");
    }

    printf("\n");
}

int ConverterLinha(char letra)
{
    if(letra >= 'A' && letra <= 'J'){
        return letra - 'A';
    }

    if(letra >= 'a' && letra <= 'j'){
        return letra - 'a';
    }

    return -1;
}

int ConverterColuna(char posicao[])
{
    int coluna = 0;
    int iCont = 1;

    while(posicao[iCont] != '\0'){

        coluna = coluna * 10;

        coluna = coluna + (posicao[iCont] - '0');

        iCont++;
    }

    coluna--;

    if(coluna >= 0 && coluna < TAM){
        return coluna;
    }

    return -1;
}

int PosicaoValida(int linha, int coluna)
{
    if(linha < 0 || linha >= TAM){
        return 0;
    }

    if(coluna < 0 || coluna >= TAM){
        return 0;
    }

    return 1;
}

int PodePosicionarBarco(char tabuleiro[TAM][TAM], int linha, int coluna, int tamanhoBarco, char direcao)
{
    int iCont;

    for(iCont = 0; iCont < tamanhoBarco; iCont++){

        if(direcao == 'H'){

            if(!PosicaoValida(linha, coluna + iCont)){
                return 0;
            }

            if(tabuleiro[linha][coluna + iCont] != ' '){
                return 0;
            }
        }
        else{

            if(!PosicaoValida(linha + iCont, coluna)){
                return 0;
            }

            if(tabuleiro[linha + iCont][coluna] != ' '){
                return 0;
            }
        }
    }

    return 1;
}

void PosicionarBarco(char tabuleiro[TAM][TAM], int tamanhoBarco)
{
    char posicao[5];

    char direcao;

    int linha;
    int coluna;

    int iCont;

    do{

        printf("Informe a posicao do barco tamanho %d: ", tamanhoBarco);

        scanf("%s", posicao);

        printf("Informe a direcao H ou V: ");

        scanf(" %c", &direcao);

        linha = ConverterLinha(posicao[0]);

        coluna = ConverterColuna(posicao);

        if(direcao >= 'a' && direcao <= 'z'){
            direcao = direcao - 32;
        }

        if(!PodePosicionarBarco(tabuleiro, linha, coluna, tamanhoBarco, direcao)){
            printf("Posicao invalida!\n");
        }

    }while(!PodePosicionarBarco(tabuleiro, linha, coluna, tamanhoBarco, direcao));

    for(iCont = 0; iCont < tamanhoBarco; iCont++){

        if(direcao == 'H'){
            tabuleiro[linha][coluna + iCont] = 'N';
        }
        else{
            tabuleiro[linha + iCont][coluna] = 'N';
        }
    }
}

void PosicionarFrota(char tabuleiro[TAM][TAM])
{
    PosicionarBarco(tabuleiro, 4);

    PosicionarBarco(tabuleiro, 3);

    PosicionarBarco(tabuleiro, 1);

    PosicionarBarco(tabuleiro, 1);

    PosicionarBarco(tabuleiro, 1);
}

void FazerJogada(char tabuleiro[TAM][TAM])
{
    char posicao[5];

    int linha;
    int coluna;

    printf("Informe a posicao do tiro: ");

    scanf("%s", posicao);

    linha = ConverterLinha(posicao[0]);

    coluna = ConverterColuna(posicao);

    if(!PosicaoValida(linha, coluna)){

        printf("Posicao invalida!\n");

        return;
    }

    if(tabuleiro[linha][coluna] == 'N'){

        tabuleiro[linha][coluna] = '0';

        printf("Acertou um navio!\n");
    }
    else if(tabuleiro[linha][coluna] == ' '){

        tabuleiro[linha][coluna] = 'X';

        printf("Errou o tiro!\n");
    }
    else{

        printf("Posicao ja utilizada!\n");
    }
}

int ContarNavios(char tabuleiro[TAM][TAM])
{
    int iCont, jCont;

    int qtdNavios = 0;

    for(iCont = 0; iCont < TAM; iCont++){
        for(jCont = 0; jCont < TAM; jCont++){

            if(tabuleiro[iCont][jCont] == 'N'){
                qtdNavios++;
            }
        }
    }

    return qtdNavios;
}