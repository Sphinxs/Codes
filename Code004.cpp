
# include <stdio.h>


typedef struct {
        char rua [30];
        int num;
} Endereco;

typedef struct {
        char nome [30], telefone [20];
        int produtos;
        Endereco end;
} Fornecedor;


void imprime ( Fornecedor * forn, int ini, int fim ) {

    if ( ini <= fim ) {

        printf ( "\n\nDados do fornecedor %d:\n", ini + 1 );

        printf ( "Nome: %s\n", forn [ini].nome );

        printf ( "Produtos: %d\n", forn [ini].produtos );

        printf ( "Telefone %s\n", forn [ini].telefone );

        printf ( "Rua: %s\n", forn [ini].end.rua );

        printf ( "Numero: %d\n", forn [ini].end.num );

        imprime ( forn, ini + 1, fim );

    }

}


int main ( void ) {

    FILE * f;


    f = fopen ( "forn.bin", "rb" );

    if ( f == NULL ) {
       return 1;


    int n = 0;

    fread ( &n, sizeof( int ), 1, f );

    Fornecedor * forn;

    forn = ( Fornecedor * ) calloc ( 1, sizeof ( Fornecedor ) );


    fread ( forn, sizeof ( Fornecedor ), n, f );


    imprime ( forn, 0, n - 1 );


    int i;

    int ind = 0, maior = forn [0].produtos;

    for ( i = 0; i < n; i++ ) {

         if ( forn [i].produtos > maior ) {

            maior = forn [i].produtos;

            ind = i;

        }

    }

    printf ( "\n\nFornecedor com mais produtos : %s\n", forn[ind].nome );


    free(forn);

    fclose(f);


    return 0;

}
