#include <iostream>
#include <utility>
#include <vector>

unsigned int number(const std::vector<std::pair<int, int>> &busStops) {
  int n = 0;
  for (std::pair<int, int> i : busStops) {
    n += i.first;
    n -= i.second;
  }
  return n;
  // your code here
}

int main() {
  ;
  return 0;
}
