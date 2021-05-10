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
  int tamanho2 = 100;
  int *vet = (int*)malloc (tamanho * sizeof (int));
  int *vet2 = (int*)malloc (tamanho * sizeof (int));
  int* vet3;
  char nomeArq[30] = "a100.txt";
  char nomeArq2[30] = "a100.txt";

  Inicializar(vet2, tamanho, nomeArq2);
  Inicializar(vet, tamanho, nomeArq);
  
  Imprimir(vet, tamanho);
  Imprimir(vet2, tamanho2);
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
  int quartil_1 = Quartil_1(vet, tamanho);
  printf("%d eh o primeiro quartil do vetor\n", quartil_1);
  int quartil_3 = Quartil_3(vet, tamanho);
  printf("%d eh o terceiro quartil do vetor\n", quartil_3);
  double dp = Dp(vet, tamanho);
  printf("%.2f eh o desvio padrao\n", dp);
  int compara = Comparar(vet, tamanho, vet2, tamanho2);
  printf("%d se 1 eh igual, se 0 eh diferente\n", compara);
  double distanciaEu = DistEuclidiana(vet, tamanho, vet2, tamanho2);
  printf("%.2f eh a distancia euclediana dos 2 vetores\n", distanciaEu);
  vet3 = Uniao(vet, tamanho, vet2, tamanho2);
  Imprimir(vet3, tamanho+tamanho2);

  vet3 = Inter(vet, tamanho, vet2, tamanho2);
  Imprimir(vet3, tamanho+tamanho2);
  
  OrdenarB(vet2, tamanho2);
  Imprimir(vet2, tamanho2);
  
  OrdenarC(vet, 0, tamanho);
  Imprimir(vet, tamanho);
  
  OrdenarD(vet2, tamanho2);
  Imprimir(vet2, tamanho2);
    
  free(vet);
  free(vet2);
  free(vet3);
  return 0;
}
