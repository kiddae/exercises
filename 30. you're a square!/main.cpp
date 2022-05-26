#include <iostream>

bool is_square(int n) {
  if (n < 0)
    return false;
  int i;
  for (i = 0; i * i < n; i++)
    ;
  return (i * i == n);
}

int main() {
  std::cout << (is_square(-1) == false) << std::endl;
  std::cout << (is_square(0) == true) << std::endl;
  std::cout << (is_square(3) == false) << std::endl;
  std::cout << (is_square(4) == true) << std::endl;
  std::cout << (is_square(25) == true) << std::endl;
  std::cout << (is_square(26) == false) << std::endl;
  return 0;
}
