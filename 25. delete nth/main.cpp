#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> deleteNth(std::vector<int> arr, int n) {
  std::unordered_map<int, int> occurences;
  std::vector<int> out;
  // no need to init, maps member are init to 0 by default.
  for (int i : arr) {
    if (++occurences[i] <= n) {
      out.push_back(i);
    }
  }
  return out;
}

int main() {
  std::vector<int> yea = deleteNth({20, 37, 20, 21}, 1);
  for (int i : yea)
    std::cout << i << " ";
  return 0;
}
