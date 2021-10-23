#include <stdio.h>
#include <stdlib.h>

struct Answer {
  char canBeSorted[4];
  int startIndex;
  int endIndex;
};

struct Answer canBeSorted(int *array, int *indexOutOfPlace, int arraySize) {

  int outOfPlaceCounter = 0;
  struct Answer cannotBeSorted = {"no", 0, 0};

  for (int i = 1; i < arraySize; i++) {
    if (array[i] < array[i - 1]) {
      if (outOfPlaceCounter == 0) {
        indexOutOfPlace[outOfPlaceCounter] = i - 1;
        outOfPlaceCounter++;
      }

      indexOutOfPlace[outOfPlaceCounter] = i;
      outOfPlaceCounter++;
    }
  }

  // the array is already sorted
  if (outOfPlaceCounter == 0) {
    struct Answer isAlreadySorted = {"yes", 1, 1};
    return isAlreadySorted;
  }

  // check if it is more than one segment
  for (int i = 1; i < outOfPlaceCounter; i++) {
    if (indexOutOfPlace[i - 1] + 1 != indexOutOfPlace[i]) {
      return cannotBeSorted;
    }
  }

  int outOfPlaceLength = outOfPlaceCounter - 1;
  int lastIndex = indexOutOfPlace[outOfPlaceLength];
  outOfPlaceCounter = 0;
  int prev = 0;
  int isSorted = 1;

  for (int i = 0; i < arraySize; i++) {
    int current;
    if (i == indexOutOfPlace[outOfPlaceCounter]) {
      current = array[indexOutOfPlace[outOfPlaceLength - outOfPlaceCounter]];
      outOfPlaceCounter++;
    } else {
      current = array[i];
    }

    if (current < prev) {
      isSorted = 0;
      break;
    }
    prev = current;
  }

  if (isSorted) {
    struct Answer canBeSorted = {"yes", indexOutOfPlace[0] + 1, lastIndex + 1};
    return canBeSorted;
  }
  return cannotBeSorted;
}

int main() {
  int arraySize;
  scanf("%d", &arraySize);
  int *p_array = (int *)malloc(sizeof(int) * arraySize);
  int *indexOutOfPlace = (int *)malloc(sizeof(int) * arraySize);
  int temp;
  for (int i = 0; i < arraySize; i++) {
    scanf("%d", &temp);
    p_array[i] = temp;
  }
  struct Answer answer = canBeSorted(p_array, indexOutOfPlace, arraySize);

  printf("%s", answer.canBeSorted);
  if (answer.startIndex != 0) {
    printf("\n%d %d", answer.startIndex, answer.endIndex);
  }
  free(p_array);
  free(indexOutOfPlace);
  return 0;
}