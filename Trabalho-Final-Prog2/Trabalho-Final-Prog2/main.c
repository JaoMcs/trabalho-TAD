//
//  main.c
//  Trabalho-Final-Prog2
//
//  Created by João Marcos on 08/05/21.
//

#include "biblioteca.h"
#include <stdio.h>

int main(int argc, const char * argv[]) {
  
  int tamanho = 100;
  int *vet = (int*)malloc (tamanho * sizeof (int));
  char nomeArq[30] = "a100.txt";

  Inicializar(vet, tamanho, nomeArq);
  Imprimir(vet, tamanho);
  int posicao = TestarElemento(vet, tamanho, 3062);
  printf("\nPosicao eh: %d\n", posicao);
  int somatorio = RetornarSoma(vet, tamanho);
  printf("\n\nsomatorio: %d\n", somatorio);
  int menor = RetornarMenor(vet, tamanho);
  printf("%d eh o menor numero do vetor\n", menor);
  int maior = RetornarMaior(vet, tamanho);
  printf("%d eh o maior numero do vetor\n", maior);
  int media = Media(vet, tamanho);
  printf("%d eh a media do vetor\n", media);
  int moda = Moda(vet, tamanho);
  if (moda != -1) {
    printf("%d eh a moda do vetor\n", moda);
  } else {
    printf("Moda nao exista nesse vetor\n");
  }
  int mediana = Mediana(vet, tamanho);
  printf("%d eh a mediana do vetor\n", mediana);
  
  free(vet);
  return 0;
}
