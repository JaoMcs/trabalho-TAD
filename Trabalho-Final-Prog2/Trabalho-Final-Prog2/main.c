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
  
  return 0;
}
