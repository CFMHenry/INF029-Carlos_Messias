// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo contém exemplos de testes das questões do trabalho.
//  o aluno pode incrementar os testes

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016 - 12/12/2018

// #################################################

#include <stdio.h>
#include <string.h>

//renomeie o arquivo do include abaixo para trabalho1.h
#include "trabalho1.h"

void testSomar();    //função utilizada para testes
void testFatorial(); //função utilizada para testes
void testQ1();
void testQ2Extra();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();
void testQ7();

int main()
{

    //testSomar();
    //testFatorial();
    

    //testSomar();
    //testFatorial();
   
    //testQ1();
    //testQ2();
    testQ2Extra();
    //testQ3();
    //testQ4();
    //testQ5();
    //testQ6();
    //testQ7();
    return 0;
}

int ligado = 0;
void show_log(char *str)
{
    if (ligado)
        printf("###%s###\n", str);
}  

void testSomar()
{
    show_log("testeSomar()");
    printf("%d\n", somar(3, 4) == 7);
    printf("%d\n", somar(-1, -3) == -4);
    printf("%d\n", somar(-6, 6) == 0);
    printf("%d\n", somar(74, 9) == 83);
    printf("%d\n", somar(30, -9) == 21);
    printf("%d\n", somar(-2, 8) == 6);
    printf("%d\n", somar(1000, 99) == 1099);
}

void testFatorial()
{
    show_log("testFatorial()");
    printf("%d\n", fatorial(3) == 6);
    printf("%d\n", fatorial(1) == 1);
    printf("%d\n", fatorial(5) == 120);
}

void testQ1()
{
    show_log("testQ1()");
    char str[11];
    strcpy(str, "31/04/2024");
    printf("%d\n", q1(str) == 0);

    strcpy(str, "29/02/2000");
    printf("%d\n", q1(str) == 1);

    strcpy(str, "29/02/1900");
    printf("%d\n", q1(str) == 0);

    strcpy(str, "1/1/24");
    printf("%d\n", q1(str) == 1);

    strcpy(str, "00/01/2020");
    printf("%d\n", q1(str) == 0);
}

void testQ2Extra()
{
    show_log("testQ2Extra()");
    
    char datainicial[11], datafinal[11];
    DiasMesesAnos dma;

    // teste 1 - diferença simples de 1 dia
    strcpy(datainicial, "31/01/2025");
    strcpy(datafinal, "01/02/2025");

    dma = q2(datainicial, datafinal);

    printf("%d - %d\n", dma.retorno == 1, dma.retorno);
    printf("%d - %d\n", dma.qtdDias == 1, dma.qtdDias);
    printf("%d - %d\n", dma.qtdMeses == 0, dma.qtdMeses);
    printf("%d - %d\n", dma.qtdAnos == 0, dma.qtdAnos);

    // teste 2 - fevereiro em ano bissexto
    strcpy(datainicial, "28/02/2024");
    strcpy(datafinal, "01/03/2024");

    dma = q2(datainicial, datafinal);

    printf("%d - %d\n", dma.retorno == 1, dma.retorno);
    printf("%d - %d\n", dma.qtdDias == 2, dma.qtdDias);
    printf("%d - %d\n", dma.qtdMeses == 0, dma.qtdMeses);
    printf("%d - %d\n", dma.qtdAnos == 0, dma.qtdAnos);

    // teste 3 - virada de ano
    strcpy(datainicial, "10/12/2024");
    strcpy(datafinal, "05/01/2025");

    dma = q2(datainicial, datafinal);

    printf("%d - %d\n", dma.retorno == 1, dma.retorno);
    printf("%d - %d\n", dma.qtdDias == 26, dma.qtdDias);
    printf("%d - %d\n", dma.qtdMeses == 0, dma.qtdMeses);
    printf("%d - %d\n", dma.qtdAnos == 0, dma.qtdAnos);

    // teste 4 - mesma data
    strcpy(datainicial, "15/08/2025");
    strcpy(datafinal, "15/08/2025");

    dma = q2(datainicial, datafinal);

    printf("%d - %d\n", dma.retorno == 1, dma.retorno);
    printf("%d - %d\n", dma.qtdDias == 0, dma.qtdDias);
    printf("%d - %d\n", dma.qtdMeses == 0, dma.qtdMeses);
    printf("%d - %d\n", dma.qtdAnos == 0, dma.qtdAnos);

    // teste 5 - empréstimo usando mês de 30 dias
    strcpy(datainicial, "30/04/2025");
    strcpy(datafinal, "01/05/2025");

    dma = q2(datainicial, datafinal);

    printf("%d - %d\n", dma.retorno == 1, dma.retorno);
    printf("%d - %d\n", dma.qtdDias == 1, dma.qtdDias);
    printf("%d - %d\n", dma.qtdMeses == 0, dma.qtdMeses);
    printf("%d - %d\n", dma.qtdAnos == 0, dma.qtdAnos);
}

