
# include <stdio.h> 

typedef struct sPes {
        char nome[30];
        int idade;
} Pessoa;

int main(){

    FILE* f;

    f = fopen("dados.txt", "r");

    if(f == NULL){

       printf("Arquivo não existe !\n");

       system("pause");

       return 0;
    }

        int n;

        fscanf(f, "%d", &n);

        Pessoa *vet;

        vet = (Pessoa*) malloc (n*sizeof(Pessoa));

        int i, maior, ind;

        for(i=0; i<n; i++){

            fscanf(f, "%s", vet[i].nome);

            fscanf(f, "%d", &vet[i].idade);

            if(i==0){ // Primeira Leitura
                 maior = vet[i].idade;
                 ind = i;
            }

            // Encontrando a pessoa mais velha

            if(vet[i].idade > maior){
               maior = vet[i].idade;
               ind = i;
            }

        }

        printf("A pessoa mais velha chama-se %s e tem %d anos.\n", vet[ind].nome, vet[ind].idade);

        free(vet);

    fclose(f);

    system("pause");

    return 0;

}
