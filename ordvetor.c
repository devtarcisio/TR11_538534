#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

VETORORD *VETORD_create(int n, COMP *compara)
{                                                  // criar um vetor ordenadamente
    VETORORD *vetorord = malloc(sizeof(VETORORD)); // alocar o size do ponteiro na memoria
    vetorord->comparador = compara;                // este implica o comparador recebe a funcao de compara
    vetorord->N = n;                               // recebe o tamanho do vetor
    vetorord->P = 0;                               // neste o valor P recebe o valor 0
    vetorord->elems = malloc(n * sizeof(void *));  // este aloca memoria para os elems
    for (int i = 0; i < n; i++)
        vetorord->elems[i] = NULL; // este atribui o valor null para os vetores do elems

    return vetorord; // logo retorna um ponteiro para VETORORD
}

void VETORD_add(VETORORD *vetor, void *newelem)
{ // acrescenta ao vetorord
    if (vetor->P < vetor->N)
    { // se o valor p for menor q N, então o if é realizado
        if (vetor->P == 0)
            vetor->elems[0] = newelem; // se P for 0, então adiciona na primeira casa
        else if (vetor->comparador(newelem, vetor->elems[vetor->P - 1]) == -1 ||
                 vetor->comparador(newelem, vetor->elems[vetor->P - 1]) == 0)
            vetor->elems[vetor->P] = newelem; // verifica se o ultimo elemento é maior ou igual para acrescentar/adicionar
        else
        { // se newelem for menor
            for (int i = vetor->P - 1; i > -1; i--)
            { // a repetição ira acontecer enquanto não encontrar (find
                if (vetor->comparador(newelem, vetor->elems[i]) == 1)
                {                                          // se o elemto for menor que newelem então
                    vetor->elems[i + 1] = vetor->elems[i]; // ele anda o elems uma casa
                    vetor->elems[i] = newelem;             // e o elemento é adicionado no lugar
                }
                else
                    break; // se não for menor então interrompe
            }
        }
        vetor->P++; // valor p do vetorord adiciona mais um
    }
}

void *VETORD_remove(VETORORD *vetor)
{                                // remove ao vetorord
    void *aux = vetor->elems[0]; // um ponteiro auxiliar pra encontrar o endereço referente
    for (int i = 0; i < vetor->P; i++)
        vetor->elems[i] = vetor->elems[i + 1]; // Remove o menor elemento do vetor
    vetor->P--;                                // valor p do vetorord remove um

    return aux; // retorna um ponteiro para o elemento que foi removido do vetor em questão
}
