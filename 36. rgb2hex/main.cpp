#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#define test(a, b)                                                             \
  { std::cout << a << " " << b << ": " << (a == b) << std::endl; }

class RGBToHex {
public:
  static std::string rgb(int r, int g, int b);

private:
  static std::string dec2hex(int n);
};

/* std::string RGBToHex::rgb(int r, int g, int b) { */
/*   std::string hexr = dec2hex(r); */
/*   std::string hexg = dec2hex(g); */
/*   std::string hexb = dec2hex(b); */
/*   return hexr + hexg + hexb; */
/* } */

std::string RGBToHex::rgb(int r, int g, int b) {
  std::ostringstream oss;
  oss << std::uppercase << std::setfill('0') << std::hex << std::setw(2)
      << std::clamp(r, 0, 255) << std::setw(2) << std::clamp(g, 0, 255)
      << std::setw(2) << std::clamp(b, 0, 255);
  return oss.str();
}

std::string RGBToHex::dec2hex(int n) {
  n = std::clamp(n, 0, 255);
  int rem = n % 16;
  int div = (n - rem) / 16;
  std::map<int, std::string> m;
  for (int i = 0; i <= 9; i++) {
    m[i] = std::to_string(i);
    m[i + 10] = std::string(1, 'A' + i);
  }
  return m[div] + m[rem];
}

int main() {
  test(RGBToHex::rgb(0, 0, 0), "000000");
  test(RGBToHex::rgb(1, 2, 3), "010203");
  test(RGBToHex::rgb(255, 255, 255), "FFFFFF");
  test(RGBToHex::rgb(254, 253, 252), "FEFDFC");
  test(RGBToHex::rgb(-20, 275, 125), "00FF7D");
  return 0;
}
