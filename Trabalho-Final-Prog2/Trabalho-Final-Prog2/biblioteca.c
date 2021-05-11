//
//  biblioteca.c
//  Trabalho-Final-Prog2
//
//  Created by João Marcos on 08/05/21.
//
#include "biblioteca.h"

//Inicializar o conjunto: cria um vetor e preenche com conteúdo de um arquivo.
void Inicializar(int* vetor, int tamVet, char* arquivo) {
  FILE *arq = fopen(arquivo, "rt"); //Abertura do arquivo, passando como parametro o nome do arquivo e o que vai ser feito, no caso leitura de texto (rt)
  
  if (arq == NULL) { // Verificacao se o arquivo existe!!!
    printf("Arquivo nao encontrado! \n"); // Informar pro usuario ou pro programador
    return; // Return para paarar a funcao
  }
  int i; //Indice
  for (i = 0; i < tamVet; i++){ //Criacao do looping
     fscanf (arq, "%d", &vetor[i]); // Passar todos os itens do arquivo separadamente pro vetor, leitura do arquivo
  }
  fclose (arq); //fechamento do arquivo
}

// Imprimir os elementos do conjunto
void Imprimir(int *vetor, int tamVet) { // recbe como parametro o vetor e o tamanho
  int i; // Valor do indice
  
  for (i = 0; i < tamVet; i++) { // Looping simples pra ir do primeiro elemento ate o ultimo
    printf("%d ", vetor[i]); //Mostrar na tela o numero ou conteudo do TAD (int)
  }
  printf("\n"); // Print so pra melhorar a visualizacao dos elementos
}

//Testar se um elemento está presente no conjunto, retornando sua posição ou -1 se não estiver presente
int TestarElemento (int *vetor, int tamVet, int elemento) { //
  int i; // Indice
  
  for (i = 0; i < tamVet; i++) { //Looping simples do inicio ate o fim do vetor
    if (vetor[i] == elemento) { // verificacao se o elemento esta presente no meu vetor
      return i; // Retornar o indice do valor encontrado
    }
  }
  return -1; // Caso nao encontre, retorne -1
}

// Retornar a soma de elementos presentes no conjuntos
int RetornarSoma (int *vetor, int tamVet) {
  int i; //Indice
  int soma = 0; //variavel que vai conter a soma
  
  for (i = 0; i < tamVet; i++) { //Looping simples pra percorrer o vetor todo
    soma += vetor[i]; // o campo de soma vai somar cada sempre adicionar o elemento do looping
  }
  return soma; //Retorno o valor de soma
}

// Retornar o menor elemento presente no conjunto
int RetornarMenor (int *vetor, int tamVet) {
  int menor = vetor[0]; // Inicio como valor inicial do indice 0 <<
  int i; //Indice
  
  for (i = 0; i < tamVet; i++) { // Mesmo looping simples pra percorrer o vetor todo
    if (vetor[i] < menor) { //Verifico se o menor realmente é o menor elemento
      menor = vetor[i]; //Troca de valores
    }
  }
  
  return menor; //variavel com o menor valor do vetor
}

//Retornar o maior elemento presente no conjunto
int RetornarMaior (int *vetor, int tamVet) {
  int maior = vetor[0]; //iniciar no valor inicial
  int i; //Indice
  
  for (i = 0; i < tamVet; i++) { // Looping simples
    if (vetor[i] > maior) { //verifico se a variavel MAIOR realmente é o maior valor no momento
      maior = vetor[i]; // Troca de valores
    }
  }
  
  return maior; //Variavel com o maior vetor
}

//Retornar a média aritmética dos elementos de um conjunto
double Media(int *vetor, int tamVet) {
  double media = 0; // Importante iniciar com 0 para nao ter lixo
  int soma = RetornarSoma(vetor, tamVet); //Chamo a funcao soma
  
  media = soma/tamVet; //soma divido pelo tamanho do vetor
  
  return media; // retorno o valor da media em questao
}

//Retornar a moda dos elementos de um conjunto (-1 caso nao exista a moda)
int Moda(int *vetor, int tamVet) {
  int moda = 0; // Campo pra colocar o numero que mais apareceu
  int i, j; //Indices i e j
  int *cont = (int*)malloc (tamVet * sizeof (int)); // criando um vetor auxiliar
  int conta = 0; // Campo pra colocar a quantidade de vezs que o numero apareceu
  
  for(i = 0; i < tamVet; i++) { //Looping que percorre do primeiro ao o ultimo
    for(j = i+1; j < tamVet; j++) { //looping que percorre do segundo ao ultimo
      
      if(vetor[i] == vetor[j]) { //Verificacao se os valores sao iguais
        cont[i]++; //Contador pra verificar quantas vezes o numero apareceu
        if(cont[i] > conta){ // Guardando o a conta que vai ter o valor da quantidade de vezes e o numero
          conta = cont[i]; // Guardando a quantidade de vezes que o numero apareceu (apois eu verificar que é o numero que ate entao mais apareceu)
          moda = vetor[i]; // Guardado o numero que mais apareceu
        }
      }
      
    }
    cont[i]=0; // So pra zerar a contador apois a verificacao
  }
  free(cont); // Libero a memoria do cont
  if (moda == 0) { // Faco a verificacao se o moda é maior que 0
    return -1; // Retorno de -1 caso nao tenha nenhum numero igual
  }
  return moda; // Caso o numero moda seja maior que 0 < ele foi tracado alguma vez, a moda existe
}

