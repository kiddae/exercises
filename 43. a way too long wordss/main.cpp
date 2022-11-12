#include <iostream>
#include <string>
#include <vector>
#define test(a, b)                                                             \
  { std::cout << a << " " << b << ": " << (a == b) << std::endl; }

int main() {
  int n;
  std::cin >> n;
  std::vector<std::string> in(n);
  for (int i = 0; i < n; i++)
    std::cin >> in[i];
  for (auto i : in) {
    if (i.length() <= 10) {
      std::cout << i << std::endl;
      continue;
    }
    std::string s;
    int count = 0;
    for (int j = 1; j < i.length() - 1; j++)
      count++;
    s += i[0];
    s += std::to_string(count);
    s += i[i.length() - 1];
    std::cout << s << std::endl;
  }
  return 0;
}
