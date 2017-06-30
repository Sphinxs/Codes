
# include <stdio.h>

# include <string.h>


void decrescente ( char * vet, int ini, int fim ){

    if ( ini <= fim ) {

        decrescente ( vet, ini + 1, fim );

        printf ( "%c", vet [ini] );

    }

    return;

}

int main ( void ) {

    char vetor [100];


    gets ( vetor );

    decrescente ( vetor, 0, strlen( vetor ) - 1 );


    return 0;

}
