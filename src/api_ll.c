#include <stdlib.h>
#include <stdio.h>
#include <api_header.h>

struct node {
  int x;
  struct node *next;
};

int thingy(void) {

	struct node *root;

	root = (struct node *) malloc( sizeof(struct node) );

	root->next = 0;

	root->x = 5;

	printf( "thing \n" );

	return 0;

}

void write_to_file(char string[], char outfile[]) {
	/* do stuff */
	printf( "a: %c , b: %c \n", string[0],	outfile[0]);
}

int write_out(char string[] ) {

	int x;
	for ( x=0; x<10; x++ ) {
		printf( "checking val: %d \n", x );
		printf( "val: %c \n" , string[x] );
	}

	return 0;
}



