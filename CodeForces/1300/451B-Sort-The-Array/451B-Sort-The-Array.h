#ifndef C_451B_SORT_THE_ARRAY_H
#define C_451B_SORT_THE_ARRAY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Answer {
  char canBeSorted[4];
  int startIndex;
  int endIndex;
};
struct Answer canBeSorted(int *array, int arrayLength);
#endif // C_451B_SORT_THE_ARRAY_H