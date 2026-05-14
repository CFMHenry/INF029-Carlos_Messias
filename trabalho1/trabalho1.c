// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Carlos Henrique Ferreir Messias
//  email: carlosmessias2266@gmail.com
//  Matrícula: 20252160036
//  Semestre: 2º

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;
  int iCont;
  

  //quebrar a string data em strings sDia, sMes, sAno
  for(iCont = 0; data[iCont]; iCont++){
    
  } 

  //printf("%s\n", data);

  if (datavalida)
      return 1;
  else
      return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
      
      //calcule a distancia entre as datas


      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    int iCont;
    char CopyStr[256];
    char LowerBox = 'a' - 'A';

    
    if(isCaseSensitive != 1){
        if(c >= 'A' && c <= 'Z'){
            c += LowerBox;
        }

        for(iCont = 0; texto[iCont] != '\0'; iCont++){
            if(texto[iCont] >= 'A' && texto[iCont] <= 'Z')
                CopyStr[iCont] = texto[iCont] + LowerBox;
            else
                CopyStr[iCont] = texto[iCont];
        }
    }
    else{
        for(iCont = 0; texto[iCont] != '\0'; iCont++){
            CopyStr[iCont] = texto[iCont];
        }
    }

    CopyStr[iCont] = '\0';

    for(iCont = 0; CopyStr[iCont]; iCont++){
        if(CopyStr[iCont] == c){
            qtdOcorrencias++;
        }
    }
    
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    int iCont = 0, jCont = 0, kCont = 0;

    for(iCont = 0; strTexto[iCont]; iCont++){

        for(jCont = 0; strBusca[jCont]; jCont++){
            if(strTexto[iCont + jCont] != strBusca[jCont]){
                break;
            }
                
        }
        if(strBusca[jCont] == '\0'){
            qtdOcorrencias++;
            posicoes[kCont] = iCont + 1;
            kCont++;
            posicoes[kCont] = iCont + jCont;
            kCont++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int Razao10, Mult10 = 1;
    int CopyNum = 0;

    Razao10 = CalcRazao10(num);

    for(;num > 0;){
        CopyNum += (num / Razao10) * Mult10;
        num = num % Razao10;
        Razao10 /= 10;
        Mult10 *= 10;
    }

    num = CopyNum;
    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int Razao10Busca;

    Razao10Busca = CalcRazao10(numerobusca);

    for(;numerobase > 0;){
        
        if(numerobase % (Razao10Busca * 10) == numerobusca)
            qtdOcorrencias++;
        
        numerobase /= 10;
        
    }
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

int q7(char matriz[8][10], char palavra[6])
{
    int achou = 0;
    int iCont, jCont, kCont;

    for(iCont = 0; iCont < 8 && !achou; iCont++){
        for(jCont = 0; jCont < 10 && !achou; jCont++){
            if(matriz[iCont][jCont] == palavra[0] && !achou){
                achou += VerificarAcima(matriz, palavra, iCont - 1, jCont, 1);
                achou += VerificarAbaixo(matriz, palavra, iCont + 1, jCont, 1);
                achou += VerificarEsquerda(matriz, palavra, iCont, jCont - 1, 1);
                achou += VerificarDireita(matriz, palavra, iCont, jCont + 1, 1);
                achou += VerificarDiagonalSupEsq(matriz, palavra, iCont - 1, jCont - 1, 1);
                achou += VerificarDiagonalSupDir(matriz, palavra, iCont - 1, jCont + 1, 1);
                achou += VerificarDiagonalInfEsq(matriz, palavra, iCont + 1, jCont - 1, 1);
                achou += VerificarDiagonalInfDir(matriz, palavra, iCont + 1, jCont + 1, 1);
            }
        }
    }

    if(achou > 0)
        achou = 1;

    return achou;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq; 
}

int CalcRazao10(int num){
    int CopyNum = num, Razao10 = 1;

    for(;CopyNum >= 10;){
        CopyNum /= 10;
        Razao10 *= 10;
    }

    return Razao10;
}

int VerificarAcima(char matriz[8][10], char palavra[6], int LinAtual,  int ColAtual, int indxPalavra){

    if(ePosicaoValida(0, LinAtual, ColAtual)){
        if(indxPalavra == 5)
            return 1;

        if(matriz[LinAtual][ColAtual] == palavra[indxPalavra]){
            indxPalavra++;
            if(indxPalavra == 5)
                return 1;
            return VerificarAcima(matriz, palavra, LinAtual - 1, ColAtual, indxPalavra);
        }
        else{
            return 0;
        }    
    }
    else{
        return 0;
    }
}

int VerificarAbaixo(char matriz[8][10], char palavra[6], int LinAtual,  int ColAtual, int indxPalavra){

    if(ePosicaoValida(1, LinAtual, ColAtual)){
        if(indxPalavra == 5)
            return 1;

        if(matriz[LinAtual][ColAtual] == palavra[indxPalavra]){
            indxPalavra++;
            if(indxPalavra == 5)
                return 1;
            return VerificarAbaixo(matriz, palavra, LinAtual + 1, ColAtual, indxPalavra);
        }
        else{
            return 0;
        }    
    }
    else{
        return 0;
    }
}

int VerificarEsquerda(char matriz[8][10], char palavra[6], int LinAtual,  int ColAtual, int indxPalavra){

    if(ePosicaoValida(2, LinAtual, ColAtual)){
        if(indxPalavra == 5)
            return 1;

        if(matriz[LinAtual][ColAtual] == palavra[indxPalavra]){
            indxPalavra++;
            if(indxPalavra == 5)
                return 1;
            return VerificarEsquerda(matriz, palavra, LinAtual, ColAtual - 1, indxPalavra);
        }
        else{
            return 0;
        }    
    }
    else{
        return 0;
    }
}

int VerificarDireita(char matriz[8][10], char palavra[6], int LinAtual,  int ColAtual, int indxPalavra){

    if(ePosicaoValida(3, LinAtual, ColAtual)){
        if(indxPalavra == 5)
            return 1;

        if(matriz[LinAtual][ColAtual] == palavra[indxPalavra]){
            indxPalavra++;
            if(indxPalavra == 5)
                return 1;
            return VerificarDireita(matriz, palavra, LinAtual, ColAtual + 1, indxPalavra);
        }
        else{
            return 0;
        }    
    }
    else{
        return 0;
    }
}

int VerificarDiagonalSupEsq(char matriz[8][10], char palavra[6], int LinAtual,  int ColAtual, int indxPalavra){
    if(ePosicaoValida(4, LinAtual, ColAtual)){
        if(indxPalavra == 5)
            return 1;

        if(matriz[LinAtual][ColAtual] == palavra[indxPalavra]){
            indxPalavra++;
            if(indxPalavra == 5)
                return 1;
            return VerificarDiagonalSupEsq(matriz, palavra, LinAtual - 1, ColAtual - 1, indxPalavra);
        }
        else{
            return 0;
        }    
    }
    else{
        return 0;
    }
}

int VerificarDiagonalInfEsq(char matriz[8][10], char palavra[6], int LinAtual,  int ColAtual, int indxPalavra){
    if(ePosicaoValida(4, LinAtual, ColAtual)){
        if(indxPalavra == 5)
            return 1;

        if(matriz[LinAtual][ColAtual] == palavra[indxPalavra]){
            indxPalavra++;
            if(indxPalavra == 5)
                return 1;
            return VerificarDiagonalSupEsq(matriz, palavra, LinAtual - 1, ColAtual + 1, indxPalavra);
        }
        else{
            return 0;
        }    
    }
    else{
        return 0;
    }
}

int VerificarDiagonalSupDir(char matriz[8][10], char palavra[6], int LinAtual,  int ColAtual, int indxPalavra){
    if(ePosicaoValida(4, LinAtual, ColAtual)){
        if(indxPalavra == 5)
            return 1;

        if(matriz[LinAtual][ColAtual] == palavra[indxPalavra]){
            indxPalavra++;
            if(indxPalavra == 5)
                return 1;
            return VerificarDiagonalSupEsq(matriz, palavra, LinAtual + 1, ColAtual - 1, indxPalavra);
        }
        else{
            return 0;
        }    
    }
    else{
        return 0;
    }
}

int VerificarDiagonalInfDir(char matriz[8][10], char palavra[6], int LinAtual,  int ColAtual, int indxPalavra){
    if(ePosicaoValida(4, LinAtual, ColAtual)){
        if(indxPalavra == 5)
            return 1;
            
        if(matriz[LinAtual][ColAtual] == palavra[indxPalavra]){
            indxPalavra++;
            if(indxPalavra == 5)
                return 1;
            return VerificarDiagonalSupEsq(matriz, palavra, LinAtual + 1, ColAtual + 1, indxPalavra);
        }
        else{
            return 0;
        }    
    }
    else{
        return 0;
    }
}

int ePosicaoValida(int caso, int LinAtual, int ColAtual){
    switch(caso){
        case 0:
            return (LinAtual >= 0); //Verificar casa acima
        case 1:
            return(LinAtual < 8); //Verificar casa abaixo
        case 2: 
            return (ColAtual >= 0); //Verificar casa a esquerda
        case 3: 
            return(ColAtual < 10); //Verifico casa a direita
        case 4: 
            return(LinAtual >= 0 && LinAtual < 8 && ColAtual >= 0 && ColAtual < 10); //Verificar casa acima e a esquerda   
    }
}