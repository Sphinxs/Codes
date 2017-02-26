
#include <stdio.h>

typedef struct sEnd{
        char rua[30];
        int num;
} Endereco;

typedef struct sFornecedor{
        char nome[30];
        int produtos;
        Endereco end;
        char telefone[20];
} Fornecedor;

void imprime(Fornecedor *forn, int ini, int fim){

    if(ini<= fim){

        printf("\n\nDados do fornecedor %d:\n", ini+1);

        printf("Nome: %s\n", forn[ini].nome);

        printf("Produtos: %d\n", forn[ini].produtos);

        printf("Telefone %s\n", forn[ini].telefone);

        printf("Rua: %s\n", forn[ini].end.rua);

        printf("Numero: %d\n", forn[ini].end.num);

        imprime(forn, ini+1, fim);

    }
}


int main(){

    FILE* f;


    f = fopen("forn.bin", "rb");

    if(f == NULL){

       printf("Arquivo não existe!\n");

       system("pause");

       return 0;
    }

    int n;

    fread(&n, sizeof(int), 1, f);

    Fornecedor *forn;

    forn = (Fornecedor*) malloc (n*sizeof(Fornecedor));

    //Lendo do arquivo

    fread(forn, sizeof(Fornecedor), n, f);

    //Imprimindo os dados

    imprime(forn, 0, n-1);


    int i;

    int ind = 0, maior = forn[0].produtos;

    for(i=0; i<n; i++){

          if(forn[i].produtos > maior){

             maior = forn[i].produtos;

             ind = i;

          }

    }

    printf("\n\nO fornecedor com mais produtos eh: %s\n", forn[ind].nome);

    free(forn);

    fclose(f);

    system("pause");

    return 0;

}