//Retornar a Mediana dos elementos de um conjunto
int Mediana(int *vetor, int tamVet) {
  int mediana; // Valor que vai ficar salvo a mediana
  int *vetorAux = vetor; // Ponteiro igual o vetor pra ordenar
  OrdenarA(vetorAux, tamVet); // Ordena de forma crescente o vetor
  
  mediana = vetorAux[tamVet/2]; // Pegando o valor que esta na metade do vetor
  return mediana; // Retornando o valor que ta na metade
}

//Retornar o quartil 1 dos elementos de um conjunto
int Quartil_1(int *vetor, int tamVet) {
  int quartil; // Campo pra ser guardado o 1 quartil
  int indiceQuartil = tamVet; // Indice do Quartil vai ser o valor que eu vou alterar ate achar o indice
  int *vetorAux = vetor; // Clonar novamente o vetor pra nao alterar o vetor inicial
  
  OrdenarA(vetorAux, tamVet); // Lembrando qa funcao ordenaA vai ordenar de forma crescente
  indiceQuartil = (tamVet+1)/4; // Aplica a formula
  
  quartil = vetorAux[indiceQuartil]; // o valor representado nesse quartil
  return quartil; // Retorno o quartil
}

//Retornar o quartil 3 dos elementos de um conjunto
int Quartil_3(int *vetor, int tamVet) {
  int quartil; // Campo pra guardar o quartil
  int indiceQuartil = tamVet; // Indice do quartil que inicio em tamVet
  int *vetorAux = vetor; // Clone do vetor para nao alterar o vetor inicial
  
  OrdenarA(vetorAux, tamVet); // Chamada da funcao que ordena o vetor
  indiceQuartil = 3*(tamVet+1)/4; // Alteracao na formula pra pegar o terceiro quartil
  
  quartil = vetorAux[indiceQuartil]; // Valor que vai guardar o terceiro quartil
  return quartil; // Retorno com o valor
}

//Retornar o desvio padrão dos elementos de um conjunto
double Dp(int *vetor, int tamVet) {
  double dp; // Nao to usando float, mudei pra double por causa do formato ser mais amigavel
  int i; // indice
  
  double media = Media(vetor, tamVet); // Chamada da funcao que calcula a media para utilizar na formula

  float variacoes = 0; // Campo pra ser guardado as variacoes
  for (i = 0; i < tamVet; i++) { // Looping pra aplicar a formula
      float v = vetor[i] - media; // subtrair pela media
      variacoes += (v * v); // Fazer ao quadrado
  }

  dp = sqrt(variacoes / tamVet); // Calculo da raiz qudarada
  
  return dp; // Retorna o valor calculado
}

//Comparar 2 conjuntos, retornando 1 se são iguais e 0 se são diferentes
int Comparar(int *vetorA, int tamVetA, int *vetorB, int tamVetB) {
  int comparacao = 0; // Campo pra guardar o resultado das comparacoes
  int i; // Indice
  
  if ( tamVetA == tamVetB ) { // Verificacao pq se os vetores tem tamanhos diferentes eles nao sao iguais
    for (i = 0; i < tamVetA; i++) { // Looping simples do primeiro ate o ultimo valor
      if ( vetorA[i] == vetorB[i]) { // Verifico se é realmente igual
        comparacao = 1; // Igualo a comparacao a 1
      } else { // se os valores forem diferentes ele entra no else
        comparacao = 0; // coloco o valor comparacao pra 0
        return comparacao; // retorno o valor de comparacao parando o looping
      }
    }
  }
  return comparacao; // Retorno o valor de comparacao (no caso 1)
}

//Distancia euclidiana entre 2 conjuntos (os dois conjuntos devem ser do mesmo tamanho)
double DistEuclidiana(int *vetorA, int tamVetA, int *vetorB, int tamVetB) {
  int i; // Indice
  int potencia = 0; //
  int subtracao = 0;
  long int soma = 0; // INT ele vai de -32.000 ate a +32.000
  
  for (i = 0; i < tamVetA; i++) { // Sigo a formula matematica
    subtracao = ( vetorA[i] - vetorB[i] ); // subtracao dos valores de acordo com a formula
    potencia = (pow(subtracao, 2)); // elevo a potencia
    soma += potencia; // somatorio do resultado das potencias
  }
  double de = sqrt(soma); // Raiz quadrada da soma
  return de; // Retorno o valor
}

