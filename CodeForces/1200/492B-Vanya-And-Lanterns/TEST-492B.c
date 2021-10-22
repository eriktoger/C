/* file minunit_example.c */

#include "../../../minunit.h"
#include "492B-Vanya-And-Lanterns.h"
#include <stdio.h>

int tests_run = 0;

int foo = 7;
int bar = 4;

static char *test_one() {
  int lanters[] = {15, 5, 3, 7, 9, 14, 0};
  qsort(lanters, 7, sizeof(int), compare);
  double answer = getDistance(7, lanters, 15);
  mu_assert("error, answer != 2.5", answer == 2.5);
  return 0;
}

static char *test_two() {
  int lanters[] = {2, 5};
  qsort(lanters, 2, sizeof(int), compare);
  double answer = getxDistance(2, lanters, 5);
  mu_assert("error, answer != 2.0", answer == 2.0);
  return 0;
}

static char *all_tests() {
  mu_run_test(test_one);
  mu_run_test(test_bar);
  return 0;
}

int main(int argc, char **argv) {
  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  } else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}