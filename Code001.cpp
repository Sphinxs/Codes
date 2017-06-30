
# include <stdio.h>


typedef struct {
        char nome [30];
        int idade;
} Pessoa;


int main ( void ) {

    Pessoa * v;

    int n;

    FILE * f;


    f = fopen ( "dados.txt", "r" );

    if ( f == NULL ){
       return 1;

    fscanf ( f, "%d", &n );


    v = ( Pessoa * ) calloc ( 1, sizeof ( Pessoa ) );


    int maior, ind;

    int register i = 0;


    for ( ; i<n; i++ ) {

        fscanf ( f, "%s", v[i].nome );

        fscanf ( f, "%d", &v[i].idade );

        if ( i == 0 ) {

            maior = v[i].idade;

            ind = i;
        }

        if ( v [i].idade > maior ) {

            maior = v[i].idade;

            ind = i;

        }

    }

    printf("A pessoa mais velha chama-se %s e tem %d anos.\n", v [ind].nome, v [ind].idade);


    free ( v );

    fclose ( f );


    return 0;

}
