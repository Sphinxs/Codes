
# include <stdio.h>

# include <string.h>

# include <stdlib.h>


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


int main ( int argv, const char * argc [] ) {

    Node * list = NULL;

    empty ( &list ) == 1 ? printf("\n\nEmpty !\n\n") : printf("\n\nHave Itens !\n\n");

    addstart ( &list );

    clear ();

    addend ( &list );

    clear ();

    noteone ( &list );

    // showlist ( &list );

    showmedia ( &list );

    removeall ( &list );

    showlist ( &list );
    
    return 0;

}

void clear ( void ) {

    system ("clear");

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

    // register int cont = 0;

    printf("\nWhat's your registry : ");
    scanf("%d", &( * temp ) -> info.regis);

    setbuf ( stdin , NULL );

    printf("\nWhat's your name : ");
    fgets(( * temp ) -> info.name, 25, stdin);

    /* // With for I have problems

        for ( ; cont ++ < 3 ; ) {
            printf("\n\tWhat's your note in proof %d : ", cont);
            scanf("%f", &( * temp ) -> info.proof [cont]);
        }

    */

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

        return 0;

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

        printf("\nList empty !\n\n");

    } else {

        Node * aux = ( * list );

        if ( aux == NULL ) {

        	exit (1);

        }

        printf("\nList\n");

        while ( aux != NULL ) {

            printf("\n\t( %s - %d )\n", aux -> info.name, ( int ) aux -> info.regis);

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

    	exit (1);

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

    while ( tmp != NULL ) {

        aux = tmp;

        tmp = tmp -> next;

        free(aux);

    }

    ( * list ) = NULL;

}

void showmedia ( Node ** list ) {

    float med;

    Node * aux = ( * list );

    while( aux != NULL ) {

        med = ( aux -> info.proof[0] + aux -> info.proof[1] + aux -> info.proof[2] ) / 3;

        printf("\n%s - %d - %.2f\n", aux -> info.name, aux -> info.regis, med);

        aux = aux -> next;

    }

}
