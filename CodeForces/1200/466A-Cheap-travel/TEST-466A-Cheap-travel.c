#include "../../../minunit.h"
#include "466A-Cheap-travel.h"
#include "stdio.h"

int tests_run = 0;

static char *test_one() {
  int cost = travelCost(6, 2, 1, 2);
  mu_assert("error, answer != 6", cost == 6);
  return 0;
}

static char *test_two() {
  int cost = travelCost(5, 2, 2, 3);
  mu_assert("error, answer != 8", cost == 8);
  return 0;
}

static char *all_tests() {
  mu_run_test(test_one);
  mu_run_test(test_two);
  return 0;
}
int main(int argc, char **argv) {
  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  } else {
    printf("ALL TESTS PASSED\n ");
  }
  printf("Tests run: %d\n", tests_run);
  return result != 0;
}