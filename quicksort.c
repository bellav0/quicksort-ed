#include <stdio.h>
#include <stdlib.h>

void trocaPos(int *numbersToSort, int i, int j) {
  int aux = numbersToSort[i];
  numbersToSort[i] = numbersToSort[j];
  numbersToSort[j] = aux;
}

int particiona(int *numbersToSort, int esq, int dir) {
 int i = esq; 
 int j = dir; 
 int pivo = numbersToSort[(dir+esq)/2];
while(1) {
    while(numbersToSort[i] < pivo){ i++;}
    while(pivo < numbersToSort[j]) {j--;}
    if(i >= j){ break};
    trocaPos(numbersToSort,i,j);
     i++; 
     j--;
}
trocaPos(numbersToSort,i,dir);
return i;
}

void quicksort(int *numbersToSort, int esq, int dir) {

  if (esq >= dir) {
    return;
  }
  int pivo_indice = particiona(numbersToSort, esq, dir);
  quicksort(numbersToSort, esq, pivo_indice-1 );
  quicksort(numbersToSort, pivo_indice, dir);
}
int main() {
  FILE *arquivo = fopen("numbersToSort.txt", "r");
  int *numbersToSort = (int *)malloc(1000 * sizeof(int));
  int vectorSize = 0;
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  int numero;
  while (fscanf(arquivo, "%d", &numero) != EOF) {
    printf("Número lido: %d\n", numero);
    numbersToSort[vectorSize] = numero;
    vectorSize++;
  }

  quicksort(numbersToSort, 0, vectorSize -1);

  for (int i = 0; i < vectorSize; i++)
    printf("%d ", numbersToSort[i]);
  free(numbersToSort);

  fclose(arquivo);

  return 0;
}
