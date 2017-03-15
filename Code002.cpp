
# include <stdio.h> 

# include <string.h>

void imprimeDecrescente(char *vet, int ini, int fim){

     if(ini <= fim){

        imprimeDecrescente(vet, ini+1, fim);

        printf("%c", vet[ini]);

     }

     return;

}

int main () {

    char vetor[100];

    gets(vetor);

    imprimeDecrescente(vetor, 0, strlen(vetor)-1);

    printf("\n");

    system("pause");

    return 0;
}
