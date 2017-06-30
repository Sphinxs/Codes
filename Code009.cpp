
# include <stdio.h>

# include <stdlib.h>

# include <stdbool.h>


# define max 50

int inst;

int stack [max];


void construct ();

bool empty ();

void push ( int value );

bool pop ( int &send );

int items ();


int main ( void ) {

	int trash = 0;


	construct();

	push(000);

	pop(trash);


	return 0;

}


void construct () {

	inst = -1;

}


bool empty () {

	if ( inst == -1 )
		return true;

	else
		return false;

}


void push ( int value ) {

	if(inst >= max)
		exit(1);

	else {
		inst ++; stack[inst] = value;
	}

}


bool pop ( int &send ) {

	if ( inst < 1 )
		exit(1);

	else {
		send = stack[inst]; inst --;
	}

}

int items () {

	return inst + 1;

}
