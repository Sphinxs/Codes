
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

int main(){

    FILE* f;

    f = fopen("forn.txt", "w");

    if(f == NULL){

       printf("Arquivo não existe!\n");

       system("pause");

       return 0;
    }

    int n;

    printf("Digite o numero de fornecedores:\n");
    scanf("%d", &n);

    //Gravando no arquivo

    fprintf(f, "%d\n", n);

    Fornecedor *forn;

    forn = (Fornecedor*) malloc (n*sizeof(Fornecedor));

    int i;

    for(i=0; i<n; i++){

        printf("Digite o nome do fornecedor:\n");
            fflush(stdin);
                gets(forn[i].nome);

        printf("Digite a quantidade de produtos:\n");
            scanf("%d", &forn[i].produtos);

        printf("Digite o telefone do fornecedor:\n");
            fflush(stdin);
                gets(forn[i].telefone);

        printf("Digite os dados de endereco:\n");

        printf("Digite o nome da rua:\n");
            fflush(stdin);
                gets(forn[i].end.rua);

        printf("Digite o numero:\n");
            fflush(stdin);
                scanf("%d", &forn[i].end.num);

        //Gravando no arquivo

        fprintf(f, "%s\n", forn[i].nome);

        fprintf(f, "%d\n", forn[i].produtos);

        fprintf(f, "%s\n", forn[i].telefone);

        fprintf(f, "%s\n", forn[i].end.rua);

        fprintf(f, "%d\n", forn[i].end.num);
    }

    free(forn);

    fclose(f);

    system("pause");

    return 0;

}
