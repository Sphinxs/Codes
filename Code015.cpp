

# include <stdio.h>

# include <string.h>


# define Qt 10 // Quantidade máxima de itens


typedef struct {
        char name[40];
        char label[40];
        int pages;
} Info;

typedef struct {
        Info hq[Qt];
        int top;
} Stack;


void initialize ( Stack * pilha ); // Inicializa a pilha

int empty ( Stack * pilha ); // Verifica se está vazia

int full ( Stack * pilha ); // Verifica se está cheia

int push ( Stack * pilha, Info data ); // Adiciona no topo

Info pop ( Stack * pilha ); // Deleta do topo

Info head ( Stack * pilha ); // Retorna topo sem deletar

void show ( Stack * pilha ); // Imprime deletando

void showemp ( Stack * pilha ); // Imprime sem deletar


int main ( int argv, const char * argc [] ) {

    Stack pilha;


    initialize ( &pilha );

    // empty ( &pilha );

    // full ( &pilha );


    {
        Info tp1; strcpy( tp1.name, "Darth" ); strcpy ( tp1.label, "Sci-fy"), tp1.pages = 200; // 3 º
        
        Info tp2; strcpy( tp2.name, "Yoda" ); strcpy ( tp2.label, "Sci-fy"), tp2.pages = 300; // 2 º
        
        Info tp3; strcpy( tp3.name, "Luke" ); strcpy ( tp3.label, "Sci-fy"), tp3.pages = 400; // 1 º

        push ( &pilha, tp1 );
   
    	push ( &pilha, tp2 );
    
    	push ( &pilha, tp3 );
    }


    /*
    
        Info test; test = pop ( &pilha );

        printf ("\n%s - %s - %d\n\n", test.name, test.label, test.pages);

        test = head ( &pilha );
        
        printf ("\n%s - %s - %d\n\n", test.name, test.label, test.pages);
        
    */


	showemp ( &pilha );
		
    show ( &pilha );


    return 0;

}


void initialize ( Stack * pilha ) {
        
    pilha -> top = -1; return;

}

int empty ( Stack * pilha ) {
        
    if ( pilha -> top <= -1 ) return 1;
        
    return 0;

}

int full ( Stack * pilha ) {

    if ( pilha -> top == ( Qt - 1 ) ) return 1;

    return 0;

}

int push ( Stack * pilha, const Info data ) {

    if ( full ( pilha ) ) return 0;

    pilha -> top ++;

    pilha -> hq [ pilha -> top ] = data;

    return 1;

}

Info pop ( Stack * pilha ) {

    Info temp; temp.pages = -1;

    if ( empty ( pilha ) ) return temp;

    temp = pilha -> hq [ pilha -> top ];

    pilha -> top --;

    return temp;

}

Info head ( Stack * pilha ) {

        Info temp; temp.pages = -1;

        if ( empty ( pilha ) ) return temp;

        temp = pilha -> hq [ pilha -> top ];

        return temp;

}

void show ( Stack * pilha ) {

    if ( empty ( pilha ) ) return;

    Info temp;
        
    int top = 0;
        
    for ( ; top <= ( pilha -> top ); top ++ ) {

        temp = pop ( pilha );

        printf ("\n%s - %s - %i\n", temp.name, temp.label, temp.pages);
                
    }

}

void showemp ( Stack * pilha ) {
	
	if ( empty ( pilha ) ) return;
	
	Info tmp;
	
	Stack aux;
	
	initialize ( &aux );
	
	while ( pilha -> top != -1 ) {
		
		tmp = pop ( pilha );
		
		printf ("\n%s - %s - %d\n\n", tmp.name, tmp.label,  tmp.pages );
		
		push ( &aux, tmp );
			
	}
	
	while ( aux.top != -1 ) {
		
		push ( pilha, pop ( &aux ) );
			
	}
	
}
