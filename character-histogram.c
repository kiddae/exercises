#include <stdio.h>

int main() {
  int c, count, total;
  float freq;
  int chars[256];
  count = 0;
  total = 0;
  for (int i = 0; i < 256; i++)
    chars[i] = 0;
  while ((c = getchar()) != EOF) {
    ++chars[c];
  }
  for (int i = 0; i < 256; i++) {
    if (chars[i] != 0)
      count += chars[i];
  }
  // printf("%d\n", count);
  for (int i = 0; i < 256; i++) {
    if (chars[i] != 0) {
      printf("%c: ", i);
      freq = (float)chars[i] / count;
      for (int j = 0; j < 30; ++j) {
        if (j <= (int)(freq * 30))
          printf("#");
        else
          printf(".");
      }
      printf("(%.2f%%)\n", freq * 100);
    }
  }
}
