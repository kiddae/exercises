#include <iostream>
#define test(a, b)                                                             \
  { std::cout << a << " " << b << ": " << (a == b) << std::endl; }

int main() {
  int in;
  std::cin >> in;
  for (int i = 2; i < in; i += 2) {
    if ((in - i) % 2 == 0) {
      std::cout << "YES";
      return 0;
    }
  }
  std::cout << "NO";

  return 0;
}
