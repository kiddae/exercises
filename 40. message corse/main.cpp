#include <iostream>
#include <vector>
#define test(a, b)                                                             \
  { std::cout << a << " " << b << ": " << (a == b) << std::endl; }

int main() {
  int p;
  std::cin >> p;
  std::vector<int> nombres(p);
  for (int i = 0; i < p; i++)
    std::cin >> nombres[i];

  int c = 0;
  for (int i = 0; i < p; i++) {
    if (nombres[i] == 10)
      c++;
    else if (nombres[i] == nombres[i - 1] && i >= 1)
      c++;
    else if (nombres[i] + nombres[i - 1] == 10 && i >= 1)
      c++;
    else if (nombres[i] == nombres[i - 2] && i >= 2)
      c++;
    else if (nombres[i] + nombres[i - 2] == 10 && i >= 2)
      c++;
  }
  std::cout << c << std::endl;

  return 0;
}
