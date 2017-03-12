
# include <stdio.h>

# include <stdbool.h>

# include <stdlib.h>

# include <locale.h>

/*
    Programa em linguagem ' c ' que verifica se um número é primo ou não.

    Lembrando que números primos são aqueles que apenas pode ser divididos
    por 1 e si mesmos.

*/

int main ( void ) {

    setlocale(LC_ALL,"");

    while (true) {

        short int num = 0, apoio = 1;

        do {
            printf("\nInforme um digito: ");
            scanf("%hi", &num);
        } while (num < 0);

        for(int cont = 1; cont < num; cont++) {
            if (num % cont == 0) {
                apoio++;
            }
        }

        if (apoio == 2) {
            printf("\n%hi - É primo !\n", num);
        } else {
            printf("\n%hi - Não é primo !\n", num);
        }

        unsigned int escolha = 0;

        printf("\n0 Para sair ou outro digito para continuar: ");
        scanf("%u", &escolha); puts("");

        if(escolha == 0) {
            break;
        } else {
            system("clear");
        }

    }

}
