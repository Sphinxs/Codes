
# include <stdio.h>

# include <string.h>

# include <stdlib.h>

# include <locale.h>


typedef struct {
    char name[25];
    int regis;
    float proof[3];
} Info;

typedef struct node {
    Info info;
    struct node * next;
} Node;


void clear ( void );

int empty ( Node ** list );

Node * newnode ();

void getdata ( Node ** temp );

int addstart ( Node ** list );

int addend ( Node ** list );

void showlist ( Node ** list );

void noteone ( Node ** list );

void removeall ( Node ** list );

void showmedia ( Node ** list );

Node * searchreg ( Node ** list, int regis ); //

void transposition ( Node ** list, char * name ); //


int main ( int argv, const char * argc [] ) {

    setlocale ( LC_ALL, " " );

    Node * list = NULL;

    unsigned short int out = 0, opt = 0;

    do {


        printf("\n0 - Go Out\n\n1 - Add End\n\n2 - Add Start\n\n3 - Show List\n\n4 - Higher note\n\n5 - Remove List\n");

        printf("\n6 - Show Medias\n");


        printf("\nWhat's your option : ");
        scanf("%hu", &opt);

        switch ( opt ) {

            case 0:
                exit (0);
            break;

            case 1:
                clear ();  addend ( &list );
            break;

            case 2:
                clear (); addstart ( &list );
            break;

            case 3:
                clear (); showlist ( &list );
            break;

            case 4:
                clear (); noteone ( &list );
            break;

            case 5:
                clear (); removeall ( &list );
            break;

            case 6:
                clear (); showmedia ( &list );
            break;

            default:
                exit(1);

        }

        printf("\nZero to exit or other number to continue : ");
        scanf("%hu", &out); clear ();

    } while ( out != 0 );

    return 0;

}

void clear ( void ) {

    system ("clear || cls");

}

int empty ( Node ** list ) {

    if ( (* list) == NULL ) {

        return 1;

    }

    return 0;

}

Node * newnode () {

    Node * temp = ( Node * ) malloc ( sizeof ( Node ) );

    return temp;

}

void getdata ( Node ** temp ) {

    printf("\nWhat's your registry : ");
    scanf("%d", &( * temp ) -> info.regis);

    setbuf ( stdin , NULL );

    printf("\nWhat's your name : ");
    fgets(( * temp ) -> info.name, 25, stdin);

    printf("\n\tWhat's your note in proof 1 : ");
    scanf("%f", &( * temp ) -> info.proof [0]);

    printf("\n\tWhat's your note in proof 2 : ");
    scanf("%f", &( * temp ) -> info.proof [1]);

    printf("\n\tWhat's your note in proof 3 : ");
    scanf("%f", &( * temp ) -> info.proof [2]);

}

int addstart ( Node ** list ) {

    Node * cell = newnode ();

    if ( cell == NULL ){

        return 0; // Error

    }

    getdata ( &cell );

    if ( empty ( list ) ) {

        cell -> next = NULL;

        (* list) = cell;

    } else {

        cell -> next = ( * list );

        ( * list ) = cell;

    }

    return 1;

}

int addend ( Node ** list ) {

    Node * news = newnode ();

    Node * aux = ( * list );

    if ( news == NULL ) {

        return 0;

    }

    getdata ( &news );

    news -> next = NULL;

    if ( empty ( list ) ) {

        ( * list ) = news;

        return 1;

    }

    while ( aux -> next != NULL ){

        aux = aux -> next;

    }

    aux -> next = news;

    return 1;

}

void showlist ( Node ** list ) {

    if ( empty ( list ) ) {

        printf("\nList empty - Show List\n\n");

    } else {

        Node * aux = ( * list );

        if ( aux == NULL ) {

        	exit (1);

        }

        printf("\nList\n");

        while ( aux != NULL ) {

            printf("\n\tName : %s - Registry : %d", aux -> info.name, ( int ) aux -> info.regis);

            	printf("\n\t\tProof 1 : %.2f", aux -> info.proof [0]);

            	printf("\n\t\tProof 2 : %.2f", aux -> info.proof [1]);

            	printf("\n\t\tProof 3 : %.2f\n", aux -> info.proof [2]);

            aux = aux -> next;

        }

    }

}

void noteone ( Node ** list ) {

    Node * aux = ( * list );

    if ( aux == NULL ) {

    	printf("\nList Empty - Note\n"); return;

    }

    if ( empty ( list ) ) {

        printf("\nList empty !\n");

    } else {

        while ( aux != NULL ) {

            if ( aux -> info.proof [1] >= 60 ) {

                printf("\n\n%s - %.2f points\n\n", aux -> info.name, aux -> info.proof [0]);

            }

            aux = aux -> next;

        }

    }

}

void removeall ( Node ** list ) {

    Node * tmp = ( * list ), * aux;

    if ( empty ( list ) ) {

        printf("\nList Empty - Remove\n"); return;
    }

    while ( tmp != NULL ) {

        aux = tmp;

        tmp = tmp -> next;

        free(aux);

    }

    ( * list ) = NULL;

    printf("\nRemoved !\n");

}

void showmedia ( Node ** list ) {

    float med = 0.0;

    Node * aux = ( * list );

    if ( empty ( list ) ) {

        printf("\nList Empty - Media\n"); return;

    }

    while( aux != NULL ) {

        med = ( aux -> info.proof[0] + aux -> info.proof[1] + aux -> info.proof[2] ) / 3;

        printf("\nName : %s - Registry : %d - Note : %.2f\n", aux -> info.name, aux -> info.regis, med);

        aux = aux -> next;

    }

}

Node * searchreg ( Node ** list, int regis ) {

    Node * aux = ( * list );

    if ( empty (list) ) {

        printf("\n\nEmpty - Search\n\n");

        return NULL;

    }

    while ( aux != NULL ) {

        if ( aux -> info.regis == regis ) {
            return aux;
        }

        aux = aux -> next;

    }

    return NULL;

}

void transposition ( Node ** list, char * name ) {

		Node * aux = ( * list );

		Node * ant = NULL;

		if ( empty ( list ) ) {

            printf("\nEmpty - Transposition\n"); return;

		}

		while ( aux != NULL || strcmp ( aux -> info.name, name) == 0 ) {

			ant = aux;

			aux = aux -> next;

		}

		if ( aux == NULL ) {

            printf("\nNot Found - Transposition\n"); return;

		} else {

            printf("\n\n%s - %d\n\n", aux -> info.name, aux -> info.regis);

            Info tmp = ant -> info;

            ant -> info = aux -> info;

            aux -> info = tmp;

		}

}
