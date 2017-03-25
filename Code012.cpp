
# include <stdio.h>

# include <locale.h>

# include <stdlib.h>

# include <string.h>

# include <stdbool.h>


typedef struct {
    char snome[25];
    int episodios, nota;
} Seriado;

typedef struct Prov {
    char anome[25];
    int assistidos;
    Seriado series[20];
} Aluno;


void Clear ();

void CadAluno (Aluno * Point, int * Tam);

void CadSerie (Aluno * Point, const int * Tam);

void ImpAluno (Aluno * Point, const int * Tam);


int main ( void ) { setlocale(LC_ALL,"");

    int Tam = 0, Escolha = 0;

    Aluno Dados[3];

    while ( true ) {

        printf("\n\n1 - Cadastrar Aluno\n\n2 - Cadastrar Série\n\nX - Para Sair\n\n3 - Imprime Todos\n\n");

        printf("\nInforme sua escolha : ");
        scanf("%d", &Escolha);

        setbuf(stdin , NULL);

        switch (Escolha) {

            case 1:
                Clear (); CadAluno (Dados, &Tam);
            break;

            case 2:
                Clear (); CadSerie (Dados, &Tam);
            break;

            case 3:
				Clear (); ImpAluno (Dados, &Tam);
			break;

            default:
                Clear (); exit(1);

        }

    }

}


void Clear () {
    system("clear || cls");
}


void CadAluno (Aluno * Point, int * Tam) {

    if ( * Tam < 3 ) {

		Clear ();

        * Tam += 1;

        setbuf(stdin, NULL);

        printf("\nInforme o nome do aluno : ");
        fgets(Point[* Tam].anome, 25, stdin);

		Clear ();

    } else {

        Clear (); printf("\nImpossível adicionar novos alunos, armazenamento indisponível !\n");

    }

}


void CadSerie (Aluno * Point, const int * Tam) {

    register int Con = 0, Indice = 0;

    char Nome [25];

    printf("\nInforme o nome do aluno que deseja cadastrar a (s) série (s) : ");
    fgets(Nome, 25, stdin);

    for ( ; Con < 3; Con ++ ) {
        if ( strcasecmp(Nome, Point[Con].anome) == 0){
            Indice = Con; // break; printf("\n\nCadastro de séries do aluno %s :\n",Point[Con].anome);
        }
    }

	if (Indice == 0) {
			Clear (); printf("\nNenhum aluno com esse nome foi encontrado !\n");
	} else {

		// ...

		if (Point[Indice].assistidos >= 20) {
			printf("\nChegou ao limite de séries cadastradas para este usuário !\n"); exit(1);
		} else {

			// setbuf(stdin, NULL);

			int NumSerie = Point[Indice].assistidos;

			printf("\nInforme o nome da série : ");
			fgets(Point[Indice].series[NumSerie].snome, 25, stdin);

			printf("\nInforme a nota da série : ");
			scanf("%d",&Point[Indice].series[NumSerie].nota);

			printf("\nInforme o número de episódios : ");
			scanf("%d",&Point[Indice].series[NumSerie].episodios);

			Point[Indice].assistidos += 1;

			Clear ();

		}

	}
}


void ImpAluno (Aluno * Point, const int * Tam) {

	int Con = 1;

	if ( * Tam > 0 ) {
		Clear ();

		for ( ; Con <= * Tam; Con ++ ) {
			printf("\n%d - Aluno %s já assistiu %d séries.\n", Con, Point[Con].anome,Point[Con].assistidos);
		}

	} else {

		Clear (); printf("\nImpossível imprimir pois nenhum aluno foi cadastrado !\n");

	}

}
