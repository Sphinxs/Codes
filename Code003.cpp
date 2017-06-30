
# include <stdio.h>


typedef struct {
        char rua [30];
        int num;
} Endereco;

typedef struct {
        char nome [30];
        int produtos;
        char telefone [20];
        Endereco end;
} Fornecedor;


int main ( void ) {

    FILE * f;


    f = fopen ( "forn.txt", "w" );

    if ( f == NULL ) {
       return 1;


    int n = 0;

    printf ( "Numero de fornecedores : ");
    scanf ( "%d", &n );

    fprintf ( f, "%d\n", n );


    Fornecedor * forn;

    forn = ( Fornecedor * ) calloc ( 1, sizeof ( Fornecedor ) );

    int i = 0;

    for ( ; i<n; i++ ) {

        setbuf ( stdin, NULL);

        printf("\nNome do fornecedor : \n");
        gets ( forn[i].nome );

        printf("\nQuantidade de produtos : \n");
        scanf ( "%d", &forn[i].produtos );

        printf ("\nTelefone do fornecedor : \n");
        gets ( forn[i].telefone );

        printf ("\nDigite o nome da rua : \n");
        gets ( forn[i].end.rua );

        printf("\nDigite o numero : \n");
        scanf ( "%d", &forn[i].end.num );


        fprintf ( f, "%s\n", forn[i].nome);

        fprintf ( f, "%d\n", forn[i].produtos);

        fprintf ( f, "%s\n", forn[i].telefone);

        fprintf ( f, "%s\n", forn[i].end.rua);

        fprintf ( f, "%d\n", forn[i].end.num);

    }


    free ( forn );

    fclose ( f );


    return 0;

}
