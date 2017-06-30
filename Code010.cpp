
# include <stdio.h>

# include <stdlib.h>


int main ( void ) {

    // 1 Ordenado - 0 Desordenado

    unsigned vet [] = {1,2,3,4,5}, con = 0, res = 1;


    for ( ; con < sizeof ( vet - 1 ); con++ ) {
        if ( vet[con] > vet[con + 1] ) {
            res = 0; exit ( 1 );
        }
    }

    res == 1 ? printf ( "\nOrdenado !\n" ) : printf( "\nDesordenado !\n" );


    return 0;

}
