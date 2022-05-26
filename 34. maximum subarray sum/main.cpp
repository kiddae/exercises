#include <iostream>
#include <vector>
#define test(out, expect)                                                      \
  { std::cout << (out == expect) << std::endl; }

int maxSequence(const std::vector<int> &arr) {
  int max = 0;
  int a, b, s;
  for (s = 1; s <= arr.size(); s++) {
    for (a = 0; a <= arr.size() - s; a++) {
      b = a + s;
      int sum = 0;
      for (int i = a; i < b; i++)
        sum += arr[i];
      if (sum > max)
        max = sum;
    }
  }
  return max;
}

int main() {
  test(maxSequence({}), 0);
  test(maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4}), 6);
  test(maxSequence({1, 2, 3, 4}), 10);
  return 0;
}
