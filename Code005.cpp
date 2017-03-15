
#include <stdio.h> 

#include <stdlib.h>


// Ordenação de vetor alocado dinamicamente preenchido e ordenado com bubble sort em funções ( protótipo )

void preenche (int *valores, int tamanho);

void ordem (int *valores, int tamanho);

void imprimir (int *valores, int tamanho);


int main () {
 
     do {

        printf("\nInforme o tamanho do vetor: ");
        scanf("%i",&tamanho);

        valores = (int *) malloc( tamanho * sizeof(int));


        preenche(valores,tamanho);
     
        ordem(valores,tamanho);

        imprimir(valores,tamanho);


        free(valores);

        printf("\nDigite 0 para sair ou 1 para refazer: ");
        scanf("%i",&cont);

        if (cont == 1){
          
          system("cls || clear");

        }

      } while (cont != 0);

  return 0;

}

void preenche (int *valores, int tamanho){

  for ( int i = 0; i < tamanho; i++){
    printf("\nInforme o %i valor: ",i + 1);
    scanf("%i",&valores[i]);
  }

}

void ordem (int *valores, int tamanho) {

    int cache;

    for ( int i = 0; i < tamanho; i++){
      for ( int h = i +1; h < tamanho; h++){
       if (valores[i] > valores[h]){
        cache = valores[h];

         valores[h] = valores[i];

         valores[i] = cache;
       }
    }
  }
}

void imprimir (int *valores, int tamanho){

  puts("");

  for ( int i = 0; i < tamanho; i++){
    printf("\n%i",valores[i]);
  }

  puts("");

}
