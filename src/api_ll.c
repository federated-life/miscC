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

	printf( "thing" );

	return 0;

}

int write_out(char string[50] ) {

	int x;
	for ( x=0; x<10; x++ ) {
		printf( "val: %s" , string[x] );
	}

	return 0;
}



