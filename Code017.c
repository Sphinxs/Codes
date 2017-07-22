
# include <stdio.h>

# include <stdlib.h>

# include <locale.h>


void fatal ( const char * msg );


int main ( int argc, const char * argv [] ) {

    setlocale ( LC_ALL, "" );


    FILE * Arch;

    if ( argc != 2 )
        fatal ( "Argumentos : Informe o nome do arquivo" );

    Arch = fopen ( argv [1], "rb" );

    if ( Arch == NULL )
        fatal ( "Arquivo : Informe um arquivo valido" );


    unsigned char cache [32];

    if ( fread ( cache, 32, 1, Arch ) != 1 )
        fatal ( "Leitura : Erro ao ler o arquivo" );

    fclose ( Arch );

    // ' Letra ' : Retorna um número hexadecimal

    if ( cache [0] != 'M' || cache [1] != 'Z' )
        fatal ( "Extensão : O arquivo não é executável Pe" );


    return 0;

}


void fatal ( const char * msg ) {

    fprintf ( stderr, "\n\nErro - %s\n\n\n", msg );

    exit ( 1 );

}
