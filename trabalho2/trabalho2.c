#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

EstAux * vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/

int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int retorno = 0;
    
    if(tamanho < 1){
        // o tamanho nao pode ser menor que 1 (X)
        retorno = TAMANHO_INVALIDO;
    }
    else if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        // se posição é um valor válido {entre 1 e 10} (X)
        retorno = POSICAO_INVALIDA;
    }
    else if(tamanho > 2147483000){
        // o tamanho ser muito grande (x)
        retorno = SEM_ESPACO_DE_MEMORIA;
    }
    else if(vetorPrincipal[posicao - 1] != NULL){
        // a posicao pode já existir estrutura auxiliar
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    }
    else{
        // deu tudo certo, crie ( )
        Criar_EstrurasAuxiliar(posicao, tamanho);
        //chamar criar estrutura
        retorno = SUCESSO;
    }
    
    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int estaCheio = 0;
    int posicao_invalida = ehPosicaoValida(posicao);


    if (posicao_invalida == POSICAO_INVALIDA)
        retorno = POSICAO_INVALIDA;
    else
    {
        int existeEstruturaAuxiliar = ExisteEstruturaAuxiliar(posicao);
        // testar se existe a estrutura auxiliar
        if (existeEstruturaAuxiliar != SEM_ESTRUTURA_AUXILIAR)
        {
            estaCheio = temEspaco(posicao);
            if (estaCheio == SUCESSO)
            {
                inserirNum(posicao, valor);
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = SUCESSO;
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        return POSICAO_INVALIDA;
    }
    else if(vetorPrincipal[posicao - 1] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    else if(vetorPrincipal[posicao - 1]->qtdElementos < 1){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    else{
        vetorPrincipal[posicao - 1]->qtdElementos--;
        return SUCESSO;
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = 0;
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        return POSICAO_INVALIDA;
    }
    else if(vetorPrincipal[posicao - 1] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    else if(vetorPrincipal[posicao - 1]->qtdElementos < 1){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    else{
        int i;
        for(i = 0; i < vetorPrincipal[posicao - 1]->qtdElementos; i++){
            if(vetorPrincipal[posicao - 1]->num[i] == valor){
                vetorPrincipal[posicao - 1]->qtdElementos--;
                retorno = SUCESSO;
                break;
            }
        }

        int j = i + 1;
        if(retorno == SUCESSO){
            for(; i < vetorPrincipal[posicao - 1]->qtdElementos; i++, j++){
                vetorPrincipal[posicao - 1]->num[i] = vetorPrincipal[posicao - 1]->num[j];
            }
        }
        else
            retorno = NUMERO_INEXISTENTE;
    }
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}

int ExisteEstruturaAuxiliar(int posicao){
    if(vetorPrincipal[posicao - 1] != NULL){
        return 1;
    }
    else{
        return SEM_ESTRUTURA_AUXILIAR;
    }
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        return POSICAO_INVALIDA;
    }
    else if(vetorPrincipal[posicao - 1] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    else if(vetorPrincipal[posicao - 1]->qtdElementos < 1){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    else{
        for(int i = 0; i < vetorPrincipal[posicao - 1]->qtdElementos; i++){
            vetorAux[i] = vetorPrincipal[posicao - 1]->num[i];
        }
        return SUCESSO;
    }
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
    int i = 0, j = 0, Aux;
    
    
    if(retorno == SUCESSO){
        while(i < vetorPrincipal[posicao - 1]->qtdElementos - 1){
            for(j = i + 1; j < vetorPrincipal[posicao - 1]->qtdElementos; j++){
                if(vetorAux[i] > vetorAux[j]){
                    Aux = vetorAux[i];
                    vetorAux[i] = vetorAux[j];
                    vetorAux[j] = Aux;
                }
            }
            i++;
        }
    }
    
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int indx = 0;
    for(int i = 0; i < TAM; i++){
        if(vetorPrincipal[i] != NULL){
            for(int j = 0; j < vetorPrincipal[i]->qtdElementos; j++){
                vetorAux[j + indx] = vetorPrincipal[i]->num[j];
            }
            indx += vetorPrincipal[i]->qtdElementos;
        }
    }

    if(!indx){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    else{
        return SUCESSO;
    }
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);
    int qtdElementosTotais = 0, i, j, Aux;
    if(retorno == SUCESSO){
        for(i = 0; i < TAM; i++){
            if(vetorPrincipal[i] != NULL){
                qtdElementosTotais += vetorPrincipal[i]->qtdElementos;
            }
        }

        for(i = 0; i < qtdElementosTotais - 1; i++){
            for(j = i + 1; j < qtdElementosTotais; j++){
                if(vetorAux[i] > vetorAux[j]){
                    Aux = vetorAux[i];
                    vetorAux[i] = vetorAux[j];
                    vetorAux[j] = Aux;
                }
            }
        }
    }
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = SUCESSO;
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }
    else if(vetorPrincipal[posicao - 1] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    else if(novoTamanho + vetorPrincipal[posicao - 1]->TAM_MAX < 1){
        return NOVO_TAMANHO_INVALIDO;
    }
    else{
        int * aux = realloc(vetorPrincipal[posicao - 1]->num, (vetorPrincipal[posicao - 1]->TAM_MAX + novoTamanho) * sizeof(int));

        
        if(aux == NULL){
            return SEM_ESPACO_DE_MEMORIA;
        }

        vetorPrincipal[posicao - 1]->num = aux;

        vetorPrincipal[posicao - 1]->TAM_MAX += novoTamanho;
        if(vetorPrincipal[posicao - 1]->qtdElementos > vetorPrincipal[posicao - 1]->TAM_MAX){
            vetorPrincipal[posicao - 1]->qtdElementos = vetorPrincipal[posicao - 1]->TAM_MAX;
        }

    }
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;
    if(ehPosicaoValida(posicao) != SUCESSO){
        return POSICAO_INVALIDA;
    }
    else if(vetorPrincipal[posicao - 1] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    else if(vetorPrincipal[posicao - 1]->qtdElementos == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    else{
        retorno = vetorPrincipal[posicao - 1]->qtdElementos;
        
    }
    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    No * head = NULL, * NoAux = NULL;
    int vetorAux[10000], cont = 0, i;
    int retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);

    if(retorno == SUCESSO){
        for(i = 0; i < TAM; i++){
            cont += contarElementos(i);
        }

        head = criar_no();
        head->prox = NULL;
        NoAux = head;

        for(i = 0; i < cont; i++){
            NoAux->prox = criar_no();
            NoAux = NoAux->prox;
            NoAux->conteudo = vetorAux[i];
        }
    }

    return head;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    No * Aux = inicio->prox;

    for(int i = 0; Aux != NULL; i++){
        vetorAux[i] = Aux->conteudo;
        Aux = Aux->prox;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No * Aux = *inicio;
    No * proximo;

    while(Aux != NULL){
        proximo = Aux->prox;
        free(Aux);
        Aux = proximo;
    }
    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    int i = 0;
    for(i = 0; i < TAM; i++)
        vetorPrincipal[i] = NULL;

}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    for(int i = 0; i < TAM; i++){
        if(vetorPrincipal[i] != NULL){
            free(vetorPrincipal[i]->num);
            free(vetorPrincipal[i]);
        }
    }
}

No * criar_no(){
    No * novo = malloc(sizeof(No));
    return novo;
} 

int temEspaco(int posicao){
    if(vetorPrincipal[posicao - 1]->qtdElementos >= vetorPrincipal[posicao - 1]->TAM_MAX){
        return SEM_ESPACO;
    }
    else{
        return SUCESSO;
    }
}

void inserirNum(int posicao, int num){
    vetorPrincipal[posicao - 1]->num[vetorPrincipal[posicao - 1]->qtdElementos] = num;
    vetorPrincipal[posicao - 1]->qtdElementos += 1;
}

void Criar_EstrurasAuxiliar(int posicao, int tamanho){
    vetorPrincipal[posicao - 1] = malloc(sizeof(EstAux));
    vetorPrincipal[posicao - 1]->qtdElementos = 0;
    vetorPrincipal[posicao - 1]->TAM_MAX = tamanho;
    vetorPrincipal[posicao - 1]->num = malloc(tamanho * sizeof(int)); 
}

int contarElementos(int posicao){
    if(vetorPrincipal[posicao] != NULL){
        return vetorPrincipal[posicao]->qtdElementos;
    }
    return 0;
}
