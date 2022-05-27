#include <iostream>
#include <string>
#define test(a, b)                                                             \
  { std::cout << a << " " << b << ": " << (a == b) << std::endl; }

class PrimeDecomp {
public:
  static std::string factors(int lst);

private:
  static bool isPrime(int n);
};

bool PrimeDecomp::isPrime(int n) {
  for (long i = 2; i * i <= n; i++)
    if (n % i == 0)
      return false;
  return n <= 1 ? false : true;
}

std::string PrimeDecomp::factors(int lst) {
  if (isPrime(lst))
    return "(" + std::to_string(lst) + ")";
  std::string out;
  for (int i = 2; lst > 1; i++) {
    int e;
    e = 0;
    while (lst % i == 0) {
      lst /= i;
      e++;
    }
    if (e > 0) {
      out += "(" + std::to_string(i);
      if (e > 1)
        out += "**" + std::to_string(e);
      out += ")";
    }
  }
  return out;
}

int main() {
  test(PrimeDecomp::factors(86240), "(2**5)(5)(7**2)(11)");
  test(PrimeDecomp::factors(7775460), "(2**2)(3**3)(5)(7)(11**2)(17)");
  test(PrimeDecomp::factors(7919), "(7919)");
  std::cout << PrimeDecomp::factors(INT32_MAX) << std::endl;
  /* int n; */
  /* std::cin >> n; */
  /* std::cout << PrimeDecomp::factors(n) << std::endl; */
  return 0;
}
