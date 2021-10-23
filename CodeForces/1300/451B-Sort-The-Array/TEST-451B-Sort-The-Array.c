#include "../../../minunit.h"
#include "451B-Sort-The-Array.h"
#include "stdio.h"

int tests_run = 0;

static char *test_one() {
  int array[] = {3, 2, 1};
  int indexOutOfPlace[3];
  struct Answer answer = canBeSorted(array, indexOutOfPlace, 3);
  mu_assert("1: answer.canBeSorted", strcmp(answer.canBeSorted, "yes") == 0);
  mu_assert("1: error, answer.startIndex != 1", answer.startIndex == 1);
  mu_assert("1: error, answer.endIndex != 3", answer.endIndex == 3);
  return 0;
}

static char *test_two() {
  int array[] = {2, 1, 3, 4};
  int indexOutOfPlace[4] = {0};
  struct Answer answer = canBeSorted(array, indexOutOfPlace, 4);
  mu_assert("2: answer.canBeSorted", strcmp(answer.canBeSorted, "yes") == 0);
  mu_assert("2: error, answer.startIndex != 1", answer.startIndex == 1);
  mu_assert("2: error, answer.endIndex != 2", answer.endIndex == 2);
  return 0;
}

static char *test_three() {
  int array[] = {3, 1, 2, 4};
  int indexOutOfPlace[4];
  struct Answer answer = canBeSorted(array, indexOutOfPlace, 4);
  mu_assert("answer.canBeSorted", strcmp(answer.canBeSorted, "no") == 0);
  return 0;
}

static char *test_four() {
  int array[] = {1, 1};
  int indexOutOfPlace[2];
  struct Answer answer = canBeSorted(array, indexOutOfPlace, 2);
  mu_assert("answer.canBeSorted != yes",
            strcmp(answer.canBeSorted, "yes") == 0);
  mu_assert("error, answer.startIndex != 1", answer.startIndex == 1);
  mu_assert("error, answer.endIndex != 2", answer.endIndex == 1);
  return 0;
}
static char *test_five() {
  int array[] = {6, 78, 63, 59, 28, 24, 8, 96, 99};
  int indexOutOfPlace[9];
  struct Answer answer = canBeSorted(array, indexOutOfPlace, 9);
  mu_assert("answer.canBeSorted != yes",
            strcmp(answer.canBeSorted, "yes") == 0);
  mu_assert("error, answer.startIndex != 2", answer.startIndex == 2);
  mu_assert("error, answer.endIndex != 7", answer.endIndex == 7);
  return 0;
}

static char *test_70() {
  int array[] = {1, 5, 3, 4, 2, 6};
  int indexOutOfPlace[6];
  struct Answer answer = canBeSorted(array, indexOutOfPlace, 6);
  mu_assert("70: answer.canBeSorted != no",
            strcmp(answer.canBeSorted, "no") == 0);
  return 0;
}

static char *all_tests() {
  mu_run_test(test_one);
  mu_run_test(test_two);
  mu_run_test(test_three);
  mu_run_test(test_four);
  mu_run_test(test_five);
  mu_run_test(test_70);
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