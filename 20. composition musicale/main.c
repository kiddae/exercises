#include <stdio.h>
#include <stdlib.h>

int shiftDuplicates(char[]);

int main(int argc, char **argv) {
  char melodie[501];
  scanf("%500s", melodie);
  while (shiftDuplicates(melodie) != 0) {
    ;
  }
  printf("%s", melodie);
  return 0;
}

int shiftDuplicates(char melodie[]) {
  // returns if changes have been made (1 or 0).
  int f = 0;
  for (int i = 0; melodie[i + 1] != '\0'; i++) {
    if (melodie[i] == melodie[i + 1]) {
      f = 1;
      // shift elements to the left.
      int j;
      for (j = 0; melodie[i + j + 2] != '\0'; j++) {
        melodie[i + j] = melodie[i + 2 + j];
      }
      // end the string at the right place.
      melodie[i + j] = '\0';
    }
  }
  return f;
}
