#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <curl/curl.h>
#include <api_header.h>
#include <parson.h>

static int tests_passed;
static int tests_failed;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define TEST(A) printf("%-72s-",#A);              \
                if(A){puts(" OK");tests_passed++;} \
                else{puts(" FAIL");tests_failed++;}
#define STREQ(A, B) ((A) && (B) ? strcmp((A), (B)) == 0 : 0)
#define EPSILON 0.000001

void test_suite_1(void) {
  JSON_Value *val;
  TEST((val = json_parse_file("tests/test_1_1.txt")) != NULL);
  TEST(json_value_equals(json_parse_string(json_serialize_to_string(val)), val));
  if (val) { json_value_free(val); }
  TEST((val = json_parse_file("tests/test_1_2.txt")) != NULL);
  TEST(json_value_equals(json_parse_string(json_serialize_to_string(val)), val));
  if (val) { json_value_free(val); }
  TEST((val = json_parse_file("tests/test_1_3.txt")) != NULL);
  TEST(json_value_equals(json_parse_string(json_serialize_to_string(val)), val));
  if (val) { json_value_free(val); }

  TEST((val = json_parse_file_with_comments("tests/test_1_1.txt")) != NULL);
  TEST(json_value_equals(json_parse_string(json_serialize_to_string(val)), val));
  if (val) { json_value_free(val); }
  TEST((val = json_parse_file_with_comments("tests/test_1_2.txt")) != NULL);
  TEST(json_value_equals(json_parse_string(json_serialize_to_string(val)), val));
  if (val) { json_value_free(val); }
  TEST((val = json_parse_file_with_comments("tests/test_1_3.txt")) != NULL);
  TEST(json_value_equals(json_parse_string(json_serialize_to_string(val)), val));
  if (val) { json_value_free(val); }
}

void myPrintHelloMake(void) {

  printf("Hello makefiles!\n");

  return;
}

void myLoopPrint(void) {

  int i;
  for ( i=0 ; i<10; i++ ) {

    printf("dude...\n");

  }

  return;
}

int curl_a_page(void) {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
	  if(curl) {
	  curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
	  /* example.com is redirected, so we tell libcurl to follow redirection */ 
	  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
 
	  /* Perform the request, res will get the return code */ 
	  res = curl_easy_perform(curl);
	  /* Check for errors */ 
	  if(res != CURLE_OK)
		  fprintf(stderr, "curl_easy_perform() failed: %s\n",
				  curl_easy_strerror(res));
 
	  /* always cleanup */ 
	  curl_easy_cleanup(curl);
	}
	return 0;
}