void testQ2()
{
    show_log("testQ2()");
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    DiasMesesAnos dma;

    //teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "31/01/2025");
    strcpy(datafinal, "01/02/2025");
    dma = q2(datainicial, datafinal);
    printf("%d - %d\n", dma.retorno == 1, dma.retorno);

    //teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "10/05/2020");
    strcpy(datafinal, "05/06/2020");
    dma = q2(datainicial, datafinal);
    printf("%d - %d\n", dma.qtdDias == 26, dma.qtdDias);

    strcpy(datainicial, "01/3/2015");
    strcpy(datafinal, "40/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d - %d\n", dma.retorno == 3, dma.retorno);

    strcpy(datainicial, "01/06/2016");
    strcpy(datafinal, "01/06/2015");
    dma = q2(datainicial, datafinal);
    printf("%d - %d\n", dma.retorno == 4, dma.retorno);

    //teste 3
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "06/06/2017");
    strcpy(datafinal, "07/07/2017");
    dma = q2(datainicial, datafinal);
    printf("%d - %d\n", dma.retorno == 1, dma.retorno);
    printf("%d - %d\n", dma.qtdDias == 1, dma.qtdDias);
    printf("%d - %d\n", dma.qtdMeses == 1, dma.qtdMeses);
    printf("%d - %d\n", dma.qtdAnos == 0, dma.qtdAnos);
}

void testQ3()
{
    show_log("testQ3()");
    char str[250];
    strcpy(str, "AAAAaaaa");
    printf("%d\n", q3(str, 'a', 0) == 8);

    printf("%d\n", q3(str, 'A', 1) == 4);
}

void testQ4()
{
    show_log("testQ4()");
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    strcpy(strTexto, "aaaa");
    strcpy(strBusca, "aa");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 3);

    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    strcpy(strTexto, "Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca, "mui");
    strcpy(strTexto, "banana");
    strcpy(strBusca, "ana");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 2);
}

void testQ5()
{
    show_log("testQ5()");
    printf("%d\n", q6(123123, 123) == 2);

    printf("%d\n", q6(1111, 11) == 3);

    printf("%d\n", q6(99999, 99) == 4);

    printf("%d\n", q6(12345, 6) == 0);
}

void testQ6()
{
    show_log("testQ6()");
    printf("%d\n", q6(123123, 123) == 2);

    printf("%d\n", q6(1111, 11) == 3);

    printf("%d\n", q6(99999, 99) == 4);

    printf("%d\n", q6(12345, 6) == 0);
}

void testQ7()
{
    show_log("testQ7()");
    char matrix3[8][10] = {
    {'X','X','X','X','X','X','X','X','X','A'},
    {'X','X','X','X','X','X','X','X','B','X'},
    {'X','X','X','X','X','X','X','C','X','X'},
    {'X','X','X','X','X','X','D','X','X','X'},
    {'X','X','X','X','X','E','X','X','X','X'},
    {'X','X','X','X','X','X','X','X','X','X'},
    {'X','X','X','X','X','X','X','X','X','X'},
    {'X','X','X','X','X','X','X','X','X','X'}
};

char busca2[6] = "ABCDE";

printf("%d\n", q7(matrix3, busca2) == 1);

    /* char matrix[8][10] = {
        { 'L', 'Q', 'M', 'J', 'D', 'A', 'Z', 'F', 'C', 'R' },
        { 'N', 'B', 'Y', 'G', 'P', 'S', 'K', 'H', 'E', 'X' },
        { 'V', 'O', 'W', 'U', 'T', 'I', 'Z', 'A', 'L', 'C' },
        { 'M', 'Q', 'B', 'D', 'N', 'F', 'R', 'J', 'G', 'E' },
        { 'H', 'S', 'K', 'T', 'U', 'X', 'W', 'O', 'P', 'Y' },
        { 'C', 'Z', 'A', 'I', 'L', 'M', 'V', 'G', 'N', 'B' },
        { 'D', 'F', 'E', 'H', 'S', 'K', 'J', 'Q', 'R', 'T' },
        { 'U', 'X', 'Y', 'W', 'V', 'O', 'P', 'N', 'M', 'L' }
    };

    char stringBusca [6] = { 'X', 'F', 'I', 'S', 'A'};
    printf("%d\n", q7(matrix, stringBusca) == 1); */

}
