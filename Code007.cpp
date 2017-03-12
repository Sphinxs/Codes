
// Diretivas de pré processamento

# include <stdio.h>

# include <time.h>

# include <stdint.h>

# include <locale.h>

/*
	<time> De fato obtém o tempo
	<locale> Indica o idioma utf-8
	<stdio> Entrada e saída padrão
	<stdint> Auxilia na formatação
*/

// Argumentos de linha de comando ( Argc, Argv )

int main ( int argc, char const *argv[] ) {

	setlocale(LC_ALL,"");

	time_t resultado = time(NULL);

	// Caso retorne ' -1 ' o valor retornado foi estourado ( Undexflow / Overflow )

    	if( resultado != -1) {

        	printf("\n\nHora da execução: %s\n", asctime(gmtime(&resultado)), (uintmax_t)resultado);

	}

	return 0;

}
