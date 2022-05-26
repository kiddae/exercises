#include <cmath>
#include <iomanip>
#include <iostream>
#define test(a, b)                                                             \
  { std::cout << (a == b) << std::endl; }

class Magnets {
public:
  static double doubles(int maxk, int maxn);
  static double v(int k, int n);
  static double u(int k, int n);
};

double Magnets::doubles(int maxk, int maxn) {
  double sum = 0;
  for (int k = 1; k <= maxk; k++)
    for (int n = 1; n <= maxn; n++)
      sum += 1.0f / (k * pow(n + 1, 2 * k));
  return sum;
}

/* double Magnets::u(int k, int maxn) { */
/*   double sum = 0; */
/*   for (int j = 1; j <= maxn; j++) { */
/*     sum += v(k, j); */
/*   } */
/*   return sum; */
/* } */

/* double Magnets::v(int k, int n) { return 1.0f / (k * pow(n + 1, 2 * k)); } */

bool assertFuzzyEquals(double act, double exp) {
  bool inrange = std::abs(act - exp) <= 1e-6;
  if (inrange == false) {
    std::cout << std::setprecision(6);
    std::cout << "At 1e-6: Expected should be " << exp << ", but got " << act
              << std::endl;
  }
  return inrange;
}

int main() {
  test(Magnets::doubles(1, 10), 0.5580321939764581);
  test(Magnets::doubles(10, 1000), 0.6921486500921933);
  test(Magnets::doubles(10, 10000), 0.6930471674194457);
  test(Magnets::doubles(20, 10000), 0.6930471955575918);
  return 0;
}
