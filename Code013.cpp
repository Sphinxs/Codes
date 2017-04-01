
# include <stdio.h>

# include <locale.h>

# include <stdlib.h>

# include <string.h>

# include <stdbool.h>


# define max 15


typedef struct {
	char nome [20];
	float preco;
} item;

typedef struct {
	item itens [max];
	int ultimo;
} list;


// Prototipos

void limpa (); // Limpa a tela

void inicializa (list * dados); // Inicializa a estrutura

void addfinal (list * dados, const char nome[], const float preco); // Adiciona um item no final

int tamanho (const list * dados); // Retorna o tamanho da lista

float maiorprec (const list * dados); // Retorna o maior valor em float

void imprimi (const list * dados); // Imprime todos os dados da estrutura

void addposn (list * dados, const int indice, const char nome[], const float preco); // Adiciona na posição do indice informado


int main ( int argv, const char * argc [] ) {

	setlocale(LC_ALL, "");

	list dados;

	int escolha = 0;

	do {

		printf("\n\n6 - Adicionar Por Indice\n\n5 - Imprimi Estrutura\n\n4 - Maior Valor Tda\n\n3 - Tamanho Do Tda\n\n2 - Adicionar Item\n\n1 - Inicializar\n\n0 - Para Sair\n\n");

		printf("\nInforme sua escolha :\t");
		scanf("%d", &escolha);

		switch (escolha) {

			case 0:
				limpa(); exit(0);
			break;

			case 1:
				limpa(); inicializa (&dados);
			break;

			case 2:

				limpa();

				float preco;

				char nome [20];

				printf("\nInforme o preço : ");
				scanf("%f", &preco);

				// Não remover o espaço - Complicações do linux com buffer

				printf("\nInforme o nome : ");
				scanf(" %s", nome);

				addfinal (&dados, nome, preco); limpa();

			break;

			case 3:
				limpa(); printf("\nA grandeza da estrutura é : %d\n", tamanho (&dados));
			break;

			case 4:
				limpa(); printf("\nO maior valor é : %.2f\n", maiorprec (&dados));
			break;

			case 5:
				limpa(); imprimi (&dados);
			break;

			case 6:

				limpa();

				int indice;

				float prec;

				char nom [20];

				printf("\nInforme o indice : ");
				scanf("%d", &indice);

				printf("\nInforme o preço para posição informada : ");
				scanf("%f", &prec);

				// Não remover o espaço - Complicações do linux com buffer

				printf("\nInforme o nome  para posição informada : ");
				scanf(" %s", nom);

				addposn (&dados, indice, nom, prec); limpa();

			break;

			default:
				limpa(); printf("\nOpção invalida !\n");
			break;

		}

	} while ( true );

	return 0;

}


void limpa () {
	system("clear || cls");
}

void inicializa (list * dados) {
	dados -> ultimo = -1;
}

void addfinal (list * dados, const char nome[], const float preco) {
	if ( dados -> ultimo >= max ) {

		printf("\nErro na estrutura !\n"); exit(1);

	} else {

		dados -> ultimo += 1;

		strcpy(dados -> itens[dados -> ultimo].nome, nome);

		dados -> itens[dados -> ultimo].preco = preco;

	}
}

int tamanho (const list * dados) {
	if (dados -> ultimo <= -1)
		return -1;
	else
		return dados -> ultimo + 1;
}

float maiorprec (const list * dados) {
	if(dados -> ultimo <= -1) {

		printf("\nErro - Estrutura vazia !\n"); exit(1);

	} else {

		float maior = 0;

		register int con = 0;

		for ( ; con < dados -> ultimo; con ++ ) {
			if (dados -> itens [dados -> ultimo].preco > maior)
				maior = dados -> itens [dados -> ultimo].preco;
		}

		return maior;

	}
}

void imprimi (const list * dados) {
	if (dados -> ultimo <= -1) {

		printf("\nImpossível imprimir os dados, estrutura vazia !\n"); exit(1);

	} else {

		register int con = 0;

		printf("\nTodos os dados da estrutura :\n");

		for ( ; con <= dados -> ultimo; con ++ ) {
			printf("\n\n\t%s - %.2f\n", dados -> itens[con].nome, dados -> itens[con].preco);
		}

	}
}

void addposn (list * dados, const int indice, const char nome[], const float preco) {
	if (indice > dados -> ultimo) {

		printf("\nIndice maior que disponível !\n"); exit(1);

	} else if ( indice <= -1 ) {

		printf("\nErro - Estrutura vazia, impossível adicionar !\n"); exit(1);

	} else {

		dados -> ultimo += 1;

		int con = dados -> ultimo;

		for ( ; con > dados -> ultimo; con -- ) {
			dados -> itens [con] = dados -> itens[con - 1];
		}

		strcpy(dados -> itens[indice].nome, nome);

		dados -> itens[indice].preco = preco;
	}
}
