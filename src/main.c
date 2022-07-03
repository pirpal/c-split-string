#include "split_string.h"


#define TEST_STR "the,quick,brown,fox,jumps,over,the,lazy,dog"
#define SEP ','

int main (void)
{
  printf("C split_string function\n\n");

  printf("String to split:\n'%s'\n", TEST_STR);
  printf("Separator is '%c'\n", SEP);
  

  char **split = new_split(TEST_STR, SEP);

  log_split(stdout, split);

  free_split(split);
  
  return EXIT_SUCCESS;
}
