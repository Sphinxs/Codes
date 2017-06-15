
# include <stdio.h>

# include <string.h>

# include <stdlib.h>

# include <locale.h>

# include <stdbool.h>

# define Tam 50


typedef struct {
    int mat;
    char name [Tam], course [Tam], mail [Tam];
} Info;

typedef struct no {
    Info person;
    struct no * esq, * dir;
} Node;


void clear ( void );

void initialize ( Node ** root );

int empty ( Node ** root );

Node * createno ( void );

Info getinfo ( void );

void addrec ( Node ** root, const Info cell );

void showps ( Node ** root );

void showod ( Node ** root );

Node * search ( Node ** root, const int mats );

int alterc ( Node ** root, const int mats, char * ncourse );

int alterm ( Node ** root, const int mats, char * nmail );


int main ( int argv, const char * argc [] ) {

    setlocale ( LC_ALL, "" );


    Node * root, * tmp, * aux;

    initialize ( &root );

    initialize ( &tmp );

    initialize ( &aux );


    unsigned short int out = 0, cho = 0;

    int mats = 0;

    char nc [Tam], nm [Tam];

    Info temp;

    while ( true ) {


        printf ( "\nMenu :\n\n1 - Vazia\n\n2 - Curso\n\n3 - Ordem\n\n4 - E-mail\n\n5 - Recursão\n\n6 - Pesquisa\n\n7 - Crescente\n\n" );

		printf ( "\nQual é a sua escolha : " );
		scanf ( "%hu", &cho );


		switch ( cho ) {

			case 1 :

				clear (); empty ( &root ) == 1 ? printf ( "\nÁrvore vazia\n" ) : printf ( "\nÁrvore contém itens\n" );

			break;

			case 2 :

				clear ();

				printf ( "\nInforme a matrícula : " );
				scanf ( "%d", &mats );

				tmp = search ( &root, mats );

				if ( ! tmp ) {

					printf ( "\nMatrícula não encontrada\n" );

					break;

				}

				setbuf ( stdin, NULL );

				printf ( "\nInforme o novo curso para o cadastro de matrícula %d : ", mats );
				fgets ( nc, Tam, stdin );

				alterc ( &root, mats, nc ) == 1 ? printf ( "\nAlterado\n" ) : printf ( "\nErro na alteração\n" );

			break;

			case  3 :

				clear ();

				printf ( "\nOrdem de inserção : \n" );

				showod ( &root );

			break;

			case 4 :

				clear ();

				printf ( "\nInforme a matrícula : " );
				scanf ( "%d", &mats );

				tmp = search ( &root, mats );

				if ( ! tmp ) {

					printf ( "\nMatrícula não encontrada\n" );

					break;

				}

				setbuf ( stdin, NULL );

				printf ( "\nInforme o novo e-mail para o cadastro de matrícula %d : ", mats );
				fgets ( nm, Tam, stdin );

				alterm ( &root, mats, nm ) == 1 ? printf ( "\nAlterado\n" ) : printf ( "\nErro na alteração\n" );

			break;

			case 5 :

				clear ();

				temp = getinfo ();

				addrec ( &root, temp );

			break;

			case 6 :

				clear ();

				printf ( "\nInforme a matrícula : " );
				scanf ( "%d", &mats );

				aux = search ( &root, mats );

				aux == NULL ? printf ( "\nMatrícula não encontrada\n" ) : printf ( "\n\n\t%s Cursa %s, sua matrícula é %d e seu e-mail é %s\n", aux -> person.name, aux -> person.course, aux -> person.mat, aux -> person.mail );

			break;

			case 7 :

				clear ();

				printf ( "\nOrdem crescente : \n" );

				showps ( &root );

			break;

			default :

				clear ();

				printf ( "\nOpção indisponível\n" );

		}

        printf ( "\nZero para sair ou outro número para continuar : " );
        scanf ( "%hu", &out );

        clear ();

        if ( ! out )
            exit ( 0 );

    }


    free ( tmp ); free ( aux );


    return 0;

}


void clear ( void ) {

    system ( "clear || cls" ); return;

}

void initialize ( Node ** root ) {

    ( * root ) = NULL; return;

}

int empty ( Node ** root ) {

    if ( ( * root ) == NULL )
        return 1;

    return 0;

}

Node * createno ( void ) {

    Node * temp = ( Node * ) calloc ( 1, sizeof ( Node ) );

    if ( temp == NULL )
        exit (1);

    return temp;

}

Info getinfo ( void ) {

	Info temp;

	printf ( "\nInformações :" );

	printf ( "\n\tInforme a matrícula : " );
	scanf ( "%d", &temp.mat );

	setbuf ( stdin, NULL );

	printf ( "\n\tInforme o nome : " );
	fgets ( temp.name, Tam, stdin );

	printf ( "\n\tInforme o curso : " );
	fgets ( temp.course, Tam, stdin );

	printf ( "\n\tInforme o e-mail : " );
	fgets ( temp.mail, Tam, stdin );

	return temp;

}

void addrec ( Node ** root, const Info cell ) {

    if ( empty ( root ) ) {

        ( * root ) = createno ();

        ( * root ) -> esq = NULL;

        ( * root ) -> dir = NULL;

        ( * root ) -> person = cell;

    } else {

        if ( cell.mat < ( * root ) -> person.mat )
            addrec ( & ( * root ) -> esq, cell );

        else
            addrec ( & ( * root ) -> dir, cell );

    }

	return;

}

void showps ( Node ** root ) {

    if ( ( * root ) ) {

        showps ( & ( * root ) -> esq );

        printf ( "\n\n\t%s Cursa %s, sua matrícula é %d e seu e-mail é %s\n", ( * root ) -> person.name, ( * root ) -> person.course, ( * root ) -> person.mat, ( * root ) -> person.mail );

        showps ( & ( * root ) -> dir );

    } // Tratar caso não tenha nenhum cadastro

}

void showod ( Node ** root ) {

    if ( ( * root ) ) {

        printf ( "\n\n\t%s Cursa %s, sua matrícula é %d e seu e-mail é %s\n", ( * root ) -> person.name, ( * root ) -> person.course, ( * root ) -> person.mat, ( * root ) -> person.mail );

        showod ( & ( * root ) -> esq );

        showod ( & ( * root ) -> dir );

    }

}

Node * search ( Node ** root, const int mats ) {

    Node * tp = NULL;

    if ( ! ( * root ) )
        return NULL;

    if ( ( * root ) -> person.mat == mats )
        return ( * root );

    tp = search ( & ( * root ) -> esq, mats );

    if ( tp )
        return tp;

    return search ( & ( * root ) -> dir, mats );

}

int alterc ( Node ** root, const int mats, char * ncourse ) {

    Node * aux = search ( root, mats );

    if ( ! aux )
        return 0;

    strcpy ( aux -> person.course, ncourse );

    return 1;

}

int alterm ( Node ** root, const int mats, char * nmail ) {

	Node * aux = search ( root, mats );

    if ( ! aux )
        return 0;

    strcpy ( aux -> person.mail, nmail );

    return 1;

}
