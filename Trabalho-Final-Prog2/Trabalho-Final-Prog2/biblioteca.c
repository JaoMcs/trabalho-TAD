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
  printf("\n");
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
  int *vetorAux = vetor;
  OrdenarA(vetorAux, tamVet);
  
  mediana = vetorAux[tamVet/2];
  return mediana;
}

//Retornar o quartil 1 dos elementos de um conjunto
int Quartil_1(int *vetor, int tamVet) {
  int quartil;
  int indiceQuartil = tamVet;
  int *vetorAux = vetor;
  
  OrdenarA(vetorAux, tamVet);
  indiceQuartil = (tamVet+1)/4;
  
  quartil = vetorAux[indiceQuartil];
  return quartil;
}

//Retornar o quartil 3 dos elementos de um conjunto
int Quartil_3(int *vetor, int tamVet) {
  int quartil;
  int indiceQuartil = tamVet;
  int *vetorAux = vetor;
  
  OrdenarA(vetorAux, tamVet);
  indiceQuartil = 3*(tamVet+1)/4;
  
  quartil = vetorAux[indiceQuartil];
  return quartil;
}

//Retornar o desvio padrão dos elementos de um conjunto
double Dp(int *vetor, int tamVet) {
  double dp;
  int i;
  
  int somatorio = 0;
  for (int i = 0; i < tamVet; i++) {
      somatorio += vetor[i];
  }

  double media = somatorio / (double) tamVet;

  float variacoes = 0;
  for (i = 0; i < tamVet; i++) {
      float v = vetor[i] - media;
      variacoes += v * v;
  }

  dp = sqrt(variacoes / tamVet);
  
  return dp;
}

//Comparar 2 conjuntos, retornando 1 se são iguais e 0 se são diferentes
int Comparar(int *vetorA, int tamVetA, int *vetorB, int tamVetB) {
  int comparacao = 0;
  int i;
  
  if ( tamVetA == tamVetB ) {
    for (i = 0; i < tamVetA; i++) {
      if ( vetorA[i] == vetorB[i]) {
        comparacao = 1;
      } else {
        return comparacao = 0;
      }
    }
  }
  return comparacao;
}

//Distancia euclidiana entre 2 conjuntos (os dois conjuntos devem ser do mesmo tamanho)
double DistEuclidiana(int *vetorA, int tamVetA, int *vetorB, int tamVetB) {
  int i;
  int potencia = 0;
  int subtracao = 0;
  long int soma = 0;
  
  for (i = 0; i < tamVetA; i++) {
    subtracao = ( vetorA[i] - vetorB[i] );
    potencia = (pow(subtracao, 2));
    soma += potencia;
  }
  double de = sqrt(soma);
  return de;
}

//Unir os conjunto A e B, gerando um terceiro conjunto C.
int* Uniao(int* vetorA, int tamVetA, int* vetorB, int tamVetB) {
  int *vetorC = (int*)malloc (tamVetA+tamVetB * sizeof (int));
  int i;
  
  for ( i = 0; i < tamVetA; i++) {
    vetorC[i] = vetorA[i];
  }
  for ( i = 0; i < tamVetA; i++) {
    vetorC[i + tamVetA] = vetorB[i];
  }
  return vetorC;
}

//Fusionar (intersecção) os elementos do conjunto A e B, gerando um terceiro conjunto C.
int *Inter(int *vetorA, int tamVetA, int *vetorB, int tamVetB) {
  int i, j;
  int k = 0;
  int *vetorC = (int*) malloc((tamVetA+tamVetB) * sizeof(int));
  
  for ( i = 0; i < tamVetA; i++ ) {
    for ( j = 0; j < tamVetB; j++ ) {
      if ( vetorA[i] == vetorB[j] ) {
        vetorC[k] = vetorB[j];
        k++;
      }
    }
  }
  return vetorC;
}

//Ordenar conjunto através de métodos diferentes escolhido por você.
void OrdenarA (int *vetorA, int tamVetA) {
  int i, j;
  int aux;
  
  for (i = 0; i < tamVetA; i++) {
    for (j = 0; j < tamVetA; j++) {
      if (vetorA[i] < vetorA[j]) {
        aux = vetorA[i];
        vetorA[i] = vetorA[j];
        vetorA[j] = aux;
      }
    }
  }
}

void OrdenarB (int *vetor, int tamVet) {
  int i, j, min_idx;

  for (i = 0; i < tamVet-1; i++) {
      min_idx = i;
      for (j = i+1; j < tamVet; j++)
        if (vetor[j] < vetor[min_idx])
          min_idx = j;

      swap(&vetor[min_idx], &vetor[i]);
  }
}
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void OrdenarC (int *vetorC, int esq ,int dir) {
  int pivo = esq, i,ch,j;
  for(i=esq+1;i<=dir;i++){
      j = i;
      if(vetorC[j] < vetorC[pivo]){
          ch = vetorC[j];
          while(j > pivo){
            vetorC[j] = vetorC[j-1];
              j--;
          }
        vetorC[j] = ch;
          pivo++;
      }
  }
  if(pivo-1 >= esq) {
    OrdenarC(vetorC,esq,pivo-1);
  }
  if(pivo+1 <= dir) {
    OrdenarC(vetorC,pivo+1,dir);
  }
}

void OrdenarD (int *vetorD, int tamVetD) {
  int i, key, j;
  for (i = 1; i < tamVetD; i++) {
      key = vetorD[i];
      j = i - 1;
      while (j >= 0 && vetorD[j] > key) {
        vetorD[j + 1] = vetorD[j];
          j = j - 1;
      }
    vetorD[j + 1] = key;
  }
}
