#include <stdio.h>
int main() {
  int i = 0;
  char B[88];
  while (i++ < 100)
    // sprintf copies formatting into character array and returns the number of
    // characters. note that `true` is the same as `!= 0`, that's why we can use
    // all of these here.
    // colon can be used to concatenate statements into one.
    !sprintf(B, "%s%s", i % 3 ? "" : "Fizz", i % 5 ? "" : "Buzz")
        ? sprintf(B, "%d", i)
        : 0,
        printf("%s\n", B);
  return 0;
}
