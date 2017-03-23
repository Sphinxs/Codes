
# include <stdio.h>

# include <stdlib.h>

# include <string.h>

# include <locale.h>

# define Sizers 20

/*

    Atividade de Estrutura de Dados, a ideia inicial do exercício
    é que todo o algoritmo seja estático, porém com os poderes de
    Gray Skull implementei ele um pouco dinâmico. A inconsistência
    nos métodos de obtenção dos dados se faz  pelo compilador em
    questão da minha máquina.

    Terminal : Imgur.com/a/VkRRx - Dados : Amazon.com.br

*/

typedef struct {

    char nome[Sizers], autor[Sizers];

    int paginas;

} Livros;


void Preenche (Livros * Poin, int Tam);

void Imprimi (Livros * Poin, int Tam);

void ImpAutor (Livros * Poin, int Tam);

void ImpPages (Livros * Poin, int Tam);


int main ( int argv, char * argc [] ) {


    setlocale(LC_ALL,"");


    Livros User;

    Livros * Poin = &User;

    int Tam = 0;


    do {

        printf("\nInforme o tamanho da estrutura : ");
        scanf("%d", &Tam);

    } while ( Tam <= 0 );


    Poin = ( Livros * ) malloc ( Tam * sizeof(Livros) );

    if ( Poin == NULL ) {
        exit(1); // Overflow
    }


    Preenche (Poin, Tam); // Okay

    Imprimi (Poin, Tam); // Okay

    ImpAutor (Poin, Tam); // Okay

    // ImpPages (Poin, Tam); // Okay


    free (Poin);

    return 0;

}


void Preenche (Livros * Poin, int Tam) {

    short int cont = 0;

    while ( cont < Tam ) {

        setbuf(stdin, NULL);

        system("clear");

        printf("\n%hi - Nome do livro : ", cont + 1);
        fgets(Poin[cont].nome, sizeof(Poin[cont].nome), stdin);

        printf("\n%hi - Nome do autor : ", cont + 1);
        fgets(Poin[cont].autor, sizeof(Poin[cont].autor), stdin);

        printf("\n%hi - Número de páginas : ", cont + 1);
        scanf("%d", &Poin[cont].paginas);

        cont ++;

    } system("clear");

}


void Imprimi (Livros * Poin, int Tam) {

    short int quan = 0, cont = 0;

    do {

        printf("\nQuantos livros deseja imprimir : ");
        scanf("%hi", &quan);

        if ( quan > Tam ){
            printf("\nValor informado é maior que o disponível : %d\n", Tam);
        }

    } while (quan > Tam);

    for ( ; cont < quan; cont ++ ) {
        printf("\n\t%s do autor (a) %s contém %d página (s) \n", Poin[cont].nome, Poin[cont].autor, Poin[cont].paginas);
    } puts("");

}


void ImpAutor (Livros * Poin, int Tam) {

    setbuf(stdin, NULL);

    int con = 0, ach = 0;

    char aut [Sizers];

    printf("\nInforme o nome do autor : ");
    fgets(aut, sizeof(aut), stdin);

    for ( ; con < Tam; con++ ) {
        if(strcmp(aut, Poin[con].autor) == 0 ) {
           printf("\n\t%s do autor (a) %s contém %d página (s) \n", Poin[con].nome, Poin[con].autor, Poin[con].paginas); ach = 1;
        }
    }

    if ( ach == 0 ) {
        printf("\nNão foi encontrado nenhum autor com este nome !\n");
    }

}

void ImpPages (Livros * Poin, int Tam) {

    puts("\n\n-------------------------------------------------\n\nLivros com 50 ou mais páginas : ");

	for ( int con = 0; con < Tam; con++ ) {
		if (Poin[con].paginas >= 50) {
			printf("\n\t%s do autor (a) %s contém %d página (s) \n", Poin[con].nome, Poin[con].autor, Poin[con].paginas);
        }
	}

    puts("\n\n-------------------------------------------------\n");

}
