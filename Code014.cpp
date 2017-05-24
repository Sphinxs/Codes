
# include <time.h>

# include <stdio.h>

# include <stdlib.h>

# include <string.h>

# include <locale.h>

# define Lenstr 50

# define Grn "\x1B[32m"

static int Items = 0;


typedef struct {
	char nick [Lenstr];
	char element [Lenstr];
	int strength;
} Info;

typedef struct no {
	Info fighter;
	struct no * next;
} Node;

typedef struct {
	Node * hom;
	Node * end;
} Queue;


void clear ( void );

void initialize ( Queue * fl );

int empty ( Queue * fl );

void helpempty ( Queue * fl1, Queue * fl2 );

Node * createnode ( void );

int add ( Queue * fl, Info data );

void helpadd ( Queue * fl1, Queue * fl2 );

Info des ( Queue * fl );

void helpdes ( Queue * fl1, Queue * fl2 );

void show ( Queue * fl );

void helpshow ( Queue * fl1, Queue * fl2 );


int main ( int argv, const char * argc [] ) {


	setlocale ( LC_ALL, "" );

	srand ( time ( NULL ) );


	Queue fl1;

	Queue fl2;

	initialize ( &fl1 ); initialize ( &fl2 );


	unsigned int out = 0; // Exit

	unsigned int cho = 0; // Choose


	do {

		printf ("\n0 - Exit\n\n1 - Empty\n\n2 - Add Item\n\n3 - Deworming\n\n4 - Show Queue\n\n5 - How Many Queues\n\n");

		printf ("\nWhat's your choose : ");
		scanf ("%u", &cho);

		switch ( cho ) {

			case 0:

				clear (); exit (0);

			break;

			case 1:

				clear (); helpempty ( &fl1, &fl2 );

			break;

			case 2:

				clear (); helpadd ( &fl1, &fl2 );

			break;

			case 3:

				clear (); helpdes ( &fl1, &fl2 );

			break;

			case 4:

				clear (); helpshow ( &fl1, &fl2 );

			break;

			case 5:

				clear (); printf ("\nBoth queues has %d items\n\n", Items);

			break;

			case 42:

                clear (); { printf (Grn "\nThe answer to life, the universe and everything ( :\n\n"); }

            break;

			default:

				clear ();

				printf ("\nThis option is not available\n\n");

		}

		printf ("\nZero to go out or other digit to continue : ");
		scanf ("%u", &out); clear ();

	} while ( out != 0 );

	return 0;

}

void clear ( void ) {

	system ("clear || cls"); return;

}

void initialize ( Queue * fl ) {

	fl -> hom = NULL; fl -> end = NULL; return;

}

int empty ( Queue * fl ) {

	if ( fl -> hom == NULL && fl -> end == NULL ) return 1;

	return 0;

}

void helpempty ( Queue * fl1, Queue * fl2 ) {

	int check = 0;

	printf ("\nPress 1 to check the first queue or 2 to second : ");
	scanf ("%d", &check);

	clear ();

	if ( check == 1 ) {

		empty ( fl1 ) == 1 ? printf ("\nFirst queue is empty\n\n") : printf ("\nFirst queue has items\n\n");

	} else if ( check == 2 ){

		empty ( fl2 ) == 1 ? printf ("\nSecond queue is empty\n\n") : printf ("\nSecond queue has items\n\n");

	} else {

		clear (); printf ("\nThis option is not available - Add Queue\n\n");

	}

}

Node * createnode ( void ) {

	Node * temp = ( Node * ) calloc ( 1, sizeof ( Node ) );

	return temp;

}

int add ( Queue * fl, Info data ) {

	Node * temp = createnode ();

	if ( temp == NULL ) return 0;

	temp -> fighter = data;

	temp -> next = NULL;

	if ( empty ( fl ) ) {

		fl -> hom = temp;

		fl -> end = temp;

		Items ++;

		return 1;

	}

	fl -> end -> next = temp;

	fl -> end = temp;

	Items ++;

	return 1;

}

void helpadd ( Queue * fl1, Queue * fl2 ) {

	Info temp;

	{
		setbuf ( stdin, NULL );

		printf ("\nWhat's your nick name : ");
		fgets (temp.nick, Lenstr, stdin);
	}

	int aleatory = 0, cho = 0;

	aleatory = rand () % 4;

	switch (aleatory) {

		case 4:

		case 0:
			strcpy (temp.element, "Ar");
		break;

		case 1:
			strcpy (temp.element, "Água");
		break;

		case 2:
			strcpy (temp.element, "Fogo");
		break;

		case 3:
			strcpy (temp.element, "Terra");
		break;

		default:

			strcpy (temp.element, "Error");

	}

	temp.strength = 900 + rand () % 200;

	printf ("\nOne to add in first queue or two to add in second queue : ");
	scanf ("%d", &cho);

	if ( cho == 1 ) {

		add ( fl1, temp );

	} else if ( cho == 2 ) {

		add ( fl2, temp );

	} else {

		printf ("\nThis chosse is not available - Add\n\n");

	}

}

Info des ( Queue * fl ) {

	Info temp; temp.strength = -1;

	if ( empty ( fl ) ) return temp;

	temp = fl -> hom -> fighter;

	if ( fl -> hom == fl -> end ) {

		free ( fl -> hom );

		initialize ( fl );

		Items --;

	} else {

		Node * aux = fl -> hom;

		fl -> hom = fl -> hom -> next;

		free ( aux );

		Items --;

	}

	return temp;

}

void helpdes ( Queue * fl1, Queue * fl2 ) {

	int check = 0;

	printf ("\nPress 1 to deworming the first queue or 2 to second queue : ");
	scanf ("%d", &check);

	Info temp;

	if ( check == 1 ) {

		temp = des ( fl1 );

		temp.strength == -1 ? printf ("\nQueue 1 is empty - Deworming\n\n") : printf ("\n1 - %s - %s - %d\n\n", temp.nick, temp.element, temp.strength);

	} else if ( check == 2 ) {

		temp = des ( fl2 );

		temp.strength == -1 ? printf ("\nQueue 2 is empty - Deworming\n\n") : printf ("\n2 - %s - %s - %d\n\n", temp.nick, temp.element, temp.strength);

	} else {

		clear (); printf ("\nThis option is not available - Deworming\n\n");

	}

}

void show ( Queue * fl ) {

	if ( empty ( fl ) ) {
		
		printf ("\nQueue is empty - Show Queue\n\n"); return;

	}

	Queue tp;

	Info temp;

	clear (); puts ("\nQueue\n");
	
	while ( empty ( fl ) != 1) {
		
		temp = des ( fl );

		printf ("\n\t%s - %s - %d\n", temp.nick, temp.element, temp.strength);

		add ( &tp, temp );

	}

	while ( empty ( &tp ) != 1 ) {

		temp = des ( &tp );

		add ( fl, temp );

	}

}

void helpshow ( Queue * fl1, Queue * fl2 ) {

	int check = 0;

	printf ("\nPress 1 to show first queue or 2 to show the second queue : ");
	scanf ("%d", &check);

	if ( check == 1 ) {

		show ( fl1 );

	} else if ( check == 2 ) {

		show ( fl2 );

	} else {

		clear (); printf ("\nThis option is not available - Show Queue\n\n");

	}

}
