#include <iostream>
#include <numeric>
#include <vector>
#define test(a, b)                                                             \
  { std::cout << a << " " << b << ": " << (a == b) << std::endl; }

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> d(n, std::vector<int>(3));
  for (int i = 0; i < n; i++)
    std::cin >> d[i][0] >> d[i][1] >> d[i][2];
  int out = 0;
  for (auto i : d) {
    int sum = 0;
    for (int j : i)
      sum += j;
    if (sum >= 2)
      out++;
  }
  std::cout << out << std::endl;
  return 0;
}