//Unir os conjunto A e B, gerando um terceiro conjunto C.
int* Uniao(int* vetorA, int tamVetA, int* vetorB, int tamVetB) {
  int *vetorC = (int*)malloc (tamVetA + tamVetB * sizeof (int)); // Alocar um novo vetor C de tamanho somado com os tamanhos dos outros vetores
  int i; // Indice
  
  for ( i = 0; i < tamVetA; i++ ) { // Looping simples
    vetorC[i] = vetorA[i]; // adicionando os valores no novo vetor
  }
  for ( i = 0; i < tamVetB; i++) { // Looping simples
    vetorC[i + tamVetA] = vetorB[i]; // Passando os valores do VetorB no indice i + tamVetA (apos os numeros do vetA)
  }
  return vetorC; // Retorno o novo vetor
}

//Fusionar (intersecção) os elementos do conjunto A e B, gerando um terceiro conjunto C.
int *Inter(int *vetorA, int tamVetA, int *vetorB, int tamVetB) {
  int i, j; // Indices i e j
  int k = 0; // indice K pra ser utilizado no outro vetor
  int *vetorC = (int*) malloc((tamVetA+tamVetB) * sizeof(int)); // Alocacao do vetorC
  
  for ( i = 0; i < tamVetA; i++ ) { // Looping duplo pra percorrer os dois vetores
    for ( j = i+1; j < tamVetB; j++ ) { // Looping pra percorrer o vetor B
      if ( vetorA[i] == vetorB[j] ) { // Caso os numeros sejam iguais entra no if
        vetorC[k] = vetorB[j]; // faz a adicao do item igual no novo vetor
        k++; // incrementa o contado do novo vetor
      }
    }
  }
  return vetorC; // retorna o novo vetor com os items iguais
}

//Ordenar conjunto através de métodos diferentes escolhido por você.
void OrdenarA (int *vetorA, int tamVetA) { // Algoritmo de ordenacao simples
  int i, j; // Indices
  int aux; // Variavel auxliar pra guardar temporariamente o valor do vetor
  
  for (i = 0; i < tamVetA; i++) { // Looping duplo pra percorrer o vetor 2 vezes
    for (j = 0; j < tamVetA; j++) { // Garantindo que cada valor vai ser verificado com todos os vetores
      if (vetorA[i] < vetorA[j]) { // Caso o vet[j] seja maior é invertido
        aux = vetorA[i];           // Troca feita
        vetorA[i] = vetorA[j];
        vetorA[j] = aux;
      }
    }
  }
}

void OrdenarB (int *vetor, int tamVet) { // Boubble Sort
  int i, j, min_idx; // Indices

  for (i = 0; i < tamVet-1; i++) { // Looping simples que percorre o vetor todo
      min_idx = i; // guardando do valor de i
      for (j = i+1; j < tamVet; j++) // looping em J pra percorrer o vetor
        if (vetor[j] < vetor[min_idx]) // Verificacao se o vetor na posicao min_idx é maior que o vetor no j
          min_idx = j; // Troca do valor do min_idx

      swap(&vetor[min_idx], &vetor[i]); // chamada da funcao swap que faz a troca dos valores
  }
}
void swap(int *xp, int *yp) {
    int temp = *xp; //troca dos valores utilizando uma variavel temporaria
    *xp = *yp;
    *yp = temp;
}

void OrdenarC (int *vetorC, int esq ,int dir) { //Quick Sort
  int pivo = esq, i,ch,j; // criacao do pivo (utilizando como referencia a esq e os indices
  for(i=esq+1;i<=dir;i++){ // looping simples
      j = i; // guardando o valor de i na variavel j
      if(vetorC[j] < vetorC[pivo]){ // utilizando a o indice pivo para fazer a verificacao
          ch = vetorC[j]; // guardando a variavel no ch
          while(j > pivo){ // segundo looping que sera feito ate o j for maior que o pivo
            vetorC[j] = vetorC[j-1]; // troca do j pelo valor anterior
              j--; // decremento do j
          }
        vetorC[j] = ch; //setando o vetor[j] como o ch
           pivo++; // encremendo no pivo
      }
  }// chamada recursiva da funcao passando como parametro um novo pivo e novos parametros de esq e dir
  if(pivo-1 >= esq) {
    OrdenarC(vetorC,esq,pivo-1);
  }
  if(pivo+1 <= dir) {
    OrdenarC(vetorC,pivo+1,dir);
  }
}

void OrdenarD (int *vetorD, int tamVetD) { //Insertion Sort
  int i, key, j; // criacao os indices e da variavel keys (onde ira guardar a chave)
  for (i = 1; i < tamVetD; i++) { // loopin simples do inicio ate o final do vetor
      key = vetorD[i]; // guardando o valor da chave do vetor no indice i
      j = i - 1; // mudando o valor de j para o proixmo looping
      while (j >= 0 && vetorD[j] > key) { // looping usando while
        vetorD[j + 1] = vetorD[j]; // passando o valor do vetor no j para o proximo indice
          j = j - 1; // alteracao do valor de j
      }
    vetorD[j + 1] = key; // passando o valor da chave
  }
}
