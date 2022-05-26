#include <iostream>
#include <vector>

long sumTwoSmallestNumbers(std::vector<int> numbers) {
  long min1 = INT64_MAX;
  long min2 = INT64_MAX;
  for (int i : numbers) {
    if (i < min1) {
      min2 = min1;
      min1 = i;
    } else if (i < min2)
      min2 = i;
  }
  return min1 + min2;
}

int main() {
  long expected = 3453455;
  long actual = sumTwoSmallestNumbers({10, 343445353, 3453445, 3453545353453});
  std::cout << (expected == actual) << std::endl;
  return 0;
}
