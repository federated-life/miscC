#include <api_header.h>
#include <stdio.h>

int main() {

	/* char string[50];
	printf("gimmie a string: ");
	gets(string); */

	char string[]="blahyadda";
	char outfile[]="myfile.txt";

  /* call a function in another file */
  myPrintHelloMake();
  myLoopPrint();
  /* curl_a_page();
  test_suite_1(); */

	thingy();
	write_out(string);

	write_to_file(string, outfile);

  return(0);
}
