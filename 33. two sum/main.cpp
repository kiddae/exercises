#include <iostream>
#include <utility>
#include <vector>

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int> &numbers,
                                            int target) {
  for (int i = 0; i < numbers.size(); i++) {
    for (int j = 0; j < numbers.size(); j++) {
      if (i != j && numbers[i] + numbers[j] == target)
        return {i, j};
    }
  }
}

void test(const std::vector<int> &numbers, int target,
          std::pair<std::size_t, std::size_t> expected) {
  std::pair<std::size_t, std::size_t> output = two_sum(numbers, target);
  std::cout << output.first << "," << output.second << std::endl;
  std::cout << (two_sum(numbers, target) == expected ? "true" : "false")
            << std::endl;
}

int main() {
  test({1, 2, 3}, 4, {0, 2});
  test({1234, 5678, 9012}, 14690, {1, 2});
  test({1, 2, 3}, 4, {0, 2});
  return 0;
}
