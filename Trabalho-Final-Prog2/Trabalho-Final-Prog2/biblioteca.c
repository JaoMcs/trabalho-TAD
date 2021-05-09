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

//Testar se um elemento está presente no conjunto, retornando sua posição ou -1 se não estiver presente
int TestarElemento (int *vetor, int tamVet, int elemento) {
  int i;
  
  for (i = 0; i < tamVet; i++) {
    if (vetor[i] == elemento) {
      return i;
    }
  }
  return -1;
}

// Retornar a soma de elementos presentes no conjuntos
int RetornarSoma (int *vetor, int tamVet) {
  int i;
  int soma = 0;
  
  for (i = 0; i < tamVet; i++) {
    //printf("n: %d, soma:%d\n", i, soma);
    soma += vetor[i];
  }
  return soma;
}

// Retornar o menor elemento presente no conjunto
int RetornarMenor (int *vetor, int tamVet) {
  int menor = vetor[0];
  int i;
  
  for (i = 0; i < tamVet; i++) {
    if (vetor[i] < menor) {
      menor = vetor[i];
    }
  }
  
  return menor;
}

//Retornar o maior elemento presente no conjunto
int RetornarMaior (int *vetor, int tamVet) {
  int maior = vetor[0];
  int i;
  
  for (i = 0; i < tamVet; i++) {
    if (vetor[i] > maior) {
      maior = vetor[i];
    }
  }
  
  return maior;
}

//Retornar a média aritmética dos elementos de um conjunto
int Media(int *vetor, int tamVet) {
  int media = 0;
  int soma = RetornarSoma(vetor, tamVet);
  
  media = soma/tamVet;
  
  return media;
}

//Retornar a moda dos elementos de um conjunto (-1 caso nao exista a moda)
int Moda(int *vetor, int tamVet) {
  int moda = 0;
  int i, j;
  int *cont = (int*)malloc (tamVet * sizeof (int));
  int conta = 0;
  
  for(i = 0; i < tamVet; i++){
    for(j = i+1; j < tamVet; j++){
      
      if(vetor[i] == vetor[j]){
        cont[i]++;
        if(cont[i] > conta){
          conta = cont[i];
          moda = vetor[i];
        }
      }
      
    }
    cont[i]=0;
  }
  free(cont);
  if (moda == 0) {
    return -1;
  }
  return moda;
}

//Retornar a Mediana dos elementos de um conjunto
int Mediana(int *vetor, int tamVet) {
  int mediana;
  
  mediana = vetor[tamVet/2];
  return mediana;
}
