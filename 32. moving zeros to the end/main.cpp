#include <iostream>
#include <vector>

std::vector<int> move_zeroes(const std::vector<int> &input) {
  std::vector<int> out;
  int n_zeroes = 0;
  for (int i : input) {
    if (i != 0)
      out.push_back(i);
    else
      n_zeroes++;
  }
  for (int i = 0; i < n_zeroes; i++)
    out.push_back(0);
  return out;
}

int main() {
  std::cout << (move_zeroes(std::vector<int>{1, 2, 0, 1, 0, 1, 0, 3, 0, 1}) ==
                std::vector<int>{1, 2, 1, 1, 3, 1, 0, 0, 0, 0})
            << std::endl;
  std::cout << (move_zeroes(std::vector<int>{0, 0, 0, 0, 0, 0}) ==
                std::vector<int>{0, 0, 0, 0, 0, 0})
            << std::endl;
  std::cout << (move_zeroes(std::vector<int>{1, 2, 5, 1, 5, 1, 5, 3, 2, 1}) ==
                std::vector<int>{1, 2, 5, 1, 5, 1, 5, 3, 2, 1})
            << std::endl;
  return 0;
}
