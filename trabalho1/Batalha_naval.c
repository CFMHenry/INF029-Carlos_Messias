#include <stdio.h>


#define QTD_BARCOS 5

void IniciarTabuleiro(char tabuleiro[10][10]);

void MostrarTabuleiro(char tabuleiro[10][10], int mostrarNavio);

int ConverterLinha(char letra);

int ConverterColuna(char posicao[]);

int PosicaoValida(int linha, int coluna);

int PodePosicionarBarco(char tabuleiro[10][10], int linha, int coluna, int tamanhoBarco, char direcao);

void PosicionarBarco(char tabuleiro[10][10], int tamanhoBarco);

void PosicionarFrota(char tabuleiro[10][10]);

void FazerJogada(char tabuleiro[10][10]);

int ContarNavios(char tabuleiro[10][10]);


int main()
{
    char tabuleiroJogador1[10][10];
    char tabuleiroJogador2[10][10];

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

void IniciarTabuleiro(char tabuleiro[10][10])
{
    int iCont, jCont;

    for(iCont = 0; iCont < 10; iCont++){
        for(jCont = 0; jCont < 10; jCont++){

            tabuleiro[iCont][jCont] = ' ';
        }
    }
}

void MostrarTabuleiro(char tabuleiro[10][10], int mostrarNavio)
{
    int iCont, jCont;

    printf("\n    1  2  3  4  5  6  7  8  9 10\n");

    for(iCont = 0; iCont < 10; iCont++){

        printf("%c ", 'A' + iCont);

        for(jCont = 0; jCont < 10; jCont++){

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

    if(coluna >= 0 && coluna < 10){
        return coluna;
    }

    return -1;
}

int PosicaoValida(int linha, int coluna)
{
    if(linha < 0 || linha >= 10){
        return 0;
    }

    if(coluna < 0 || coluna >= 10){
        return 0;
    }

    return 1;
}

int PodePosicionarBarco(char tabuleiro[10][10], int linha, int coluna, int tamanhoBarco, char direcao)
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

void PosicionarBarco(char tabuleiro[10][10], int tamanhoBarco)
{
    char posicao[5];

    char direcao;

    int linha;
    int coluna;

    int iCont;

 
    MostrarTabuleiro(tabuleiro, 1);

    do{
        
        printf("Informe a posicao do barco tamanho %d (ex: A5): ", tamanhoBarco);

        scanf("%s", posicao);

        printf("Informe a direcao H (horizontal) ou V (vertical): ");

        scanf(" %c", &direcao);

        linha = ConverterLinha(posicao[0]);

        coluna = ConverterColuna(posicao);

        if(direcao >= 'a' && direcao <= 'z'){
            direcao = direcao - 32;
        }

        if(!PodePosicionarBarco(tabuleiro, linha, coluna, tamanhoBarco, direcao)){
            printf("Posicao invalida! Tente novamente.\n");
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

   
    printf("Barco de tamanho %d posicionado! Tabuleiro atualizado:\n", tamanhoBarco);
    MostrarTabuleiro(tabuleiro, 1);
}

void PosicionarFrota(char tabuleiro[10][10])
{
    int qtdBarcos = QTD_BARCOS;
    int iCont;

    printf("Posicione seus %d barcos:\n", qtdBarcos);
    printf("  - 1 barco de tamanho 4\n");
    printf("  - 1 barco de tamanho 3\n");
    printf("  - 3 barcos de tamanho 1\n\n");

    PosicionarBarco(tabuleiro, 4);

    PosicionarBarco(tabuleiro, 3);

    PosicionarBarco(tabuleiro, 1);

    PosicionarBarco(tabuleiro, 1);

    PosicionarBarco(tabuleiro, 1);


    for(iCont = 5; iCont < qtdBarcos; iCont++){
        PosicionarBarco(tabuleiro, 2);
    }
}

void FazerJogada(char tabuleiro[10][10])
{
    char posicao[5];

    int linha;
    int coluna;

    printf("Informe a posicao do tiro (ex: A5): ");

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

int ContarNavios(char tabuleiro[10][10])
{
    int iCont, jCont;

    int qtdNavios = 0;

    for(iCont = 0; iCont < 10; iCont++){
        for(jCont = 0; jCont < 10; jCont++){

            if(tabuleiro[iCont][jCont] == 'N'){
                qtdNavios++;
            }
        }
    }

    return qtdNavios;
}
