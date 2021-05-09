//
//  biblioteca.c
//  Trabalho-Final-Prog2
//
//  Created by João Marcos on 08/05/21.
//
#include "biblioteca.h"

//Inicializar o conjunto: cria um vetor e preenche com conteúdo de um arquivo.
void Inicializar(int* vetor, int tamVet, char* arquivo) {
  FILE *arq = fopen(arquivo, "rt");
  
  if (arq == NULL) {
    printf("Arquivo nao encontrado! \n");
    return;
  }
  int i;
  for (i = 0; i < tamVet; i++){
     fscanf (arq, "%d", &vetor[i]);
  }
  fclose (arq);
}

// Imprimir os elementos do conjunto
void Imprimir(int *vetor, int tamVet) {
  int i;
  
  for (i = 0; i < tamVet; i++) {
    printf("%d ", vetor[i]);
  }
}


