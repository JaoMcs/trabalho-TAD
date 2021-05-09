//
//  biblioteca.h
//  Trabalho-Final-Prog2
//
//  Created by João Marcos on 08/05/21.
//

#ifndef biblioteca_h
#define biblioteca_h

#include <stdio.h>
#include <stdlib.h>

//Inicializar o conjunto: cria um vetor e preenche com conteúdo de um arquivo.
void Inicializar(int *vetor, int tamVet, char *arquivo);

// Imprimir os elementos do conjunto
void Imprimir(int *vetor, int tamVet);

//Testar se um elemento está presente no conjunto, retornando sua posição ou -1 se não estiver presente
int TestarElemento (int *vetor, int tamVet, int elemento);

// Retornar a soma de elementos presentes no conjuntos
int RetornarSoma (int vetor, int tamVet);

// Retornar o menor elemento presente no conjunto
int RetornarMenor (int vetor, int tamVet);

//Retornar o maior elemento presente no conjunto
int RetornarMaior (int vetor, int tamVet);

//Retornar a média aritmética dos elementos de um conjunto
int Media(int vetor, int tamVet);

//Retornar a moda dos elementos de um conjunto
int Moda(int vetor, int tamVet);

//Retornar a Mediana dos elementos de um conjunto
int Mediana(int vetor, int tamVet);

//Retornar o quartil 1 dos elementos de um conjunto
int Quartil_1(int vetor, int tamVet);

//Retornar o quartil 3 dos elementos de um conjunto
int Quartil_3(int vetor, int tamVet);

//Retornar o desvio padrão dos elementos de um conjunto
double dp(int vetor, int tamVet);

//Comparar 2 conjuntos, retornando 1 se são iguais e 0 se são diferentes
int Comparar(int vetorA, int tamVetA, int vetorB, int tamVetB);

//Distancia euclidiana entre 2 conjuntos (os dois conjuntos devem ser do mesmo tamanho)
float DistEuclidiana(int vetorA, int tamVetA, int vetorB, int tamVetB);

//Unir os conjunto A e B, gerando um terceiro conjunto C.
int *Uniao(int vetorA, int tamVetA, int vetorB, int tamVetB);

//Fusionar (intersecção) os elementos do conjunto A e B, gerando um terceiro conjunto C.
int *Inter(int vetorA, int tamVetA, int vetorB, int tamVetB);

//Ordenar conjunto através de métodos diferentes escolhido por você.
void OrdenarA (int *vetorA, int tamVetA);
void OrdenarB (int *vetorB, int tamVetB);
void OrdenarC (int *vetorC, int tamVetC);
void OrdenarD (int *vetorD, int tamVetD);



#endif / *biblioteca_h */
