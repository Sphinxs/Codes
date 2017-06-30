
# include <stdio.h>

# include <time.h>

# include <stdint.h>

# include <locale.h>


int main ( int argc, char const * argv [] ) {

	setlocale ( LC_ALL, "" );


	time_t resultado = time ( NULL );


    if( resultado != -1 )
        printf("\n\nExecução: %s\n", asctime ( gmtime ( &resultado ) ), ( uintmax_t ) resultado );


	return 0;

}
