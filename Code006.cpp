
# include <stdio.h>

# include <stdlib.h>

# include <string.h>


typedef struct Pessoa {

    char marca[20], cor[15];

    int portas, preco;

} Peso;


int main (void) {

    Peso carro;

    FILE *bin;
    
    bin = fopen ( "informacoes.bin", "rb" );

    if ( bin == NULL ) {

        exit(1);

    }
    
        int gravado;

        gravado = fread( &carro , sizeof(Peso), 1, bin);
        
                printf("%s %s %i %i",carro.marca,carro.cor,carro.portas,carro.preco);

    fclose(bin); 
    
    return 0;
    
}
