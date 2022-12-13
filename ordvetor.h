#include <stdio.h>
#include <stdlib.h>

#ifndef ORDVETOR_H
#define ORDVETOR_H

/*A Definicao do tipo de funcao a ser utilizada para comparacao
Esta function recebe dois valores x e y e retorna
1 : se x Ã© menor que y.
0 : se x Ã© equivalente a y.
-1: se x Ã© maior que y na ordem.
*/
typedef int COMP(void *x, void *y);

// Vetor ordenado estático. Os elementos do vetor estao colocados no vetor
// de acordo com a ordem indicada por comparador.
typedef struct vet
{
    int N;            // tamanho do vetor
    int P;            // numero de elementos no vetor
    void **elems;     // o vetor de elementos
    COMP *comparador; // a funcao de comparacao em questao
} VETORORD;

/**
Cria um vetor ordernado vazio de tamanho n e com funcao de comparacao compara
@param n: o tamanho do vetor
@param compara: a funcao de comparacao
@return um ponteiro para uma estrutura VETORORD, observe que este ponteiro ja
deve apontar para a estrutura, ou seja, a alocacao de memoria deve ser feita nele.
*/
VETORORD *VETORD_create(int n, COMP *compara);

/**
Adiciona o elemento newelem ao vetor ordenado, na posicao correta se for possível
ainda incluir o elemento (se existe espaco no vetor). O vetor deve estar ordenado em
ordem crescente, ou seja: x[i] Ã© menor que ou equivalente a x[j] para todo i < j.
@param vetor: o vetor ordenado a ter o elemento incluido
@param newelem: o elemento a ser adicionado
*/
void VETORD_add(VETORORD *vetor, void *newelem);

/**
Remove o menor elemento do vetor, de acordo com a funcao compara.
@param vetor: o vetor que tera seu elemento removido
@return um ponteiro para o elemento que foi removido do vetor.
*/
void *VETORD_remove(VETORORD *vetor);

#endif
