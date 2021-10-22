#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
  int int_a = *((int *)a);
  int int_b = *((int *)b);

  if (int_a == int_b)
    return 0;
  else if (int_a < int_b)
    return -1;
  else
    return 1;
}

double getDistance(int size, int *lanterns, int end) {

  // first lantern has to cover start of the street
  int distance = lanterns[0] * 2;

  for (int i = 0; i < (size - 1); i++) {
    int currentDistance = abs(lanterns[i] - lanterns[i + 1]);
    distance = currentDistance > distance ? currentDistance : distance;
  }

  // last lantern has to cover end of the street
  int endDistance = (end - lanterns[size - 1]) * 2;

  distance = endDistance > distance ? endDistance : distance;

  return distance / 2.0;
}

int main() {

  int noLanterns;
  int streetLength;

  scanf("%d", &noLanterns);
  scanf("%d", &streetLength);
  int lanterns[noLanterns];
  int tempLantern;
  for (int i = 0; i < noLanterns; i++) {

    scanf("%d", &tempLantern);
    lanterns[i] = tempLantern;
  }

  qsort(lanterns, noLanterns, sizeof(int), compare);

  double answer = getDistance(noLanterns, lanterns, streetLength);
  printf("%.1f", answer);
  return 0;
}