#include <criterion/criterion.h>
#include "../src/split_string.h"


#define CSV_LINE "the;quick;brown;fox;jumps;over;the;lazy;dog"
#define TOKENS_NB 9

Test(tests_split_string, test_tokens_nb) {
  uint16_t tok_nb = tokens_nb(CSV_LINE, ';');
  cr_expect(tok_nb == TOKENS_NB, "Tokens nb should be equal to 9");
}


Test(tests_split_string, test_splits) {
  const char *str = "foo bar";
  char **split = new_split(str, ' ');
  cr_expect(strcmp(split[0], "foo") == 0);
  cr_expect(strcmp(split[1], "bar") == 0);
  free_split(split, tokens_nb(str, ' '));
}


Test(tests_split_string, test_empty_fields) {
  const char *str = ",some,empty,fields,";
  char **split = new_split(str, ',');
  cr_expect(strcmp(split[0], "") == 0);
  cr_expect(strcmp(split[4], "") == 0);
  free_split(split, tokens_nb(str, ','));
}
